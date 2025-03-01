
## Flask API to Fetch Contest From Different Sources

#### `contest_scrap.py`
```python
# Import required libraries
import json  # To handle JSON data
from platforms import atcoder, codechef, codeforces, hackerearth, hackerrank, geeksforgeeks  # Import platform-specific contest fetchers
```
- `fetchContests()`
```python
def fetchContests():
    """
    Fetches upcoming programming contests from multiple platforms.
    """
    # Fetch contests from various platforms
    contests = []  # Initialize an empty list to store contest data
    contests.extend(codeforces.getCodeforcesContests())  # Fetch contests from Codeforces
    contests.extend(codechef.getCodechefContests())  # Fetch contests from CodeChef
    contests.extend(hackerrank.getHackerrankContests())  # Fetch contests from HackerRank
    contests.extend(hackerearth.getHackerearthContests())  # Fetch contests from HackerEarth
    contests.extend(geeksforgeeks.getGeeksforgeeksContests())  # Fetch contests from GeeksforGeeks
    contests.extend(atcoder.getAtCoderContests())  # Fetch contests from AtCoder

    # Sort contests by start time
    contests = sorted(contests, key=lambda contest: contest['startTime'])

    # Create the final result dictionary
    result = {"contests": contests}

    return result  # Return the fetched contest data
```

#### `app.py`
```python
from flask import Flask, render_template
from flask_restful import Api, Resource
from flask_cors import CORS  # Import CORS
import contest_scrap

app = Flask(__name__)
CORS(app)
api = Api(app)

# Define API resource for fetching contest data
class cpAPI(Resource):
    @staticmethod
    def get():
        return contest_scrap.fetchContests() # Call scrap function to get latest contest data

# Add API resource to Flask app with endpoint '/'
api.add_resource(cpAPI, "/") # Whenever a request is made to '/', call the cpAPI class. The get() method inside cpAPI will handle GET requests.

if __name__ == "__main__":
    # app.run(host="0.0.0.0", port=5000) # Uncomment this to run on all network interfaces
    app.run(debug=True) # Run in debug mode (auto-restarts on code changes)
```
---

## **Update 1:** Added Redis Cloud Cache ✅ on `upstash.com`

#### `contest_scrap.py`
```python
# Import required libraries
import redis  # Redis client for Python
import json  # To handle JSON data
import os  # To access environment variables
from platforms import atcoder, codechef, codeforces, hackerearth, hackerrank, geeksforgeeks  # Import platform-specific contest fetchers
from dotenv import load_dotenv  # Load environment variables from a .env file

# Load environment variables from .env file
load_dotenv()
```
- Redis Setup
```Python
# Retrieve Redis connection details from environment variables
redis_host = os.getenv("REDIS_HOST")  # Get Redis host from environment
redis_port = int(os.getenv("REDIS_PORT", 6379))  # Get Redis port, default to 6379 if not provided
redis_password = os.getenv("REDIS_PASSWORD")  # Get Redis password from environment

# Create a Redis client instance
redis_client = redis.StrictRedis(
    host=redis_host,  # Redis server host
    port=redis_port,  # Redis server port
    password=redis_password,  # Redis authentication password
    decode_responses=True,  # Decode responses from bytes to string
    socket_timeout=10,  # Set timeout for Redis requests in seconds
    ssl=True  # Enable SSL for secure connection
)

# Uncomment the following line to clear old cached contest data
# redis_client.delete("contests_data")
```
- `fetchContests()`
```python
def fetchContests():
    """
    Fetches upcoming programming contests from multiple platforms.
    Uses Redis caching to reduce redundant API calls.
    """
    # Check if contests data is available in Redis cache
    cached_data = redis_client.get("contests_data")
    if cached_data:
        return json.loads(cached_data)  # Return cached results if available

    # If no cached data, fetch contests from various platforms
    contests = []  # Initialize an empty list to store contest data
    contests.extend(codeforces.getCodeforcesContests())  # Fetch contests from Codeforces
    contests.extend(codechef.getCodechefContests())  # Fetch contests from CodeChef
    contests.extend(hackerrank.getHackerrankContests())  # Fetch contests from HackerRank
    contests.extend(hackerearth.getHackerearthContests())  # Fetch contests from HackerEarth
    contests.extend(geeksforgeeks.getGeeksforgeeksContests())  # Fetch contests from GeeksforGeeks
    contests.extend(atcoder.getAtCoderContests())  # Fetch contests from AtCoder

    # Sort contests by start time
    contests = sorted(contests, key=lambda contest: contest['startTime'])

    # Create the final result dictionary
    result = {"contests": contests}

    # Store the result in Redis cache with an expiration time of 6 hours (6 * 60 * 60 seconds)
    redis_client.setex("contests_data", 6 * 60 * 60, json.dumps(result))

    return result  # Return the fetched contest data
```

`.env`
```sh
REDIS_HOST=gorgeous-rodent-12506.upstash.io
REDIS_PORT=6379
REDIS_PASSWORD=ATDaAAIjcDEzNzEyOTQxM2M0ZmQ0NmI2OGZkZTk0OTk4OWY4Mzg5NXAxMA
```

---