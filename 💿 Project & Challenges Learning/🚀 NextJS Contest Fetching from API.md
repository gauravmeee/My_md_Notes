

## Client-Side Rendering (CSR)

- You're using `"use client"` directive and `useEffect` to fetch data on the client side
- The data loading happens in the browser after the page loads
- This is why you see the loading state for a while

#### `apps/contests/page.js`
```jsx
"use client";  // This makes this a Client Component (needed for using state and effects in Next.js)

// Import React hooks for state and side effects
import { useEffect, useState } from "react";  
```
- `Contests()`
```jsx
const Contests = () => {
  // State to store contests data
  const [contests, setContests] = useState([]);
  // State to track loading state
  const [loading, setLoading] = useState(true);
  // State to store any error message
  const [error, setError] = useState(null);

  // API endpoint from where contest data will be fetched
  const apiUrl = 'https://flask-contest-api.onrender.com/';  

  // Fetch contests data when the component mounts
  useEffect(() => {
    const fetchContests = async () => {
      try {
        // Fetch data from the API
        const response = await fetch(apiUrl);
        const data = await response.json();

        // Check if the response contains valid contest data
        if (data.contests && data.contests.length > 0) {
	      // Update state with contest data
          setContests(data.contests);  
        } else {
        // Set an error message if no contests are found
          setError("No contests available at the moment.");  
        }
      } catch (err) {
      // Log the error for debugging
        console.error("Error fetching contests:", err);  
        // Set an error message
        setError("Failed to load contests. Please try again later.");  
      } finally {
      // Stop loading once data fetching is complete (whether success or failure)
        setLoading(false);  
      }
    };
	// Empty dependency array means this runs only once when the component mounts
    fetchContests();
  }, []);  
```
- Error Handling
```jsx
  // Show a loading spinner while data is being fetched
  if (loading) {
    return (
      <div className="flex flex-col justify-center items-center mt-40">
        {/* Loading animation */}
        <div className="animate-spin rounded-full h-12 w-12 border-4 border-gray-300 border-t-blue-500"></div>
        <p className="text-xl text-gray-500 mt-2 ml-5">Loading...</p>
      </div>
    );
  }

  // Show an error message if data fetching fails
  if (error) {
    return (
      <div className="flex justify-center items-center pt-40">
        <p className="text-xl text-red-500">{error}</p>
      </div>
    );
  }
```
- Return JSX
```jsx
  return (
    <div className="min-h-screen container mx-auto p-6 backdrop-blur">
      {/* Heading */}
      <h2 className="text-2xl md:text-4xl font-semibold mb-4 text-center">Contest Updates</h2>

      {/* Grid layout to display contests */}
      <div className="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 gap-6">
        {contests.map((contest) => {
          // Format contest start time into a readable format
          const formattedDate = new Date(contest.startTime).toLocaleDateString('en-GB', {
            day: '2-digit',
            weekday: 'short',
            month: 'short',
            year: 'numeric',
            hour: '2-digit',
            minute: '2-digit',
            hour12: true,
          });

          // Set platform image dynamically based on the contest platform
          const platformImage = `/assets/contests/${contest.platform}.png` || "/assets/contests/default.png";

          return (
            <div key={contest.contestName} className="bg-white dark:bg-gray-800 p-6 rounded-lg shadow-lg relative">
              {/* Faint background image of the contest platform */}
              <div
                className="absolute top-0 left-0 w-full h-full bg-contain bg-center bg-no-repeat opacity-5"
                style={{ backgroundImage: `url(${platformImage})` }}
              ></div>

              {/* Contest details */}
              <div className="relative z-10">
                {/* Contest name with clickable link */}
                <h3 className="text-xl font-semibold text-gray-600 dark:text-gray-300">
                  <a href={contest.contestLink} target="_blank" className="text-blue-500 hover:underline">
                    {contest.contestName}
                  </a>
                </h3>
                {/* Contest platform */}
                <p><strong>Platform:</strong> {contest.platform}</p>
                {/* Contest start time */}
                <p><strong>Start Time:</strong> {formattedDate}</p>
                {/* Contest duration */}
                <p><strong>Duration:</strong> {contest.contestDuration}</p>
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
};
```
- Export
```jsx
export default Contests;  // Export the Contests component
```

---

## **Update 1** : Server-Side Rendering (SSR) ✅

This would be ideal for your use case since contest data changes regularly and you want SEO benefits:

✅ Converted to **async server component**  
✅ Added **revalidation** for caching  
✅ Removed **client-side hooks (`useEffect`, `useState`)**  
✅ Improved **performance** by fetching contests before rendering  
✅ Added **comments for better readability**

1. **Converted the Component to an Async Server Component:**
    - Previously, `Contests` was a client component using `useEffect` to fetch data.
    - Now, `ContestsPage` is an **async server component**, fetching contests directly on the server side before rendering the page.

2. **Revalidation for Data Fetching:**
    - Added `{ next: { revalidate: 3600 } }` to fetch options.
    - This ensures the data is **cached and refreshed every hour** instead of fetching on every request.

3. **Removed `useEffect` and `useState`:**
    - Since the data is fetched before rendering, there’s no need for `useEffect` or `useState`.


#### `apps/contests/page.js`
```jsx
// Function to fetch contests from the API
async function getContests() {
  try {
    // Fetch data from the API with revalidation set to 1 hour (3600 seconds)
    const response = await fetch('https://flask-contest-api.onrender.com/', { 
      next: { revalidate: 3600 } // Ensures data is updated every hour
    });

    // Convert the response to JSON format
    const data = await response.json();

    // Return contests array, if available, else return an empty array
    return data.contests || [];
  } catch (error) {
    // Log error if fetching fails and return an empty list
    console.error("Failed to fetch contests:", error);
    return [];
  }
}
```

```jsx
// Server component to display contests
export default async function ContestsPage() {
  // Fetch contests before rendering the page
  const contests = await getContests();
  
  // If no contests are available, show a message
  if (!contests.length) {
    return (
      <div className="flex justify-center items-center pt-40">
        <p className="text-xl text-red-500">No contests available at the moment.</p>
      </div>
    );
  }
```

```jsx
  return (
    ...
  );
};
```





---

With local cache and upstash cache
local redis cache
```python
import redis

import json

from platforms import atcoder, codechef, codeforces, hackerearth, hackerrank, geeksforgeeks

  

# Connect to Redis

redis_client = redis.StrictRedis(host="localhost", port=6379, decode_responses=True)

  

def fetchContests():

    cached_data = redis_client.get("contests_data")

    if cached_data:

        return json.loads(cached_data)  # Return cached results if available

  

    # Fetch new contest data if cache is empty

    contests = []

    contests.extend(codeforces.getCodeforcesContests())

    contests.extend(codechef.getCodechefContests())

    contests.extend(hackerrank.getHackerrankContests())

    contests.extend(hackerearth.getHackerearthContests())

    contests.extend(geeksforgeeks.getGeeksforgeeksContests())

    contests.extend(atcoder.getAtCoderContests())

  

    contests = sorted(contests, key=lambda contest: contest['startTime'])

    result = {"contests": contests}

  

    # Store in Redis for 30 minutes (1800 seconds)

    redis_client.setex("contests_data", 1800, json.dumps(result))

  

    return result
```

upstash cloud redis cache
```python
# Cloud Cache Upstash-Redis

import redis

import json

import os

from platforms import atcoder, codechef, codeforces, hackerearth, hackerrank, geeksforgeeks

  
  

redis_host = "gorgeous-rodent-12506.upstash.io"  # Set this in your Vercel environment variables

redis_port = 6379

redis_password = "ATDaAAIjcDEzNzEyOTQxM2M0ZmQ0NmI2OGZkZTk0OTk4OWY4Mzg5NXAxMA"

  

redis_client = redis.StrictRedis(

    host=redis_host,

    port=redis_port,

    password=redis_password,

    decode_responses=True,

    socket_timeout=10,  # Timeout in seconds

    ssl=True  # Enable SSL

)

  

def fetchContests():

    cached_data = redis_client.get("contests_data")

    if cached_data:

        return json.loads(cached_data)  # Return cached results if available

  

    # Fetch new contest data if cache is empty

    contests = []

    contests.extend(codeforces.getCodeforcesContests())

    contests.extend(codechef.getCodechefContests())

    contests.extend(hackerrank.getHackerrankContests())

    contests.extend(hackerearth.getHackerearthContests())

    contests.extend(geeksforgeeks.getGeeksforgeeksContests())

    contests.extend(atcoder.getAtCoderContests())

  

    contests = sorted(contests, key=lambda contest: contest['startTime'])

    result = {"contests": contests}

  

    # Store in Redis for 30 minutes (1800 seconds)

    redis_client.setex("contests_data", 604800, json.dumps(result)) # 604800 seconds -> 1 week cache

  

    return result
```