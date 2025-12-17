

**SSH (Secure Shell)** is a cryptographic network protocol used to securely connect to remote machines over an unsecured network.

**Purpose**
- Remote login to servers
- Secure file transfer
- Remote command execution
- Port forwarding and tunneling

**Default Port**
```
22
```

**How SSH Works**
- Client initiates connection to remote server
- Key exchange and encryption established
- User authentication by password or SSH keys
- Encrypted session begins

##### **Authentication Methods**

```
1. Password-based authentication
2. Public–Private key authentication (recommended)
```

##### **Generate SSH Key (Client Side)**

```
ssh-keygen -t rsa -b 4096
```

**Keys created:**
```
id_rsa        → Private key
id_rsa.pub    → Public key
```

##### **Copy Public Key to Server**

```
ssh-copy-id user@server-ip
```

**OR manually upload contents of `id_rsa.pub` to:**
```
~/.ssh/authorized_keys
```

##### **SSH Login**

```
ssh user@server-ip
```

##### **SSH With Custom Port**

```
ssh -p <port> user@server-ip
```

##### **Transfer Files via SSH**

**Upload**
```
scp localfile user@server-ip:/path/
```

**Download**
```
scp user@server-ip:/path/file localpath
```

#### **SSH Port Forwarding**

**Local Forwarding**
```
ssh -L localPort:targetIP:targetPort user@server-ip
```

**Remote Forwarding**
```
ssh -R remotePort:targetIP:targetPort user@server-ip
```

#### **SSH Config File (Client Side)**

**File path**
```
~/.ssh/config
```

**Example**
```
Host myserver
    HostName 10.0.0.5
    User ubuntu
    Port 22
    IdentityFile ~/.ssh/id_rsa
```

#### **Disable Password Login (Increase Security)**

**Server config**
```
/etc/ssh/sshd_config
```

**Set**
```
PasswordAuthentication no
```

**Restart SSH service**
```
sudo systemctl restart ssh
```

##### **Important Security Tips**

- Always use key-based login
- Disable root login
- Change default port 22
- Use firewall to limit SSH access

##### **Common SSH Errors**

```
Permission denied (publickey) → Key not configured correctly
Connection refused → SSH service not running / wrong port
Host key verification failed → Server identity changed, remove from known_hosts
```

##### **Related Tools**

```
ssh     → remote login
scp     → secure copy
sftp    → interactive file transfer
ssh-keygen → generate keys
ssh-copy-id → upload key to server
```

### SFTP

**SFTP (SSH File Transfer Protocol)** is a secure method to transfer files over SSH.

**Purpose**
- Upload and download files securely
- Manage directories on remote server
- Remote file editing and permission handling
    
**Default Port**
```
22
```

**Requirements**
- SSH server must be running on remote machine
- User credentials or SSH key must be available

**Security Practices**

- Prefer SSH key login instead of password
- Use strong key length (4096 bits)
- Restrict SSH access using firewall

**Common Errors**
```
Connection refused → SSH not running or wrong port
Permission denied → wrong credentials or no access rights
No such file → invalid path
```

##### **Start SFTP (Windows CMD / PowerShell)**


**Start SFTP**
```
sftp user@server-ip
```

**After login, basic commands:**
```
ls          → list files
cd folder   → change directory
pwd         → show remote path
lpwd        → show local path
get file    → download file
put file    → upload file
exit        → close SFTP
```

**Example upload**
```
sftp user@server-ip
put C:\data\test.txt /home/user/
```

**Example download**
```
sftp user@server-ip
get /home/user/test.txt C:\data\
```

**Transfer Folder (recursive)**
```
put -r myFolder
get -r myFolder
```

**SSH Key Based Login**
```
sftp -i C:\Users\me\.ssh\id_rsa user@server-ip
```

**Resume Interrupted Transfer**
```
reget <file>  → resume download
reput <file>  → resume upload
```

##### **Windows GUI Tools for SFTP**

```
WinSCP → easy and reliable
FileZilla → supports SFTP
VS Code SFTP extension → for coding workflow
```

**WinSCP**
1. Install WinSCP
2. Select File Protocol → SFTP
3. Enter Hostname, Username, Password / SSH Key
4. Connect
5. Drag-and-drop files to transfer

**VS Code**
1. Install extension → SFTP by Natizyskunk
2. Configure `sftp.json`
3. Upload / download directly from editor
