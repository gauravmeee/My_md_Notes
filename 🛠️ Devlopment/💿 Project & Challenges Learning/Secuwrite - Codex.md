**What It Is**

`Secuwrite` is a client-heavy Next.js 15 journaling app with two content types: `Diary` and `Journal`. The product promise is “private writing with encryption,” and the codebase implements that as:

- Supabase auth for identity and cloud persistence
- Client-side encryption for cloud-stored entry content
- A separate app-lock layer for hiding/guarding diary and optionally journal content
- A hybrid storage model where new entries are often saved locally first, then optionally uploaded later

The root composition is in [layout.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/layout.js:103), where `ThemeProvider`, `AuthProvider`, and `LockProvider` wrap the whole app, and the global `Navbar` and `AuthModal` are always mounted. Auth state lives in [AuthContext.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/context/AuthContext.js:10), and lock state lives in [LockContext.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/context/LockContext.js:11).

**How The App Actually Works**

Entries are loaded and saved through two layers:

- Cloud CRUD and encryption in [database.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/database.js:76)
- Local-first/offline helpers in [localStorage.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/localStorage.js:5)

For cloud data, `database.js` encrypts `title` and `content` in the browser before writing to Supabase and decrypts after reading. The encryption key is managed in [encryption.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/encryption.js) and stored in the `user_encryption_keys` table from [create_user_encryption_keys.sql](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/supabase/migrations/create_user_encryption_keys.sql:1). Diary entries support both text and image modes; journal entries are rich HTML from Jodit.

The app’s UI flows are split by feature:
- Home recent entries: [HomeContent.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/components/HomeContent.js)
- Diary list/detail/new/edit/drafts: [diary/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/diary/page.js), [diary/[id]/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/diary/[id]/page.js), [diary/new/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/diary/new/page.js), [diary/edit/[id]/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/diary/edit/[id]/page.js), [diary/draft/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/diary/draft/page.js)
- Journal list/detail/new/edit/drafts: [journal/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/journal/page.js), [journal/[id]/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/journal/[id]/page.js), [journal/new/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/journal/new/page.js), [journal/edit/[id]/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/journal/edit/[id]/page.js), [journal/draft/page.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/journal/draft/page.js)

Locking is a second privacy layer, separate from encryption. The menu/UI is in [LockMenu.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/components/LockMenu.js) and [LockModal.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/components/LockModal.js). Preview blur happens with [LockOverlay.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/components/common/LockOverlay.js:8). Route blocking for detail/edit/draft pages is done client-side by [EntryLockProtection.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/components/EntryLockProtection.js:9). Lock settings are stored in `user_lock_settings`, defined in [create_user_lock_settings.sql](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/supabase/migrations/create_user_lock_settings.sql:1), and accessed through [lockService.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/lockService.js:54).

**Important Design Realities**

This is not a server-driven app. Most protection is enforced in client React code, not middleware or server components. Middleware in [middleware.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/middleware.js) only refreshes Supabase session and redirects `/auth` routes.

The strongest parts of the design:
- Clear feature separation between diary, journal, auth, lock, and storage
- Real client-side encryption before cloud persistence
- Good local draft support and hybrid local/cloud recovery
- RLS-backed tables for diary, journal, encryption keys, and lock settings

The riskiest parts:
- `Lock` is UI/client enforced, not a hard server-side access boundary
- Lock passwords are hashed with plain SHA-256 in [lockService.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/lockService.js:8), not a slow password hash
- The OTP flow is weak: `otp_verification` has permissive RLS in [create_otp_verification.sql](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/supabase/migrations/create_otp_verification.sql:1), and `send-simple` returns the OTP to the client even outside development in [send-simple/route.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/app/api/otp/send-simple/route.js:4)
- Supabase URL and anon key have hardcoded fallbacks in [supabase.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/supabase.js)
- There are signs of old/new encryption approaches coexisting, especially between [encryption.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/encryption.js) and [keyManagement.js](d:/Users/Gaurav/Desktop/@GAURAV/Projects/gkmeena-secuwrite/src/lib/keyManagement.js)

If you want, the next useful step is either:
1. a feature-by-feature architecture diagram in plain English, or
2. a code review of the biggest security and maintainability risks.

---

