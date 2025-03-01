

> # HENNGE Backend/Global Internship Challenge
# Challenge :

## Overview
This challenge consists of 3 missions. After completing Mission 3, you'll receive a link to submit your CV and Cover Letter. We'll review your code and documents together and contact you with results within a month.

**Tip:** We recommend clearly explaining your motivation in your Cover Letter due to our competitive application process.

## Mission 1: Sum of Squares Program

### Description
Calculate the sum of squares of given integers, excluding any negatives.
- First line: integer N (1 ≤ N ≤ 100) indicating number of test cases
- For each test case:
  - Line 1: integer X (0 < X ≤ 100)
  - Line 2: X space-separated integers Yn (-100 ≤ Yn ≤ 100)
- Calculate sum of squares of integers (excluding negatives) for each test case
- Output each calculated sum

### Notes
- No output until all input is received
- No blank lines between test case solutions
- Take input from standard input, output to standard output

### Rules
- Use either Go or Python (not both)
- Only standard library packages allowed
- Extra points for solutions without global variables

#### Go Rules
- Single file solution
- No `for` or `goto` statements
- Tested against Go 1.22+ (April 2024)
- Must use package main with main function

#### Python Rules
- Single file with at least a main function
- No for/while loops or list/set/dictionary comprehensions
- Tested against Python 3.13+ (January 2025)

### Sample Input
```
2
4
3 -1 1 14
5
9 6 -53 32 16
```

### Sample Output
```
206
1397
```

## Mission 2: Publish Code as Secret Gist

### Description
- Publish your solution as a secret gist on GitHub
- Ensure it's not public
- Upload only a single file (no additional files)

## Mission 3: Send URL of Your Work

### Description
Construct a JSON string:

```json
{
  "github_url": "https://gist.github.com/YOUR_ACCOUNT/GIST_ID",
  "contact_email": "EMAIL",
  "solution_language": "golang" or "python"
}
```

Make an HTTP POST request to: `https://api.challenge.hennge.com/challenges/003`

### Requirements
- Content-Type: application/json
- Protected by HTTP Basic Authentication (RFC2617)
  - Userid: your email address
  - Password: 10-digit TOTP (RFC6238)

### TOTP Configuration
- Time Step X: 30 seconds, T0: 0
- Hash function: HMAC-SHA-512 (not default HMAC-SHA-1)
- Token shared secret: userid + "HENNGECHALLENGE003"
  - Example: if userid is "ninja@example.com", shared secret is "ninja@example.comHENNGECHALLENGE003"

### Sample Request
```
POST /challenges/003 HTTP/1.1
Authorization: Basic bmluamFAZXhhbXBsZS5jb206MTU5NTk0MjU2MA==
Host: api.challenge.hennge.com
Accept: */*
Content-Type: application/json
Content-Length: 133

{"github_url":"https://gist.github.com/hennge/b859bd12e7a7fb418141","contact_email":"ninja@example.com","solution_language":"golang"}
```

### Sample Response
```
HTTP/1.1 200 OK
Content-Type: application/json
Date: Wed, 26 Jun 2019 02:15:16 GMT
Transfer-Encoding: chunked

{"message":"Congratulations! You have achieved mission 3"}
```

## Questions?
For questions (other than about the challenge itself), contact:
- Global internship: gip@hennge.com
- Backend position: recruit-engineer@hennge.com


---
# Solution Guide :
## Mission 1: Program to Calculate Sum of Squares (Excluding Negatives)

First, let's understand the requirements:
- Need to calculate sum of squares of integers, excluding negatives
- Input starts with number of test cases, followed by test cases
- Each test case has number of integers, then those integers
- Cannot use for/while loops (Python) or for/goto statements (Go)
- Cannot use list/dict/set comprehensions in Python

Let's solve this with Python since the restrictions make it interesting:

```python
def sum_of_squares(numbers):
    # Filter out negative numbers and compute sum of squares
    filtered = filter(lambda x: x >= 0, numbers)
    squared = map(lambda x: x * x, filtered)
    return sum(squared)

def process_test_case():
    # Get number of integers in this test case
    x = int(input())
    # Get the integers themselves
    numbers = list(map(int, input().split()))
    return sum_of_squares(numbers)

def main():
    # Get number of test cases
    n = int(input())
    
    # Process each test case
    results = []
    
    # Use recursion instead of loops
    def process_remaining_cases(i, remaining_results):
        if i == 0:
            return remaining_results
        result = process_test_case()
        return process_remaining_cases(i-1, remaining_results + [result])
    
    results = process_remaining_cases(n, [])
    
    # Print all results at once
    for result in results:
        print(result)

if __name__ == "__main__":
    main()

```

The code uses:
- Recursion instead of loops
- Functional programming with `filter` and `map` instead of list comprehensions
- No global variables

## Mission 2: Publish as a Secret Gist

1. Go to [GitHub Gist](https://gist.github.com/)
2. Sign in to your GitHub account (or create one if you don't have it)
3. Create a new gist:
   - Paste your code
   - Give it a description like "HENNGE Coding Challenge Solution"
   - Make sure "Secret gist" is selected (not "Public gist")
   - Click "Create secret gist"
4. Save the URL, it should look like: `https://gist.github.com/YOUR_USERNAME/some_long_id`

## Mission 3: Send the URL via HTTP POST

This is the tricky part - you need to:
1. Create a JSON with your gist URL and email
2. Generate a TOTP password using HMAC-SHA-512
3. Make an HTTP POST request with Basic Authentication

Here's a Python script to help with Mission 3:

```python
import base64
import hmac
import json
import hashlib
import time
import requests

# Replace these with your actual information
EMAIL = "your.email@example.com"
GITHUB_GIST_URL = "https://gist.github.com/YOUR_USERNAME/your_gist_id"
SOLUTION_LANGUAGE = "python"  # or "golang" if you used Go

# Prepare JSON body
body = {
    "github_url": GITHUB_GIST_URL,
    "contact_email": EMAIL,
    "solution_language": SOLUTION_LANGUAGE
}

# Generate TOTP (Time-based One-Time Password)
def generate_totp():
    # Secret is email + "HENNGECHALLENGE003"
    secret = EMAIL + "HENNGECHALLENGE003"
    secret_bytes = secret.encode('utf-8')
    
    # Get current time in seconds and divide by 30 (time step)
    time_step = 30
    current_time = int(time.time())
    time_counter = current_time // time_step
    
    # Convert counter to bytes (8 bytes, big-endian)
    counter_bytes = time_counter.to_bytes(8, byteorder='big')
    
    # Generate HMAC-SHA-512
    h = hmac.new(secret_bytes, counter_bytes, hashlib.sha512)
    hmac_result = h.digest()
    
    # Perform dynamic truncation
    offset = hmac_result[-1] & 0x0F
    binary = ((hmac_result[offset] & 0x7F) << 24 |
              (hmac_result[offset + 1] & 0xFF) << 16 |
              (hmac_result[offset + 2] & 0xFF) << 8 |
              (hmac_result[offset + 3] & 0xFF))
    
    # Generate 10-digit password
    totp = binary % 10**10
    return str(totp).zfill(10)

# Make the HTTP POST request
def submit_solution():
    # Generate TOTP password
    totp_password = generate_totp()
    
    # Create auth header (Basic Authentication)
    auth_string = f"{EMAIL}:{totp_password}"
    auth_bytes = auth_string.encode('utf-8')
    auth_b64 = base64.b64encode(auth_bytes).decode('utf-8')
    headers = {
        'Authorization': f'Basic {auth_b64}',
        'Content-Type': 'application/json'
    }
    
    # Make the request
    url = "https://api.challenge.hennge.com/challenges/003"
    response = requests.post(url, headers=headers, data=json.dumps(body))
    
    # Print result
    print(f"Status code: {response.status_code}")
    print(f"Response: {response.text}")

if __name__ == "__main__":
    submit_solution()

```

## Important Notes:

1. **For the main solution**:
   - Make sure your solution handles all test cases correctly
   - Test with the provided sample inputs
   - Ensure you follow the no-loop/no-global-variables requirements

2. **For the submission script**:
   - You need to replace:
     - `your.email@example.com` with your actual email
     - `https://gist.github.com/YOUR_USERNAME/your_gist_id` with your actual gist URL
     - `"python"` with `"golang"` if you used Go
   - The TOTP implementation follows RFC6238 with the required modifications
   - You need the `requests` library installed (`pip install requests`)

3. **After success**:
   - Once you get a success response, you'll receive an email with a link to submit your CV and Cover Letter
   - As mentioned, clearly explain your motivation in your Cover Letter as it's considered important
