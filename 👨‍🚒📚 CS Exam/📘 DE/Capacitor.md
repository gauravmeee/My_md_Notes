
I'll set up Capacitor for Android, add the SQLite plugin, and scaffold a cross-platform storage service. Then I'll configure the app to run via a dev server in Android during development and allow a production remote URL. Proceeding to install dependencies and initialize the Android project.

[1 tool called]

I'll install Capacitor and initialize Android in your project root, then proceed to the SQLite plugin.

[1 tool called]

I initialized Capacitor. Next I'll add the Android platform and install the SQLite plugin. Then I'll generate a basic config and scaffold a storage service with a web fallback.

[1 tool called]

I added Capacitor and the Android platform. Next, I'll install the SQLite plugin and create the config and storage service, then update scripts.

[2 tools called]

I'll check the installed Capacitor version to choose the correct SQLite plugin and retry the install with compatible flags.

[2 tools called]

I'll look up the current Capacitor and SQLite plugin versions to ensure compatibility with your React/Next setup, then install with peer-deps flags to avoid resolution issues.

[1 tool called]

I’m going to scan for existing Capacitor files and Android project, then install required Capacitor packages and add Android. I’ll also check for localStorage usage to plan the SQLite service integration.

[3 tools called]

I'll open `src/lib/localStorage.js` to see how storage is currently abstracted, then I'll install Android and the SQLite plugin with peer-deps flags, add the Capacitor config, and scaffold a storage service.

[3 tools called]

I'll check that the Android project and Capacitor config exist, then add a Capacitor config, npm scripts, and scaffold a SQLite storage service with a web fallback. I'll update the TODOs as I finish each step.

[1 tool called]

I'll install Capacitor core/CLI and Android, then add the Capacitor config and a cross-platform storage service. After that, I'll sync the Android project.

[10 tools called]

- I initialized Capacitor, added Android, installed the SQLite plugin, and wired a cross-platform storage layer. Now I’ll show you how to run it.

### What you can do next
- **Dev (emulator/device via Next server)**:
  1. Start Next: `npm run dev`
  2. In `capacitor.config.ts`, uncomment `server.url` and set it to your dev URL (Android emulator: `http://10.0.2.2:3000`).
  3. Sync and open Android Studio:
     - `npm run cap:sync`
     - `npm run android`
  4. Run on emulator/device from Android Studio.

- **Prod (bundled PWA in APK)**:
  1. Build Next to `out` (you currently use Next 15; use `next export` or PWA build flow if applicable). If you need static export, add a script or adapt build to output to `out`.
  2. Ensure `capacitor.config.ts` has no `server.url` (use bundled `webDir: 'out'`).
  3. `npm run cap:sync` then `npm run android`.
  4. Build a release APK/AAB in Android Studio.

### Changes made
- Added `capacitor.config.ts` with `webDir: 'out'`, Android scheme, and SQLite plugin config.
- Installed Capacitor core/CLI/Android and the community SQLite plugin.
- Created `src/lib/sqliteService.js` providing:
  - `openDatabase`, `setItem`, `getItem`, `removeItem`
  - Entry APIs: `saveEntry`, `getEntries`, `updateEntry`, `deleteEntry`, `deleteManyEntries`
  - Falls back to `localStorage` on web.
- Updated `src/lib/localStorage.js` to use SQLite service under the hood with async functions, keeping the same external API shape for callers.
- Added scripts to `package.json`:
  - `cap:sync`, `android`, `android:copy`

### Notes
- If using the Android emulator, use `http://10.0.2.2:3000` for the dev server.
- Supabase usage remains unchanged; cloud sync continues to work.
- For static export, ensure your Next build outputs to `out` or adjust `webDir` accordingly.

All tasks are complete.