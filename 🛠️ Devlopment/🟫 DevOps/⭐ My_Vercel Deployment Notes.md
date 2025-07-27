
# [Vercel](https://vercel.com/)

## Vercel Deployment (CLI) for Windows

11. **Install Vercel CLI**:
    - Install **Node.js** from [nodejs.org](https://nodejs.org/en/download/).
    - Once installed, open a terminal (Command Prompt or PowerShell) and run: `npm install -g vercel`
12. **Login to Vercel**: `vercel login`
13. **Deploy App**:
    - Navigate to your project directory and run: `vercel`
14. **View Logs**:  `vercel logs <deployment-id>`
15. **Redeploy App**: `vercel --prod --force`
16. **Link Project to Vercel**: `vercel link`

---

### Vercel Cron Jobs

**What is it?**

- Vercel Cron Jobs let you **run scheduled functions** (e.g., for cleanup, notifications, pings) on **Vercel Serverless Functions** or **Edge Functions**.

 **Key Features**
- Native to Vercel (no external service needed)
- Supports **cron syntax**
- Runs on **Serverless Functions** or **Edge Functions**
- Works even when app is idle (no incoming traffic)
    
**Use Cases**
- Send emails/summaries at fixed times
- Refresh cache
- Clean up database
- Ping Render/Heroku backend to prevent cold start
    

**How to Set Up**

**1. Create API Route**
- Create a serverless function under `api/`:
```ts
// /api/ping.ts
export default async function handler(req, res) {
  // your scheduled logic here
  res.status(200).json({ message: "Pinged!" });
}
```

**2. Define Cron in `vercel.json`**
```json
{
  "cron": [
    {
      "path": "/api/ping",
      "schedule": "*/10 * * * *"  // every 10 mins
    }
  ]
}
```
> Put `vercel.json` at the project root.

**3. Deploy to Vercel**
- Push to GitHub → Vercel deploys it.
- The cron job will now run at scheduled times.
    

**Cron Syntax Examples**

|Schedule|Meaning|
|---|---|
|`* * * * *`|Every minute|
|`0 * * * *`|Every hour at 0th minute|
|`0 0 * * *`|Every day at midnight|
|`*/5 * * * *`|Every 5 minutes|

**Limitations**
- Max 100 cron jobs per project
- Max 10 concurrent executions
- No guaranteed exact execution time (can vary slightly)
- Only supported in **Pro and Enterprise** plans
    

**Best Practices**
- Keep the logic short (within serverless timeout)
- Log outputs for debugging
- Use environment variables for secrets
- Use for **non-critical background tasks**


---

### Vercel Serverless Functions – Timeout & Cron Job Notes

**What are Serverless Functions in Vercel?**
- Lightweight backend functions that run on-demand
- Auto-scaled and deployed with your project
- Used in API Routes or `server actions`
    
**Timeout in Vercel Serverless Functions**

|Plan|Max Timeout|
|---|---|
|Hobby / Pro|**10 seconds**|
|Enterprise|**Up to 60 seconds** (via support)|

> ❌ **You cannot manually increase the timeout** on Hobby/Pro plans.


**Why Timeout Happens**
- Long-running external API (e.g., a slow or sleeping backend like Render)
- Heavy DB queries
- Blocking or inefficient code
    

 **Symptoms of Timeout**
- API call fails with **504 Gateway Timeout**
- Function exits before finishing task
- No response or partial data returned
    
**Workarounds & Best Practices**

1. **Use Vercel Cron Jobs**
	- Schedule functions to run in the background
	- Good for periodic data updates, syncing, backups
	- Keeps user-facing functions fast

2. **Move to a Custom Server**
	- Use Express, Node.js, or Python backend (e.g., Render, Railway)
	- You control the timeout settings
    
3. **Optimize Code**
	- Use faster APIs
	- Minimize external dependencies
	- Use caching (e.g., `revalidateTag` wisely)
    

---

### 🧠 Summary Table

|Use Case|Recommended Method|
|---|---|
|User-facing API (fast)|Vercel Serverless Function|
|Background job / sync|Vercel Cron Job|
|Long-running logic (>10s)|Custom server (e.g., Express)|
|Slow API fetching|Pre-fetch with cron|

---

Let me know if you want **step-by-step instructions** on setting up **Vercel Cron Jobs**.