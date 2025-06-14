

---

### Setup for Windows

1. Download **Scrcpy**: [https://github.com/Genymobile/scrcpy/releases](https://github.com/Genymobile/scrcpy/releases), extract and open the folder.
    
2. **Enable Developer Options and USB Debugging** on your phone.
    
3. **Connect phone via USB** and allow USB debugging when prompted.
    
4. **Optional (for Wireless Mode)**:
    
    ```sh
    adb tcpip 5555  
    adb connect <PHONE_IP>
    ```
    
    Then remove USB.
    
5. **Launch scrcpy** using the `scrcpy` command in terminal.
    

---

### To Run Next Time

```sh
adb connect 192.168.1.5
scrcpy -s 192.168.1.5:5555
# Use this for consistent and specific connection** (like in a `.bat` file) ✅
```

or

```sh
adb tcpip 5555
adb connect <PHONE_IP>
scrcpy
# Use this when first switching from USB to wireless mode ✅
```

---

### To Make an Executable File (Windows `.bat` file)

```bat
@echo off
adb connect 192.168.1.5
scrcpy -s 192.168.1.5:5555
pause
```

---

### Optional Commands

**Check if device is connected:**
```sh
adb devices
```

**Change resolution (to reduce lag):**
```sh
scrcpy --max-size 1024
```

 **Turn on your phone screen remotely via PC** 

```sh
scrcpy --turn-screen-on

# If already connected:
adb shell input keyevent 26
```

---
### Command Meaning:

1. `adb tcpip 5555`  
    -  Tells the **connected USB device** to start listening over TCP/IP on port 5555.  
    -  Must be run **with USB connected once** to switch device into wireless mode.
    
2. `adb connect <PHONE_IP>`  
    -  Connects to the device wirelessly at the given IP.
    
3. `scrcpy`  
    -  Starts screen mirroring using the **default connected device**.

4. `adb connect 192.168.1.5`  
    -  Connects to device at IP `192.168.1.5` over port `5555` (default).
    
5. `scrcpy -s 192.168.1.5:5555`  
	-  Specifies **exact device** to mirror by IP and port.  
	-  Useful when **multiple devices** are connected (USB + Wi-Fi etc).
	- `-s` (`--serial`) flag is used to **specify the device** you want to connect to, by its serial ID or IP (for wireless).
    
6. `input keyevent 26`: Sends **power button** press (toggles screen state). Run twice if needed.