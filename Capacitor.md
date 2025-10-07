
##### **Capacitor Commands – Detailed Notes**

**1. Initialization**
```bash
# Initialize Capacitor project (creates capacitor.config.ts/json)
npx cap init
# Requires appId (e.g., com.myapp.app) and appName
```

```bash
# Add Android platform (creates /android folder)
npx cap add android
```

```bash
# Add iOS platform (creates /ios folder)
npx cap add ios
```

**2. Building & Copying Assets**
```bash
# Framework build (React/Angular/Next.js etc.)
npm run build
# Generates production-ready files (usually in /dist or /out)
```

```bash
# Copy only web assets to native projects
npx cap copy
# Copies -> android/app/src/main/assets/public
# Use after every web build
```

```bash
# Copy + update plugins and native dependencies
npx cap sync
```

```bash
# Sync only Android platform
npx cap sync android
```

```bash
# Sync only iOS platform
npx cap sync ios
```

**3. Running Apps**
```bash
# Build & install app on connected Android device/emulator
npx cap run android
```

```bash
# Build & install app on iOS device/simulator
npx cap run ios
```

```bash
# Open Android project in Android Studio
npx cap open android
# Use for: Signed APK/AAB, Gradle configs, debugging
```

```bash
# Open iOS project in Xcode
npx cap open ios
# Use for: App Store builds, simulator debugging
```

**4. Maintenance & Updates**
```bash
# Update Capacitor core + CLI
npm install @capacitor/core@latest @capacitor/cli@latest
```

```bash
# Apply updates to all platforms
npx cap update
```

```bash
# Update only Android platform
npx cap update android
```

```bash
# Update only iOS platform
npx cap update ios
```

**5. Debugging & Cleaning**
```bash
# Diagnose configuration issues
npx cap doctor
```

```bash
# Clean Android build artifacts
npx cap clean android
```

```bash
# Clean iOS build artifacts
npx cap clean ios
```

**Typical Workflow**
```bash
# 1. Build web app
npm run build

# 2. Copy assets
npx cap copy

# 3. Sync (if plugins changed)
npx cap sync android

# 4. Run on device
npx cap run android

# 5. Open IDE for release builds
npx cap open android   # Android Studio
npx cap open ios       # Xcode
```

---
---

### Next.js → Android App with Capacitor (Complete Notes)

##### **1. Setup Capacitor**

- Install Capacitor in your Next.js project:
    ```bash
    npm install @capacitor/core @capacitor/cli
    ```

- Initialize Capacitor:
    ```bash
    npx cap init
    ```
    - `appId`: unique ID, e.g., `com.myapp.app`
    - `appName`: your app name
    - `webDir`: set to `"out"` (Next.js export folder).

##### **2. Configure Next.js for Static Export**

- In **`next.config.js`**:
    ```js
    const nextConfig = {
      output: 'export',        // required for static files
      trailingSlash: true,     // helps with routing
      distDir: 'out',          // build output folder
      images: { unoptimized: true }
    }
    module.exports = nextConfig
    ```
    
- Build static files:
    ```bash
    npm run build
    ```
##### **3. Add Android Platform**

- Add Android project:
    ```bash
    npx cap add android
    ```
- Now `/android` folder is created (native project).

##### **4. Copy Web Assets to Android**

- After every `npm run build`, sync files:
    ```bash
    npx cap copy
    ```
    
- If plugins or Capacitor config changed:
    ```bash
    npx cap sync android
    ```

##### **5. Run the App**

- Open Android Studio:
    ```bash
    npx cap open android
    ```
    
- Or run directly on emulator/device:
    ```bash
    npx cap run android
    ```
##### **6. Development vs Offline Build** ⭐

- **Development Mode (live reload)**
    - In `capacitor.config.ts`:
        ```ts
        server: { url: "http://10.0.2.2:3000", cleartext: true }
        ```
        
    - Run:
        ```bash
        npm run dev
        ```
    - Works only while PC dev server is active.
        
- **Offline Production Build**
    - Remove `server.url` from config.
    - Use `output: 'export'` & `distDir: 'out'` → Next.js generates static HTML in `/out`.
    - `npx cap copy` puts static site inside APK.
    - App runs offline like a PWA.

##### **7. Using APIs (Supabase / External)**

- Online features still work (fetches data from internet).
- Offline parts (cached pages, SQLite, PWA) continue without network.

##### **8. Building APK / AAB**

1. **Open project:**
    ```bash
    npx cap open android
    ```
    
2. In **Android Studio**:
    - **Debug APK**: Build → Build Bundle(s)/APK(s) → Build APK(s).  
        → File saved at `android/app/build/outputs/apk/debug/app-debug.apk`.
    - **Release APK/AAB**: Build → Generate Signed Bundle / APK.
        - Choose APK or AAB.
        - Provide keystore (for Play Store).
        - Outputs in `android/app/release/`.

##### **9. Key Capacitor Commands**
- `npx cap init` → Setup config
- `npx cap add android` → Add Android project
- `npx cap copy` → Copy built web files
- `npx cap sync android` → Sync assets + plugins
- `npx cap run android` → Run on device
- `npx cap open android` → Open in Android Studio
    
##### **10. Workflow Summary**

1. Code in Next.js
2. `npm run build` → generates `/out`
3. `npx cap copy` → copy into Android project
4. `npx cap sync android` → update native project
5. `npx cap run android` or `npx cap open android`
6. Export APK/AAB via Android Studio

---

### Capacitor in a Next.js Project – Effects, Files, and Removal


##### **1. Does Capacitor Affect Next.js Project?**

- **No changes to Next.js core**
    - Capacitor does not modify Next.js source code.
    - You can still run `npm run dev` / `npm run build` normally.
        
- **Extra files/config** are added for mobile packaging.
- Only thing inside Next.js that changes is:
    - `capacitor.config.ts` or `capacitor.config.json` created.
    - You may adjust `next.config.js` → `output: 'export'`, `distDir: 'out'`.

- So: Next.js project works fine as a normal web app even if Capacitor is present.

##### **2. What Files/Things Are Created by Capacitor**

When you run `npx cap init` and `npx cap add android`:

- **In root project:**
    - `capacitor.config.ts` (or `.json`) → Capacitor settings (appId, appName, webDir, server config).
    - `capacitor.config.json.backup` (sometimes).
    - Dependencies added in `package.json`:
        - `@capacitor/core`
        - `@capacitor/cli`
        - Optional: `@capacitor/android`, `@capacitor/ios`.
            
- **Native Project Folders:**
    - `/android` → full Android Studio project.
    - `/ios` (if added) → full Xcode project.
        
- **Build Artifacts:**
    - Capacitor copies Next.js build (`/out`) into `android/app/src/main/assets/public/`.
        
- **Misc:**
    - Gradle and Java/Kotlin files inside `/android` (native wrapper).

##### **3. How to Remove Capacitor Completely**

If you no longer want Capacitor in your Next.js project:

**Step A – Delete Native Folders**
- Delete:
    - `/android`
    - `/ios` (if exists)
        
**Step B – Remove Config Files**

- Delete:
    - `capacitor.config.ts` or `capacitor.config.json`
    - Backup files like `capacitor.config.json.backup`
        
**Step C – Uninstall Packages**

Run:
```bash
npm uninstall @capacitor/core @capacitor/cli @capacitor/android @capacitor/ios
```

**Step D – Clean Next.js Config**
- In `next.config.js`, you can keep `output: 'export'` (if you want static site) or remove it.    
- Remove any Capacitor-specific code you added.

**Step E – Verify**

- Run your app:    
    ```bash
    npm run dev
    npm run build
    npm run start
    ```
    
- It should work as a pure Next.js app again.
    
##### **4. Summary**

- Capacitor is a **wrapper** that adds `/android` and `/ios` projects.
- It **does not harm Next.js** – your web app still works normally.    
- To remove it, delete native folders, config files, and uninstall packages.


---
---

# Problem & Solution

When you use **Google Sign-In** inside a Capacitor Android app:

1. Clicking Google login opens the **external browser** instead of staying in the APK/WebView.
    
2. After logging in, the session is created **in the browser**, not inside your app.
    
3. As a result: your app stays **logged out**.
    

Reason:

- OAuth normally redirects to a URL after login. In a web app, it’s your site URL.
    
- In a native wrapper (Capacitor), the app must handle a **custom URL scheme** (deep link) so the browser can redirect back into the app.
    

---

# Solution: Deep Link + Code Exchange

## 1. Configure Supabase Redirect URL

- In **Supabase Dashboard → Authentication → URL Configuration**  
    Add your custom scheme redirect:
    

```
secuwrite://auth/callback
```

- This tells Supabase: after OAuth login, redirect the browser to this URL, which your app can handle.
    

---

## 2. Add Android Deep Link

Edit `android/app/src/main/AndroidManifest.xml` in `MainActivity`:

```xml
<intent-filter android:autoVerify="true">
  <action android:name="android.intent.action.VIEW" />
  <category android:name="android.intent.category.DEFAULT" />
  <category android:name="android.intent.category.BROWSABLE" />
  <data android:scheme="secuwrite" android:host="auth" android:path="/callback" />
</intent-filter>
```

Explanation:

- `android:scheme="secuwrite"` → your custom scheme
    
- `android:host="auth"` → must match Supabase redirect URL
    
- `android:path="/callback"` → final path for OAuth return
    

This ensures Android opens your app when a URL like `secuwrite://auth/callback?...` is accessed.

---

## 3. Listen for Deep Link in App

Install Capacitor App plugin:

```bash
npm i @capacitor/app
npx cap sync
```

In your app (e.g., `src/app/layout.js`), add a listener component:

```javascript
"use client";
import { useEffect } from "react";
import { App } from "@capacitor/app";
import { Capacitor } from "@capacitor/core";
import supabase from "@/lib/supabase";

export default function DeepLinkBootstrap({ children }) {
  useEffect(() => {
    if (!Capacitor.isNativePlatform()) return;

    const sub = App.addListener("appUrlOpen", async ({ url }) => {
      try {
        const u = new URL(url);
        if (u.hostname === "auth" && u.pathname === "/callback") {
          const code = u.searchParams.get("code");
          if (code) {
            await supabase.auth.exchangeCodeForSession({ authCode: code });
            // Session now valid inside app
          }
        }
      } catch (e) {
        console.error("auth deep link error", e);
      }
    });

    return () => sub?.remove();
  }, []);

  return children;
}
```

Wrap your app body once:

```jsx
<DeepLinkBootstrap>
  {children}
</DeepLinkBootstrap>
```

---

## 4. Start Google Sign-In Using Native Redirect

When initiating Google login in the app:

```javascript
import { Capacitor } from "@capacitor/core";

const signInWithGoogle = async () => {
  const redirectTo = Capacitor.isNativePlatform()
    ? "secuwrite://auth/callback"
    : `${window.location.origin}/auth/callback`;

  const { error } = await supabase.auth.signInWithOAuth({
    provider: "google",
    options: {
      redirectTo,
      queryParams: { access_type: "offline", prompt: "consent" },
      skipBrowserRedirect: false
    }
  });

  if (error) throw error;
  return { success: true };
};
```

Explanation:

- On native app → use **custom scheme**.
    
- On web → use normal URL.
    
- `skipBrowserRedirect: false` ensures browser opens for login.
    

---

## 5. Build and Test ⭐

```bash
npx next build --no-lint
npx cap copy android
cd android
.\gradlew assembleDebug # ⭐
adb install -r app\build\outputs\apk\debug\app-debug.apk
```

- Open app → start Google sign-in.
- Browser opens → user consents → browser redirects to `secuwrite://auth/callback?...`
- Capacitor listener intercepts URL → calls `exchangeCodeForSession()` → session is now valid in the WebView.
    

---

## 6. Important Notes

- Supabase client must have:
    

```javascript
auth: {
  detectSessionInUrl: true,
  persistSession: true
}
```

- `exchangeCodeForSession` stores session in WebView local storage.
    
- Ensure **scheme/host/path** match exactly in:
    
    - Supabase redirect URL
        
    - AndroidManifest intent-filter
        
    - App code (`DeepLinkBootstrap`)
        
- If mismatch → browser login works but app stays logged out.
    

---

✅ **Outcome**

- Google login works inside the app.
    
- User stays logged in without needing browser session.
    
- Hybrid: works offline + supports OAuth via deep link.
    
