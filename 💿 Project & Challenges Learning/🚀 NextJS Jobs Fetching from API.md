


## Client-Side Rendering (CSR)


#### `apps/jobs/page.js`
```javascript
"use client";  // This makes this a Client Component in Next.js

import { useState, useEffect } from 'react'; // Importing hooks for state and side effects
import axios from 'axios'; // Importing Axios for making HTTP requests

// Checking the environment mode (development or production)
if (process.env.NODE_ENV === 'production') {
  console.log('Running in production mode'); // Logs message when running in production
} else {
  console.log('Running in development mode'); // Logs message when running in development
}
```
- `JobsPage()`
```jsx
const JobsPage = () => {
  // State to store job data
  const [jobs, setJobs] = useState([]);
  // State to track loading status
  const [loading, setLoading] = useState(true);
  // State to store any errors encountered during API call
  const [error, setError] = useState(null);

  useEffect(() => {
    // Function to fetch jobs from the Flask API
    const fetchJobs = async () => {
      try {
        const response = await axios.get('https://flask-jobs-api.onrender.com/'); // Fetch data from Flask API
        setJobs(response.data); // Update state with received jobs data
      } catch (err) {
        setError('Error fetching jobs'); // Set error message in case of failure
      } finally {
        setLoading(false); // Set loading to false after API call finishes
      }
    };

    fetchJobs(); // Call fetchJobs function when the component mounts
  }, []); // Empty dependency array ensures useEffect runs only once

  // Show loading spinner while data is being fetched
  if (loading) {
    return (
      <div className="flex flex-col justify-center items-center mt-40">
        <div className="animate-spin rounded-full h-12 w-12 border-4 border-gray-300 border-t-blue-500"></div> 
        {/* Spinning loader animation */}
        <p className="text-xl text-gray-500 mt-2 ml-5">Loading...</p>
      </div>
    );
  }

  // Show error message if fetching data fails
  if (error) {
    return (
      <div className="flex justify-center items-center pt-40">
        <p className="text-xl text-red-500">{error}</p> 
        {/* Display error message in red */}
      </div>
    );
  }

  return (
    <div className="min-h-screen container mx-auto p-6">
      {/* Page title */}
      <h2 className="text-2xl md:text-4xl font-semibold mb-4 text-center">Job Updates</h2>
      
      {/* Show message if no jobs are available */}
      {jobs.length === 0 ? (
        <p className="text-center text-lg text-gray-500">No jobs available at the moment.</p>
      ) : (
        <ul className="space-y-6">
          {/* Loop through the jobs array and display each job */}
          {jobs.map((job, index) => {
            const datePosted = new Date(job.date_posted); // Convert date string to Date object
```
- Return 
```jsx
            return (
              <li
                key={index} // Using index as key (ensure jobs have unique identifiers for better performance)
                className="bg-white dark:bg-gray-800 p-6 rounded-lg shadow-md hover:shadow-xl transition-shadow duration-300"
              >
                {/* Job title */}
                <h3 className="text-xl font-semibold text-gray-800 dark:text-gray-100">{job.role}</h3>
                {/* Company name */}
                <p className="text-md text-gray-600 dark:text-gray-300">Company: {job.company}</p>
                {/* Batch eligibility */}
                <p className="text-md text-gray-600 dark:text-gray-300">Batch Eligible: {job.batch_eligible}</p>
                {/* Job location */}
                <p className="text-md text-gray-600 dark:text-gray-300">Location: {job.location}</p>

                {/* Show expected stipend if available */}
                {job.expected_stipend && (
                  <p className="text-md text-gray-600 dark:text-gray-300">
                    Expected Stipend: {job.expected_stipend}
                  </p>
                )}

                {/* Show extra benefits if available */}
                {job.expected_benefits && (
                  <p className="text-md text-gray-600 dark:text-gray-300">
                    Extra Benefits: {job.expected_benefits}
                  </p>
                )}

                {/* Display formatted date posted */}
                <p className="text-md text-gray-600 dark:text-gray-300">
                  Date Posted: {datePosted.getDate()}-{datePosted.getMonth() + 1}-{datePosted.getFullYear()}
                </p>

                {/* Apply link */}
                <a
                  href={job.apply_link}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="mt-4 inline-block px-4 py-2 bg-blue-500 text-white rounded-md hover:bg-blue-600 transition-colors duration-300"
                >
                  Apply Link
                </a>
              </li>
            );
          })}
        </ul>
      )}
    </div>
  );
};

export default JobsPage; // Exporting the component
```


---

## **Update 1** : Using Server-Side Rendering (SSR)  and Axios ✅

1. **No "use client" directive** - The page is now a server component ✅
2. **Removed React state and useEffect** - Data fetching happens on the server ✅
3. **Added Next.js revalidation** - Server revalidates the data every hour ✅
4. **No loading state in the component** - Loading is handled by Next.js ✅
5. **Separated error handling** - Using Next.js error boundary system ✅


When using axios (as in your original code):
- Axios is a third-party library that needs to be installed as a dependency
- It provides a consistent API across browsers and Node.js environments
- It has features like automatic JSON parsing, request/response interceptors, and better error handling
- In the SSR context, it means an extra dependency that needs to be available in the server environment

#### `apps/jobs/page.js`
```javascript
// app/jobs/page.js
import axios from 'axios';
```
- `getJobs()`
```js
// Server component - no "use client" directive needed
async function getJobs() {
  try {
    // This fetch happens on the server
    const response = await axios.get('https://flask-jobs-api.onrender.com/', {
      // Using Next.js revalidation - adjust time as needed
      headers: {
        'Cache-Control': 'max-age=0, s-maxage=3600' // Cache for 1 hour on server
      }
    });
    return response.data;
  } catch (error) {
    console.error("Failed to fetch jobs:", error);
    return [];
  }
}

// Log environment only on the server side
console.log(`Running in ${process.env.NODE_ENV} mode`);
```
- `JobsPage()`
```js
export default async function JobsPage() {
  // Fetch data on the server
  const jobs = await getJobs();
```
- Return
```js  
  return (
	...
  );
}

```

---

## **Update 2** : Removed Axios & `getJobs` function to use native fetch instead ✅


For better performance and to ensure the `axios` package is available server-side, you might want to modify the `getJobs` function to use native fetch instead

**When using native fetch (as in my alternative suggestion):**
- Fetch is built into modern JavaScript environments (browsers and Node.js)
- No additional dependencies required
- Simpler, more lightweight solution for basic requests
- Next.js optimizes the fetch API with features like automatic request deduplication

**The main reasons to consider switching from axios to native fetch in your SSR implementation:**
1. **Reduced dependencies**: One less library to maintain and keep updated
2. **Smaller bundle size**: No additional code needs to be shipped to the client
3. **Next.js optimization**: Next.js has special handling for the native fetch API that enables features like automatic deduplication and revalidation

#### `apps/jobs/page.js`
```javascript
// Alternative getJobs function using native fetch instead of axios
async function getJobs() {
  try {
    // Using Next.js fetch with revalidation
    const response = await fetch('https://flask-jobs-api.onrender.com/', {
      next: { revalidate: 3600 } // Revalidate every hour
    });
    
    if (!response.ok) {
      throw new Error(`Failed to fetch: ${response.status}`);
    }
    
    return await response.json();
  } catch (error) {
    console.error("Failed to fetch jobs:", error);
    return [];
  }
}

```


---


