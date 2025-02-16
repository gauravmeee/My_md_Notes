
# [Render](https://dashboard.render.com/)

##### Render Deployment (CLI) for Windows

1. **Install Render CLI on Windows**:
    - Download and install the **Render CLI** via [Render Docs](https://render.com/docs/cli#install-the-render-cli).
    Alternatively, you can install it through **Windows Subsystem for Linux (WSL)**: `curl -fsSL https://cli.render.com/install.sh | sh`
2. **Login to Render**: `render login`
3. **Deploy App**:
    - Make sure your app is in a Git repository. `render services deploy <service-name>`
4. **Restart Service**: `render services restart <service-name>`
5. **View Logs**: `render logs <service-name> --follow`
6. **Scale Service**: `render services scale <service-name> --instances <num>`

##### Flask
7. **Create** `requirements.txt` with all required dependencies. also add `gunicorn` package
8. **Create** `Procfile` (no extension) and add `web: gunicorn app:app`
9. **Push to Github**
10. **On Render :** 
	- Click +-> Web Services. 
	- Choose Your Repository, 
	- **Set Build Command** `pip install -r requirements.txt`
	- **Set Start Command** `gunicorn app:app`
	- **Configure Necessary Environment Variables/Keys** like `SECRET_KEY`
Note: **`Gunicorn` (Green Unicorn)** is a **WSGI HTTP server** for running Python web applications in production.

##### FastAPI
- Same As Flask. Just Change these:
- add `uvicorn` package in place of `gunicorn` in  `requirements.txt`
- Use `uvicorn app:app --reload`  in place of `gunicorn app:app`
Note: `Uvicorn` is a fast ASGI server for Python web applications for running asynchronous web applications.

---
# [Vercel](https://vercel.com/)

##### Vercel Deployment (CLI) for Windows
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

# [Netlify](https://app.netlify.com/)

---

