
**1. `adb` (Android Debug Bridge)** ⭐
- Communicates with Android device over USB/Wi-Fi    
- Push/pull files, install apps, run shell, sideload, logcat
    
**2. `fastboot`** ⭐
- Used when device is in **fastboot/bootloader mode** 
- Flash system/recovery/boot images, unlock bootloader
    
**3. `dmtracedump`**
- **Analyzes trace logs** created via `Debug.startMethodTracing()`
- Used for performance profiling of apps
    
**4. `etc1tool`**
- Converts PNG images to the **ETC1 texture compression** format (used in OpenGL ES)

**5. `hprof-conv`**
- Converts Android `.hprof` memory dump files into standard Java `.hprof` format
- Used with tools like Eclipse Memory Analyzer

**6. `lint`**
- Analyzes Android project source code for potential bugs, performance issues, or style problems

**7. `sqlite3`**
- Directly queries `.db` (SQLite) databases from Android devices
    
**8. `zipalign`**
- Optimizes APK file alignment to improve runtime performance
- Used before APK signing/final build
    
 **9. `apksigner**`**
- Signs APKs using keystores
- Ensures package integrity and allows Play Store publishing

***Deprecated****

 **10. `systrace` _(deprecated)_**
- Collected system-wide performance traces to analyze UI rendering, CPU usage    
- Now replaced by **Perfetto**

 **11. `traceview` _(deprecated)_**
- Visualizes execution logs (now replaced by Android Studio Profiler)
    
 **12. `adb backup` / `adb restore` _(deprecated)_**
- Backup/restore device data (removed from modern Android versions)
    

---

### Flashing

->Writing firmware or partition images (like system, boot, recovery, etc.) directly to a device's storage.

**Common examples:**
- `fastboot flash system system.img` → flashes system partition
- `adb sideload rom.zip` → flashes a ROM via recovery
    
**Types of flashing:**

**Full Rom** -> Flashing a complete OS
**Kernel** -> Flashing `boot.img`
**Recovery** -> Flashing `recovery.img`
**Firmware** -> Flashing modem, bootloader files


 **Differences :**

 **ROM (Read-Only Memory)**
- Complete Android OS (system apps, framework, kernel)
- Custom ROM: e.g., LineageOS, Pixel Experience
- Installed via recovery or fastboot
    
**Kernel**
- Bridge between hardware and software
- Manages CPU, memory, I/O
- Kernel is part of the ROM (inside `boot.img`)


**Recovery**
- A bootable partition for maintenance (install updates, factory reset)
- **Stock Recovery**: limited features
- **Custom Recovery**: TWRP, OrangeFox (used to flash ROMs/modules)

**Firmware**
- Low-level code that controls device hardware (modem, GPS, Wi-Fi, bootloader)
- Comes from OEM (specific to device)
- Flashed via fastboot or included in ROM package
    
 **Modules**
- Add-on components (e.g., face unlock, Dolby, Magisk modules)
- Modify specific system behavior without full ROM flashing
- Often flashed via recovery
    
**Relations:**
```
Firmware -> Bootloader -> Kernel -> ROM -> Recovery/Modules
           ↘                        ↘
          Fastboot               Recovery (TWRP)
```

- **Firmware** loads bootloader → boots **Kernel**
- **Kernel** runs the **ROM**
- **Recovery** used to flash ROM/modules
- **Modules** modify parts of the ROM without full replacement
    
---
### ADB
 
 **1. Setup & Connection**
```bash
adb devices                   # List connected devices ⭐
adb kill-server               # Kill ADB server
adb start-server              # Start ADB server
adb usb                       # Restart ADB in USB mode ⭐
adb tcpip 5555                # Restart ADB in TCP/IP mode ⭐
adb connect <ip>:5555         # Connect over Wi-Fi ⭐
adb disconnect                # Disconnect all devices
```

 **2. Reboot Options**
```bash
adb reboot                    # Reboot device ⭐
adb reboot bootloader         # Reboot to bootloader/Fastboot ⭐
adb reboot recovery           # Reboot to recovery ⭐
```

**3. Sideloading**
```bash
adb sideload <file.zip>       # Flash ZIP in recovery (e.g. ROMs, Mods) ⭐

# Examples
adb sideload launcher.zip
```

**4. File Operations**
```bash
adb push <local> <remote>     # Copy file from PC to device ⭐
adb pull <remote> <local>     # Copy file from device to PC ⭐

# Examples
adb push file.txt /sdcard/
adb pull /sdcard/log.txt
```

**5. APK Management**
```bash
adb install <apk_file>        # Install APK ⭐
adb install -r <apk_file>     # Reinstall APK (keep data)
adb uninstall <package_name>  # Uninstall app ⭐

# Examples
adb install myapp.apk
adb uninstall com.android.chrome
```

**6. Shell Access**
```bash
adb shell                     # Start interactive shell
adb shell <command>           # Run one-liner shell command

# Examples
adb shell ls /sdcard/
adb shell pm list packages ⭐
adb shell settings get global airplane_mode_on
```

*
**7. Logcat (Debugging)**
```bash
adb logcat                    # View real-time logs
adb logcat > log.txt          # Save logs to file
```

 **8. Screen/Media**
```bash
adb shell screencap /sdcard/ss.png   # Take screenshot
adb pull /sdcard/ss.png              # Save screenshot to PC

adb shell screenrecord /sdcard/rec.mp4   # Start screen recording
adb pull /sdcard/rec.mp4                 # Save to PC
```

 **9. Backup/Restore (Deprecated in new Android)**
```bash
adb backup -apk -shared -all -f backup.ab    # Create full backup
adb restore backup.ab                        # Restore backup
```

 **10. Misc**
```bash
adb shell getprop                         # View all system properties
adb shell am start -n pkg/.ActivityName   # Launch activity
adb shell input text "Hello World"        # Input text
adb shell input keyevent 26               # Power button
adb shell svc wifi disable                # Turn off Wi-Fi
adb shell svc data enable                 # Turn on mobile data
```

---

### Fastboot

**1. Device Connection**
```bash
fastboot devices              # List connected devices in fastboot mode ⭐
```

**2. Boot/Flash Images**
```bash
fastboot flash boot boot.img         # Flash boot image
fastboot flash recovery recovery.img # Flash recovery image ⭐
fastboot flash system system.img     # Flash system image
fastboot flash vbmeta vbmeta.img     # Flash vbmeta (required in A/B devices)
fastboot flash dtbo dtbo.img         # Flash DTBO (for some devices)
fastboot flash userdata userdata.img # Flash userdata (factory reset)
```

**3. Boot Temporarily**
```bash
fastboot boot recovery.img           # Boot recovery without flashing
```

**4. Unlock/Lock Bootloader**
```bash
fastboot oem unlock                  # Unlock bootloader (some OEMs)
fastboot flashing unlock             # Unlock bootloader (modern devices)
fastboot flashing unlock_critical    # Unlock critical partitions
fastboot flashing lock               # Lock bootloader
```
> ⚠ Unlocking wipes all data.

**5. Erase/Wipe Partitions**
```bash
fastboot erase userdata              # Wipe user data
fastboot erase system                # Erase system partition
fastboot erase cache                 # Erase cache
```

**6. Flash All from Factory Image** (Used in OEM factory ROMs):
```bash
flash-all.bat (Windows)
./flash-all.sh (Linux/Mac)
```

**7. Reboot**
```bash
fastboot reboot                     # Reboot normally
fastboot reboot recovery            # Reboot into recovery
```
