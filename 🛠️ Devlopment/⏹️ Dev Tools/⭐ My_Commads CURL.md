
# [How to use CURL on Windows | How to test API with CURL | CURL Basics Step by Step](https://youtu.be/8f9DfgRGOBo)
# cURL Beginner Window Tutorial

- To Learn and Test front-end against a real API. Use  [Test API (reqres.in)](https://reqres.in)
- cURL Official Website  [official website (curl.haxx.se)](https://curl.haxx.se/).
#### What is cURL?

- **cURL (Client URL)** is a command-line tool and library used to transfer data with URLs. It supports multiple protocols such as HTTP, HTTPS, FTP, etc.
- **On macOS**, cURL comes pre-installed and can be used directly from the terminal.
#### How to Run cURL on Windows

**a. cURL comes pre-installed on Windows 10 and later.**

- **Pre-installed on Windows 10 and later**
- To check if cURL is available:
    ```sh
    curl --version
    ```

**b. Better option is to use Curl in Git-bash**

- Download Git Bash from [git-scm.com](https://git-scm.com/downloads).
- Open Git Bash and use cURL commands.

#### Getting Help

View general help:
```sh
curl --help
```

- Read the full manual:
```sh
curl --manual
```

Open Command Line or Gitbash to Write command

---
## Running API Requests with cURL


We will use the [Test API (reqres.in)](https://reqres.in) for demonstration.
#### **1. GET Requests**

**Get only response:**
```sh
# curl URL
curl https://reqres.in/api/users
```
```
{
  "page": 1,
  "per_page": 6,
  "total": 12,
  "data": [
    { "id": 1, "email": "george.bluth@reqres.in", "first_name": "George", "last_name": "Bluth" }
  ]
}
```

**Handle Redirection (`-L`) :**
```sh
# curl -L URL
curl -L https://reqres.in/api/users
```

**Get Response with Headers (`-i`) :**
```sh
# curl -i URL
curl -i https://reqres.in/api/users
```
```
HTTP/2 200 
date: Thu, 03 Apr 2025 12:00:00 GMT
content-type: application/json
...
{
  "page": 1,
  "per_page": 6,
  "total": 12,
  ...
}
```

**Get Only Headers (`--head` or `-I`):**
```sh
# curl --head URL
curl --head https://reqres.in/api/users

#or

#curl -I URL
curl -I https://reqres.in/api/users
```
```
HTTP/2 200 
date: Thu, 03 Apr 2025 12:00:00 GMT
server: cloudflare
content-type: application/json
```

**Verbose Mode (`-v`) for Detailed Interaction:**
```sh
# curl -v URL
curl -v https://reqres.in/api/users
```
```
* Trying 104.21.234.45...
* Connected to reqres.in
> GET /api/users HTTP/2
> Host: reqres.in
...
< HTTP/2 200
...
```

**Save Detailed Logs to a File (`--trace`):**
```sh
# curl --trace File-Name URL
curl --trace logFile.txt https://reqres.in/api/users
```

**Send Headers in Requests (`-H` or `--header`):**
```sh
# curl -H "Header-Name: value" URL
curl -H "Accept:application/json" https://reqres.in/api/users
```

#### **2. POST Request**

**Send Form Data (`-d`):**
```sh
# curl URL -d data
curl -X POST https://reqres.in/api/users -d "name=morpheus&job=leader"
```
```
{
  "name": "morpheus",
  "job": "leader",
  "id": "123",
  "createdAt": "2025-04-03T12:00:00.000Z"
}
```

**Send JSON Data with a Custom Header :**
```sh
# curl -X POST -H "Header-Name" URL -d data
curl -X POST https://reqres.in/api/users \
     -H "Content-Type: application/json" \
     -d '{"name": "morpheus", "job": "leader"}'
```

Note: The `\` (backslash) is used in shell commands as a **line continuation character**. It allows you to break a long command into multiple lines for better readability.

#### **3. PUT Request**

**Update Data and View Response (`-i` for Headers):**
```sh
# curl -i -X PUT URL -d data
curl -i -X PUT https://reqres.in/api/users/2 \
     -H "Content-Type: application/json" \
     -d '{"name": "morpheus", "job": "zion resident"}'
```
```
HTTP/2 200 
date: Thu, 03 Apr 2025 12:00:00 GMT
...
{
  "name": "morpheus",
  "job": "zion resident",
  "updatedAt": "2025-04-03T12:00:00.000Z"
}
```
#### **4. DELETE Request**

**Delete Data (`-X DELETE`):**
```sh
# curl -i -X DELETE URL
curl -i -X DELETE https://reqres.in/api/users/2
```
```
HTTP/2 204 
date: Thu, 03 Apr 2025 12:00:00 GMT
...
```

#### Options Meanings

**Short Options:**
- `-L` -> Follow redirects (HTTP 3xx) (`--Location`)
- `-I` -> Fetch headers only (HEAD request) (`--head`)
- `-H` -> Add custom header (`--header`)
- `-X` -> Specify request method (GET, POST, etc.) (`--request`)
- `-v` -> Verbose output (debug info)  (`--verbose`)
- `-d` -> Send data in a POST request (`--data`)
- `-i` -> Include response headers in output

**Long Options:**
- `--trace` -> Detailed debugging output to a file
- `--request` -> Same as `-X`
- `--head` ->Same as `-I`
- `--header`-> Same as `-H`
- `--data` -> Same as `-d`
- `--verbose` -> Same as `-V`
- `--location` -> Same as `-L`


---

### formatted (pretty-printed) JSON data fetched using `curl`

```sh
curl -s  https://flask-jobs-api.onrender.com/ | python -m json.tool
```
- `-s` (silent) suppresses progress output.
- `python3 -m json.tool` is built into Python, so it's available if Python is installed.

- **Alternatively** Better, you can use `jq`, which is a dedicated JSON processor but requires installation.
```sh
curl -s  https://flask-jobs-api.onrender.com/ | jq
```