

# [Render](https://dashboard.render.com/)

### Render Deployment (CLI) for Windows

1. **Install Render CLI on Windows**:
    - Download and install the **Render CLI** via [Render Docs](https://render.com/docs/cli#install-the-render-cli).
    Alternatively, you can install it through **Windows Subsystem for Linux (WSL)**: `curl -fsSL https://cli.render.com/install.sh | sh`
2. **Login to Render**: `render login`
3. **Deploy App**:
    - Make sure your app is in a Git repository. `render services deploy <service-name>`
4. **Restart Service**: `render services restart <service-name>`
5. **View Logs**: `render logs <service-name> --follow`
6. **Scale Service**: `render services scale <service-name> --instances <num>`

**Flask :**
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

**FastAPI :**
- Same As Flask. Just Change these:
- add `uvicorn` package in place of `gunicorn` in  `requirements.txt`
- Use `uvicorn app:app --reload`  in place of `gunicorn app:app`
Note: `Uvicorn` is a fast ASGI server for Python web applications for running asynchronous web applications.

---

### Cold Start & 504 Gateway Timeout Issues

**Problem :**
- When hosting a backend (like Flask) on Render’s free plan, the service automatically “sleeps” after 15 minutes of inactivity.
- The first request after sleeping can take 30 seconds or more for the server to “wake up.”
- Automated clients (such as frontend apps, Next.js, or API fetches) often have a default timeout (usually 30 seconds or less).
- If the backend takes too long to wake up, the client receives a **504 Gateway Timeout** error.

**Symptoms :**
- First request after a period of inactivity fails with a 504 error.
- Manually visiting the API in a browser (and waiting) wakes up the server, after which automated requests succeed.
- This cycle repeats after each period of inactivity.

**Root Cause :**
- **Render’s free plan** puts services to sleep to save resources.
- Wake-up time is often longer than most client timeouts.
- Automated clients (like Next.js fetch) do not wait long enough for the backend to become responsive.

**Solutions :**
1. **Upgrade to a paid Render plan:**  
2. **Increase timeout to 60 seconds (client or reverse proxy):**  
3. **Use a keep-alive ping service:**  
4. **Inform users about cold starts:**  
