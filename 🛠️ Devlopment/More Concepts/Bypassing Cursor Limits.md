

### **Bypassing Cursor’s “Too many free trial accounts” Error**

**Step 1: Download the Script**

download the original `cursor_modifier.ps1` file in `/download` directory
```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/yuaotian/go-cursor-help/refs/heads/master/scripts/run/cursor_win_id_modifier.ps1" -OutFile "D:\gkmee\Downloads\cursor_modifier.ps1"
```

download my modified `my_cursor_modifier.ps1` file in `\Learn-Tech\Github Files` directory
```powershell
Invoke-WebRequest -Uri "https://raw.githubusercontent.com/gauravmeee/My-Github-Files/master/my_cursor_modifier.ps1" -OutFile "D:\gkmee\Desktop\Learn-Tech\My Github Files\my_cursor_modifier.ps1" 
```

**Step 2: Update Paths in Script**

Open `cursor_modifier.ps1` and replace:
```powershell
"$env:LOCALAPPDATA\Programs\cursor\Cursor.exe",
"$env:PROGRAMFILES\Cursor\Cursor.exe",
"$env:PROGRAMFILES(X86)\Cursor\Cursor.exe"
```

With your actual installation path:
```powershell
"D:\ProgramD\cursor\cursor.exe"
```

Also update fallback default path if present:

```powershell
Path = "D:\ProgramD\cursor\cursor.exe"
```

**Step 3: Run the Script**

to run original script from `/download` directory
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; . "D:\gkmee\Downloads\cursor_modifier.ps1"
```

to run my modified script `/My Github Files` directory
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; . "D:\gkmee\Desktop\Learn-Tech\My Github Files\my_cursor_modifier.ps1"
```

---
# Prompts

**Prompt 1**

```
 ██████╗██╗   ██╗██████╗ ███████╗ ██████╗ ██████╗
 ██╔════╝██║   ██║██╔══██╗██╔════╝██╔═══██╗██╔══██╗
 ██║     ██║   ██║██████╔╝███████╗██║   ██║██████╔╝
 ██║     ██║   ██║██╔══██╗╚════██║██║   ██║██╔══██╗
 ╚██████╗╚██████╔╝██║  ██║███████║╚██████╔╝██║  ██║
  ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝

================================
🚀   Cursor Anti-Trial Reset Tool (Pro Remover)
📱   Follow the WeChat public account: [煎饼果子卷AI]
🤝   Join to exchange more Cursor tricks and AI knowledge (free script, join the group via WeChat for more tips and experts)
💡   [Important Tip] This tool is free. If it helps you, please follow the WeChat account: [煎饼果子卷AI]

💰   [Small Ad] Selling Cursor Pro educational accounts with 1 year warranty & 3 months support. Contact on WeChat (86): JavaRookie666
================================

🎯 [Select Mode] Please choose the operation to perform:

  1️⃣  Modify machine code only
      • Modify machine ID
      • Inject cracked JS code into core files
      • Skip folder deletion / environment reset
      • Keep current Cursor config and data

  2️⃣  Reset environment + modify machine code
      • Fully reset environment (delete Cursor folder)
      • ⚠️  Configuration will be lost — please back up
      • Modify machine ID
      • Inject cracked JS code into core files
      • This is the full behavior of the script

Please enter your choice (1 or 2):
```

```
1
```

**Prompt 2**

```
✅ [Selection] You selected: Modify Machine Code Only

📋 [Execution Process] The "Modify Machine Code Only" mode will proceed with the following steps:
  1️⃣  Detect Cursor configuration files
  2️⃣  Back up existing configuration files
  3️⃣  Modify machine code configuration
  4️⃣  Display completion message

⚠️  [Notes]
  • No folders will be deleted, and the environment will not be reset
  • All existing configurations and data will be preserved
  • Original configuration files will be automatically backed up

🤔 [Confirmation] Please confirm that you understand the above process
Do you want to continue? (Enter y or yes to proceed, any other key to exit):
```

```
y
```

**Prompt 3**

```
✅ [Confirmed] User confirmed to continue

[Warning] Cursor version not detected  
[Hint] Please ensure Cursor is properly installed

💡 [Important Tip] Latest version 1.0.x is supported

🔍 [Check] Checking Cursor process...  
🚀 [Start] Starting machine code modification...

🔍 [Environment Check] Checking Cursor environment...  
✅ [Check] Config file format is correct  
✅ [Check] Found Cursor installation at: D:\ProgramD\cursor\cursor.exe  
✅ [Environment Check] All checks passed

🛠️  [Config] Modifying machine code configuration...  
🔒 [Security Check] Even in modify-only mode, ensure Cursor process is completely closed  
🔒 [Process Check] Checking and closing all Cursor-related processes...  
🔍 [Check] Process check 1/3...  
✅ [Success] All Cursor processes have been closed  
🔐 [Permission Check] Checking file access: storage.json  
⚠️  [Permission] File is read-only, attempting to fix permissions...  
✅ [Fixed] Read-only attribute removed  
✅ [Permission] Permission fix successful  
🔍 [Validation] Validating config file format...  
✅ [Validation] Config format is valid  
📋 [Current Config] Existing telemetry properties:
   ✓ telemetry.machineId = 61757468307c75736572...
   ✓ telemetry.macMachineId = dbaef711-5cf1-40d4-b...
   ✓ telemetry.devDeviceId = 697cc15d-1495-4d57-a...
   ✓ telemetry.sqmId = {D7AAE2C2-B67B-4549-...

🔄 [Attempt] Modification attempt 1/3...  
⏳ [Progress] 1/6 - Generating new device identifiers...  
✅ [Progress] 1/6 - Device identifiers generated  
⏳ [Progress] 2/6 - Creating backup directory...  
⏳ [Progress] 3/6 - Backing up original config...  
✅ [Progress] 3/6 - Backup successful: storage.json.backup_20250805_200244_retry1  
⏳ [Progress] 4/6 - Reading original config to memory...  
⏳ [Progress] 5/6 - Updating config in memory...  
   ✓ Updated: telemetry.devDeviceId  
   ✓ Updated: telemetry.machineId  
   ✓ Updated: telemetry.sqmId  
   ✓ Updated: telemetry.macMachineId  
⏳ [Progress] 6/6 - Writing updated config atomically...  
🔍 [Final Verification] Verifying new config...  
📋 [Verification Details]  
   ✓ telemetry.devDeviceId: Verified  
   ✓ telemetry.machineId: Verified  
   ✓ telemetry.sqmId: Verified  
   ✓ telemetry.macMachineId: Verified  
✅ [Success] Modification succeeded on 1st attempt!

🎉 [Done] Machine code modification completed!  
📋 [Details] Updated identifiers:
   🔹 machineId: 61757468307c757365725f6C8CC849DBB2909FE914B0CCC588CDC665B2FE0F7D9D8B48F5C02FB092B878B9  
   🔹 macMachineId: 43a2c020-84a0-4d4e-bcf0-4a417524c4aa  
   🔹 devDeviceId: b4a4c839-7137-4351-9e3d-25773fa9a4e0  
   🔹 sqmId: {455FE4B3-E0ED-437C-B86B-8AA2960D3474}

💾 [Backup] Original config backed up to: storage.json.backup_20250805_200244_retry1  
🔒 [Protection] Setting config file to read-only...  
✅ [Protection] Config is now read-only to prevent overwrites  
💡 [Hint] File path: C:\Users\gkmee\AppData\Roaming\Cursor\User\globalStorage\storage.json  
🔒 [Security] Recommended to restart Cursor to apply changes

🎉 [Config File] Machine code config modification complete!  
🔧 [Registry] Modifying system registry...  
🔧 [Registry] Updating registry MachineGuid...  
✅ [Info] Current registry value:  
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Cryptography  
    MachineGuid    REG_SZ    3f3313db-cb2a-47b6-b01c-16adaa344dd9  
💾 [Backup] Backing up registry...  
The operation completed successfully.  
✅ [Backup] Registry backup saved to:  
C:\Users\gkmee\AppData\Roaming\Cursor\User\globalStorage\backups\MachineGuid_20250805_200244.reg  
🔄 [Generated] New MachineGuid: 21c748fe-ea9b-40a7-ada7-f29dcdf21a8d  
✅ [Success] Registry updated:  
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Cryptography  
    MachineGuid    REG_SZ    21c748fe-ea9b-40a7-ada7-f29dcdf21a8d

🔧 [Device Fingerprint Bypass] Injecting JavaScript...  
💡 [Explanation] This modifies Cursor's core JS files to bypass deep device checks

🔧 [Kernel Modification] Modifying Cursor core JS files...

❌ [Error] Cursor app installation path not found  
💡 [Hint] Please ensure Cursor is correctly installed  
✅ [Registry] System registry update successful  
⚠️  [JavaScript Injection] JS injection failed, but other tasks succeeded

🎉 [Complete] Machine code modification completed!  
📋 [Details] The following were modified:
   ✓ Cursor config file (storage.json)  
   ✓ System registry (MachineGuid)  
   ⚠ JavaScript core injection (partially failed)  
🔒 [Protection] Setting config file to read-only...  
✅ [Protection] File set to read-only to prevent overwrite  
💡 [Hint] File path: C:\Users\gkmee\AppData\Roaming\Cursor\User\globalStorage\storage.json  
💡 [Hint] You can now launch Cursor using the new machine ID configuration

================================  
📱  Follow the WeChat public account [煎饼果子卷AI] to explore more Cursor tips and AI knowledge (Free script, more techniques and experts in the group)  
================================

🎉 [Script Finished] Thank you for using the Cursor Machine Code Modifier!  
💡 [Hint] If there are any issues, please refer to the WeChat account or re-run the script

Press Enter to exit:
```

```
Enter
```