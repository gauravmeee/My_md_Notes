
```python
import requests

import json

from datetime import datetime

  
  

def getCodeforcesContests():

    response = requests.get("https://codeforces.com/api/contest.list")

    codeforcesContests = []

    if response.status_code == 200:

        jsonResponse = json.loads(response.text)

        contests = jsonResponse["result"]

        for contest in contests:

            if contest["phase"] == "BEFORE":

                codeforcesContest = {}

                codeforcesContest["platform"] = "CodeForces"

                codeforcesContest["contestName"] = contest["name"]

                codeforcesContest["contestLink"] = "https://codeforces.com/contests/" + str(contest["id"])

                codeforcesContest["startTime"] = datetime.strftime(datetime.fromtimestamp(contest["startTimeSeconds"]), '%Y-%m-%dT%H:%M:%S') + '+0530'

                codeforcesContest["contestDuration"] = f"{int(contest['durationSeconds']) // 3600:02d}:{int((contest['durationSeconds']) % 3600) // 60:02d} hours"

                codeforcesContests.append(codeforcesContest)

    return codeforcesContests

print(getCodeforcesContests())
```

---
I see the issue now. Your code is using `datetime.fromtimestamp()` which interprets the timestamp according to the local timezone of the machine it's running on. This explains why you're getting different results when deployed on Render compared to your local machine.

Here's how to fix it:

```python
import requests
import json
from datetime import datetime
import pytz

def getCodeforcesContests():
    response = requests.get("https://codeforces.com/api/contest.list")
    codeforcesContests = []
    if response.status_code == 200:
        jsonResponse = json.loads(response.text)
        contests = jsonResponse["result"]
        for contest in contests:
            if contest["phase"] == "BEFORE":
                codeforcesContest = {}
                codeforcesContest["platform"] = "CodeForces"
                codeforcesContest["contestName"] = contest["name"]
                codeforcesContest["contestLink"] = "https://codeforces.com/contests/" + str(contest["id"])
                
                # Create datetime from UTC timestamp and convert to IST
                utc_time = datetime.fromtimestamp(contest["startTimeSeconds"], tz=pytz.UTC)
                ist_time = utc_time.astimezone(pytz.timezone('Asia/Kolkata'))
                codeforcesContest["startTime"] = ist_time.strftime('%Y-%m-%dT%H:%M:%S') + '+0530'
                
                codeforcesContest["contestDuration"] = f"{int(contest['durationSeconds']) // 3600:02d}:{int((contest['durationSeconds']) % 3600) // 60:02d} hours"
                codeforcesContests.append(codeforcesContest)
    return codeforcesContests
```

The key changes are:

1. Added the `pytz` library to handle timezones properly
2. Used `datetime.fromtimestamp(timestamp, tz=pytz.UTC)` to explicitly interpret the timestamp as UTC
3. Converted that UTC time to IST (Asia/Kolkata) before formatting

This ensures that no matter where your code runs (locally or on Render), it will always interpret the timestamps consistently and convert them to IST properly.


---

Let me break this code down line by line to explain what's happening:

1. **Creating a UTC datetime from the timestamp**:
    
    ```python
    utc_time = datetime.fromtimestamp(contest["startTimeSeconds"], tz=pytz.UTC)
    ```
    
    - `contest["startTimeSeconds"]` is a Unix timestamp (seconds since Jan 1, 1970 UTC)
    - `datetime.fromtimestamp()` converts this number to a datetime object
    - The `tz=pytz.UTC` parameter explicitly tells Python to interpret this timestamp in UTC timezone
    - Without this parameter, Python would use your local machine's timezone, which causes inconsistency when deployed
2. **Converting from UTC to IST (Indian Standard Time)**:
    
    ```python
    ist_time = utc_time.astimezone(pytz.timezone('Asia/Kolkata'))
    ```
    
    - `astimezone()` converts the datetime from one timezone to another
    - `pytz.timezone('Asia/Kolkata')` specifies the IST timezone (UTC+5:30)
    - This ensures the time is correctly shown in Indian time
3. **Formatting the datetime as a string with the IST timezone indicator**:
    
    ```python
    codeforcesContest["startTime"] = ist_time.strftime('%Y-%m-%dT%H:%M:%S') + '+0530'
    ```
    
    - `strftime()` formats the datetime according to the specified format
    - `%Y-%m-%dT%H:%M:%S` formats it as "YYYY-MM-DDTHH:MM:SS" (ISO 8601 format)
    - `+0530` is manually added to indicate this is IST (UTC+5:30)

This approach ensures consistency because:

1. It always interprets the timestamp in UTC first (independent of where the code runs)
2. It explicitly converts to IST
3. It includes the timezone offset in the final string

The issue with your original code was that `datetime.fromtimestamp()` without a timezone parameter uses the local system timezone, so it would give different results on your local machine (likely set to IST) versus on Render (likely set to UTC or another timezone).