
### `components / ConestsNotificationHandler.js`

---

```js
export default function ContestsNotificationHandler() {
  const { currentUser } = useAuth();
```

-  `const { currentUser } = useAuth();`
- Uses a custom hook `useAuth()` (probably from an AuthContext).
- It returns user-related info.
- We're **extracting `currentUser`** (i.e., the logged-in user).
    
---

```js
useEffect(() => {
  if (!currentUser) return;
```

This `useEffect` runs after the component mounts or when dependencies change. If `currentUser` is not available (i.e., user not logged in), it exits early.

```js
let timeoutIds = [];
```

 Declares an array to store timeout IDs. Useful for clearing them later if needed (e.g., when component unmounts).

```js
const checkNotificationSupport = () => {
  if (!('Notification' in window)) {
    toast.error("Your browser doesn't support notifications");
    return false;
  }
  return true;
};
```

 A function that checks if the browser supports the Notification API. If not, it shows a toast error and returns `false`. If supported, it returns `true`.

---

# Notification Permission

```js
// Request notification permission
const requestNotificationPermission = async () => {
  // Check if the browser supports notifications
  if (!checkNotificationSupport()) return false;
```
- The function first checks if the browser supports notifications using the `checkNotificationSupport` function. If not supported, it returns `false` and stops further execution.

```js
  try {
    // Request permission to show notifications
    const permission = await Notification.requestPermission();
```
- It then uses `Notification.requestPermission()` to request the user's permission to display notifications. This will open a prompt to the user asking if they allow notifications.

```js
    if (permission === 'granted') {
      // If permission is granted, show a success message
      toast.success("Notifications enabled successfully!");
      return true;
```
-  If the user allows notifications (permission is `granted`), it shows a success toast message and returns `true`, indicating that notifications were successfully enabled.

```js
    } else {
      // If permission is denied, show an error message
      toast.error("Notification permission denied");
      return false;
    }
```
- If the user denies the permission (permission is not `granted`), it shows an error toast message and returns `false`, indicating that notifications were not enabled.

```js
  } catch (error) {
    // If there's an error while requesting permission, log it and return false
    console.error('Error requesting notification permission:', error);
    return false;
  }
};
```
- If there is an error during the permission request process (e.g., if the browser fails to handle the request), it logs the error to the console and returns `false`, indicating the operation failed.
---

## Check Notification


```js
const checkNotifications = async () => {
  try {
    // If the currentUser is not available, exit early
    if (!currentUser) return;
    
    console.log('Checking for notifications...');
    
    // Fetch user preferences from the Firestore database using the currentUser's UID
    const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
    
    // If the document doesn't exist, exit early
    if (!userPrefsDoc.exists()) return;
    
    // Extract user data from the document
    const userData = userPrefsDoc.data();
    const notifications = userData.notifications || {};
    
    // Process each individual contest notification
    if (Object.keys(notifications).length > 0) {
      Object.entries(notifications).forEach(async ([contestId, data]) => {
        // Skip if notification is marked as disabled or is a platform notification
        if (data.disabled || (data.isPlatformNotification && !data.isTest)) return;
```
- The function first checks if `currentUser` is available. If not, it returns immediately.
- Fetches `userPreferences` from Firestore.    
- Loops over each notification.
- ❓**Why skip `isPlatformNotification && !isTest`?**  -> Because platform notifications might be global or managed differently. Only allow if marked as `isTest`.

**Regular Notfication Time Calculation** (Removed by me) 🔻 
```js
/*
        // Calculate the contest time and reminder time
        const contestTime = new Date(data.contestTime);
        const reminderTime = data.reminderTime;
        
        // Calculate the time when the notification should be shown
        const notificationTime = new Date(contestTime.getTime() - (reminderTime * 60 * 1000));
        const currentTime = new Date();
*/
```
Calculates the **exact time** the reminder should appear (`contestTime - reminderTime`), compares it with the current time.

**Test + Regular Notification Time Calculation** (Updated by me) ❇️
```js
		// Calculate the contest time and creation time
		const contestTime = new Date(data.contestTime);
		const createdAt = new Date(data.createdAt);

		// For test: calculate reminderTime in minutes such that notification fires 2 sec after creation
		const reminderTime = data.isTest
		  ? (contestTime.getTime() - (createdAt.getTime() + 2000)) / (60 * 1000)
		  : data.reminderTime;
		
		// Calculate the time when the notification should be shown
		const notificationTime = new Date(contestTime.getTime() - (reminderTime * 60 * 1000));
		
		const currentTime = new Date();

```
- Test mode: indirectly computes `reminderTime` from `createdAt + 2s`
- Real mode: uses actual `reminderTime` value

**Test Notifications:** (Removed by me)
```js
/*		
        // For test notifications, show immediately
        if (data.isTest) {
          console.log(`Test notification detected for ${contestId}, showing immediately`);
          
          // Send notification immediately
          await showNotification(
            'Test Contest Reminder',
            `${contestId.split('-')[1]} on ${contestId.split('-')[0]} starts in ${reminderTime} minutes! (TEST)`
          );
          
          // Immediately remove the notification from Firestore
          await removeNotificationImmediately(contestId);
          
          // Update local state to reflect the removal
          delete notifications[contestId];
          
          return;
        }
*/
```
- For test cases, show notification immediately.
- Delete from Firestore + local object to prevent duplicate.

**Regular Notification -Show Now**
```js       
        // For regular notifications, check if it's time to show
        if (notificationTime <= currentTime) {
          console.log(`Time to show notification for ${contestId}`);
          
          // Show the notification
          showNotification(
            'Contest Reminder',
            `${contestId.split('-')[1]} on ${contestId.split('-')[0]} starts in ${reminderTime} minutes!`
          );
          
          // Immediately remove the notification from Firestore
          await removeNotificationImmediately(contestId);
          
          // Update local state to reflect the removal
          notifications[contestId] = undefined;
        } 
```
- If it's already time, show the notification now.
- Cleanup to prevent future repeat.


**Schedule for Later**
```js
        else {
          // Schedule the notification for later if it's not yet time
          const timeUntilNotification = notificationTime.getTime() - currentTime.getTime();
          const timeDisplay = formatTimeUntilNotification(timeUntilNotification);
          
          console.log(`Scheduling notification for ${contestId} in ${timeDisplay} (${reminderTime} minutes before contest)`);
          
          // Set a timeout to show the notification at the scheduled time
          const timeoutId = setTimeout(async () => {
            const contestName = contestId.split('-')[1];
            const platform = contestId.split('-')[0];
            showNotification(
              'Contest Reminder',
              `${contestName} on ${platform} starts in ${reminderTime} minutes!`
            );
            
            // Immediately remove the notification from Firestore
            await removeNotificationImmediately(contestId);
          }, timeUntilNotification);
          
          // Store the timeout ID for cleanup
          timeoutIds.push(timeoutId);
        }
      });
    }
  } catch (error) {
    console.error('Error checking notifications:', error);
  }
};
```
- If it's **not time yet**, schedule it using `setTimeout()`.
- Show notification later.
- Delete after showing.
- Save timeout ID so it can be cancelled later if needed.

---

### Show Notification

```js
const showNotification = async (title, body) => {
  toast.info(body);
```
Shows toast notification with the given `body` using a toast library like `react-toastify`.

```js
  if (!checkNotificationSupport()) return;
```
Checks if browser supports Notification API. If not, exit early.

```js
  if (Notification.permission === 'granted') {
```
If permission is already granted, proceed to show browser notification.

```js
    try {
      if ('serviceWorker' in navigator) {
        const registration = await navigator.serviceWorker.ready;
        await registration.showNotification(title, {
          body,
          icon: '/assets/contests/default.png', // ❓ why default logo
          tag: 'contest-reminder',
          renotify: true,
          data: { type: 'contest', url: '/contests' } // Add link of contest in it ❗
        });
      }
    } catch (error) {
      console.error('Error showing notification:', error);
    }
```
Uses service worker to show a browser notification

- `icon`: icon shown in the notification
- `tag`: avoids duplicate notifications
- `renotify`: allows replacing same tag notification
- `data`: custom metadata
    
```js
  } else if (Notification.permission !== 'denied') {
    const granted = await requestNotificationPermission();
    if (granted) {
      showNotification(title, body);
    }
  }
};
```
If permission is not denied, ask for it  
If granted, retry the notification by calling `showNotification` recursively

#### Notification Types & Behaviors

| Type                                           | Show Immediately | Schedule for Later | Skipped | When Triggered                         | Removed After Trigger | Use Case                           |
| ---------------------------------------------- | ---------------- | ------------------ | ------- | -------------------------------------- | --------------------- | ---------------------------------- |
| `isTest === true`                              | ✅ Yes            | ❌ No               | ❌ No    | Instantly                              | ✅ Immediately         | For developers/testers             |
| `isPlatformNotification === true`and `!isTest` | ❌ No             | ❌ No               | ✅ Yes   | Not triggered                          | ❌ Not applicable      | Global notices; handled separately |
| Regular — time reached                         | ✅ Yes            | ❌ No               | ❌ No    | When `notificationTime <= currentTime` | ✅ Immediately         | User-scheduled contest reminders   |
| Regular — schedule for later                   | ❌ No             | ✅ Yes              | ❌ No    | `setTimeout()` till time               | ✅ After timeout       | Reminders that are due in future   |

How the Code Handles It
- **Test**: Executes notification & removal logic immediately.
- **Platform**: Completely skipped to prevent redundancy.
- **Regular (time passed)**: Shown now, removed.
- **Regular (not due)**: Scheduled with `setTimeout`, then shown & removed.
    
---

### Disable Notification (Not in use currently ❗)

```js
/* Removed by me 🔻
const disableNotification = async (contestId) => {
  try {
    console.log(`Removing notification for ${contestId}`);
*/
```
Logs the contest ID for which notification is being removed.

```js
/*  Removed by me 🔻
    const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
    if (!userPrefsDoc.exists()) return;
*/
```
Fetches user's notification preferences from Firestore.  
If not found, exit.

```js
/*  Removed by me 🔻
    const userData = userPrefsDoc.data();
    const notifications = userData.notifications || {};
*/
```
Extracts existing notifications from user data.  
If none, initialize as empty object.

```js
/*  Removed by me 🔻
    if (notifications[contestId]) {
      const newNotifications = { ...notifications };
      delete newNotifications[contestId];
*/
```
If a notification exists for `contestId`, create a copy and delete that entry.

```js
/*  Removed by me 🔻
      await setDoc(doc(db, 'userPreferences', currentUser.uid), {
        notifications: newNotifications,
        lastUpdated: new Date().toISOString()
      }, { merge: true });
*/
```
- **`setDoc`**  - A Firestore function that **writes data** to a document.  
If the document exists, it replaces it unless `{ merge: true }` is used.
- Updates Firestore document with the modified notification object  
Also sets `lastUpdated` timestamp  
Uses `{ merge: true }` to avoid overwriting other fields

**Better Way to Directly /Delete Notification from Firestore** (Updated by me ❇️)
```js
import { doc, updateDoc, deleteField } from "firebase/firestore";

await updateDoc(doc(db, 'userPreferences', currentUser.uid), {
  [`notifications.${contestId}`]: deleteField()
});
```
- Firestore **does not support deleting a nested field (like `notifications.contestId`) directly** using bracket syntax like `[contestId]`but you can use to delete a specific nested field directly `FieldValue.delete()`.
- ✅ No need to fetch all notifications
- ✅ Less read & write cost
- ✅ Cleaner and faster

```js
      console.log(`Notification for ${contestId} removed successfully`);
    }
  } catch (error) {
    console.error('Error removing notification:', error);
  }
};
```
Logs success or handles and logs any errors during the process.

---

### Cleanup Test Notifications (Why ❓)


```js
const cleanupTestNotifications = async () => {
```
Defines an async function to delete all test-type notifications.

```js
console.log('Cleaning up test notifications');
```
Logs start of cleanup process.

```js
const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
if (!userPrefsDoc.exists()) return;
```
Fetches the user's preferences doc from Firestore. If not present, exits early.

```js
const userData = userPrefsDoc.data();
const notifications = userData.notifications || {};
```
Extracts notifications from document, or initializes as empty object if undefined.

```js
const newNotifications = { ...notifications };
let removedCount = 0; // Why ❓
```
Creates a copy of existing notifications. Initializes a counter for removed entries.

```js
Object.keys(newNotifications).forEach(contestId => {
  if (newNotifications[contestId].isTest) {
    delete newNotifications[contestId];
    removedCount++;
  }
});
```
Loops through all notification entries. If a notification is a test, deletes it and increments counter.

```js
if (removedCount > 0) {
  await setDoc(doc(db, 'userPreferences', currentUser.uid), {
    notifications: newNotifications,
    lastUpdated: new Date().toISOString()
  }, { merge: true });
```
If any test notifications were removed, updates the Firestore document with new list and updates timestamp.

```js
console.log(`Removed ${removedCount} test notifications successfully`);
```
Logs how many test notifications were removed.

```js
} catch (error) {
  console.error('Error cleaning up test notifications:', error);
}
```
Handles and logs any errors during the cleanup process.

---

### Cleanup Expired Notification

```js
const  = async () => {
```
Defines an async function to remove expired notifications from Firestore.

```js
console.log('Cleaning up expired notifications');
```
Logs the start of cleanup.

```js
const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
if (!userPrefsDoc.exists()) return;
```
Fetches the current user's preferences document. If it doesn't exist, exits early.

```js
const userData = userPrefsDoc.data();
const notifications = userData.notifications || {};
const currentTime = new Date();
```
Extracts notifications. If none exist, uses an empty object. Also gets the current time.

```js
const newNotifications = { ...notifications };
let removedCount = 0;
```
Creates a copy of notifications and initializes a counter for removed items.

```js
Object.entries(newNotifications).forEach(([contestId, data]) => {
  const contestTime = new Date(data.contestTime);
  const reminderTime = data.reminderTime;
  const notificationTime = new Date(contestTime.getTime() - (reminderTime * 60 * 1000));
```
Iterates through each notification and calculates when it should have triggered using `contestTime - reminderTime`.

```js
  if (notificationTime <= currentTime) {
    delete newNotifications[contestId];
    removedCount++;
    console.log(`Removed expired notification for ${contestId}`);
  }
});
```
If `notificationTime` has passed, removes that notification and logs it.

```js
if (removedCount > 0) {
  await setDoc(doc(db, 'userPreferences', currentUser.uid), {
    notifications: newNotifications,
    lastUpdated: new Date().toISOString()
  }, { merge: true });
```
If any were removed, updates Firestore with the new notifications list and updates the timestamp.

```js
  console.log(`Removed ${removedCount} expired notifications successfully`);
}
```
Logs how many notifications were removed.

```js
} catch (error) {
  console.error('Error cleaning up expired notifications:', error);
}
```
Handles and logs any error in the process.


---

### Cleanup Disabled Notification

```js
const cleanupDisabledNotifications = async () => {
```

Defines an asynchronous function to remove disabled notifications from Firestore.

```js
console.log('Cleaning up disabled notifications');
```

Logs the start of the cleanup process.

```js
const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
if (!userPrefsDoc.exists()) return;
```

Fetches the user's `userPreferences` document from Firestore. If it doesn't exist, exits the function early.

```js
const userData = userPrefsDoc.data();
const notifications = userData.notifications || {};
```

Extracts the `notifications` object from the document. If it doesn't exist, uses an empty object.

```js
const newNotifications = { ...notifications };
let removedCount = 0;
```

Creates a shallow copy of the notifications to edit and initializes a counter to track how many are removed.

```js
Object.entries(newNotifications).forEach(([contestId, data]) => {
  if (data.disabled) {
    delete newNotifications[contestId];
    removedCount++;
    console.log(`Removed disabled notification for ${contestId}`);
  }
});
```

Iterates through each notification. If the `disabled` field is `true`, it deletes that entry and logs its removal.

```js
if (removedCount > 0) {
  await setDoc(doc(db, 'userPreferences', currentUser.uid), {
    notifications: newNotifications,
    lastUpdated: new Date().toISOString()
  }, { merge: true });
```

If any entries were removed, it updates the Firestore document with the new notifications object and updates `lastUpdated` timestamp.

```js
  console.log(`Removed ${removedCount} disabled notifications successfully`);
}
```

Logs the number of disabled notifications removed.

```js
} catch (error) {
  console.error('Error cleaning up disabled notifications:', error);
}
```

Catches and logs any errors during the process.

---

### Remove Notification Immediately

```js
const removeNotificationImmediately = async (contestId) => {
```
Defines an async function to remove a specific notification from Firestore based on `contestId`.

```js
console.log(`Immediately removing notification for ${contestId}`);
```
Logs the intent to remove a specific notification.

```js
const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));
if (!userPrefsDoc.exists()) {
  console.log(`No user preferences found for ${currentUser.uid}`);
  return;
}
```
Fetches the `userPreferences` document for the current user. If it doesn't exist, logs and exits.

```js
const userData = userPrefsDoc.data();
const notifications = userData.notifications || {};
```
Retrieves user data and initializes `notifications` (default to `{}` if not found).

```js
if (notifications[contestId]) {
  const newNotifications = { ...notifications };
  delete newNotifications[contestId];
```
If a notification exists for `contestId`, creates a copy and deletes the target notification.

```js
  await setDoc(doc(db, 'userPreferences', currentUser.uid), {
    ...userData,
    notifications: newNotifications,
    lastUpdated: new Date().toISOString()
  }, { merge: true });
```
Updates Firestore with the updated `notifications` object and adds a `lastUpdated` timestamp.

```js
  console.log(`Notification for ${contestId} removed immediately`);
```
Logs successful removal.

```js
  if (typeof window !== 'undefined') {
    window.dispatchEvent(new CustomEvent('notificationRemoved', { 
      detail: { contestId } 
    }));
  }
```
Triggers a browser event `notificationRemoved` so other parts of the UI can react and refresh.

```js
} else {
  console.log(`Notification for ${contestId} not found in user preferences`);
}
```

If notification was not found in user data, logs the message.

```js
} catch (error) {
  console.error(`Error removing notification for ${contestId}:`, error);
}
```

Catches and logs any runtime errors during the operation.

---

### Notification Management Effect:

```js
// Initial check
checkNotifications();
```

Calls `checkNotifications()` once when the component mounts to handle any immediate notification logic (like displaying or scheduling reminders).

```js
// Clean up notifications on component mount
cleanupTestNotifications();
cleanupExpiredNotifications();
cleanupDisabledNotifications();
```

On mount, runs cleanup functions to remove:

- `test` notifications (`isTest` flag)
- `expired` notifications (notification time already passed)
- `disabled` notifications (`disabled: true`)
    

```js
// Check every minute for new notifications and clean up expired ones
const intervalId = setInterval(() => {
  checkNotifications();
  cleanupExpiredNotifications();
  cleanupDisabledNotifications();
}, 60000);
```

Sets a `setInterval` that:

- Re-checks notifications
- Cleans up expired and disabled notifications every **60 seconds** (`60000ms`), keeping data fresh.
    

```js
return () => {
  clearInterval(intervalId);
  timeoutIds.forEach(id => clearTimeout(id));
};
```

Cleanup function when component unmounts:

- Stops the `setInterval` loop
    
- Clears all scheduled `setTimeout`s (used for reminder alarms)
    

```js
}, [currentUser]);
```

Effect is re-run whenever `currentUser` changes.

```js
return null;
```

No UI is rendered—this is a logic-only React component or hook.


---

#### Different Cleanup and Disable Function.

`disableNotification(contestId)`
**Purpose:**  
Marks a specific notification as **disabled** without deleting it.  
Used when you want to turn off a reminder but keep its data.

`cleanupTestNotifications()`
**Purpose:**  
Deletes all notifications that are **marked as test** (`isTest: true`).  
Used to clean up temporary or debug/test data.

`cleanupExpiredNotifications()`
**Purpose:**  
Deletes notifications where the **scheduled notification time has already passed**.  
Prevents showing or holding outdated reminders.

`cleanupDisabledNotifications()`
**Purpose:**  
Deletes notifications that were **disabled earlier** (`disabled: true`).  
Cleans up data that is no longer active.

`removeNotificationImmediately(contestId)`
**Purpose:**  
**Immediately deletes** a single notification from Firestore by `contestId`.  
Used when a user manually removes/cancels a notification.

### Summary Table:

| Function                        | Deletes? | Scope        | Based on          |
| ------------------------------- | -------- | ------------ | ----------------- |
| `disableNotification`           | ❌        | Single       | Marks as disabled |
| `cleanupTestNotifications`      | ✅        | All `isTest` | Test flag         |
| `cleanupExpiredNotifications`   | ✅        | All expired  | Time passed       |
| `cleanupDisabledNotifications`  | ✅        | All disabled | Disabled flag     |
| `removeNotificationImmediately` | ✅        | Single       | Manual delete     |


---
### Changes:
-  Why To calculate `notificationTime` Every time, It should be stored in Firebase.  ❓
- Why to use `disableNotification`, `cleanupDisabledNotification`, and `cleanupTestNotifications`
- Only use `removeNotificationImmediately` to Delete Notification when received or cancel and, `cleanupExpiredNotifications` to Delete Expired.

---

### Updated

```js
'use client';

  

import { useEffect } from 'react';

import { useAuth } from '@/lib/AuthContext';

import { db } from '@/lib/firebase';

import { doc, getDoc, setDoc, updateDoc, deleteField } from 'firebase/firestore';

import { toast } from 'sonner';

  

// Add the time formatting function

const formatTimeUntilNotification = (timeInMilliseconds) => {

  const seconds = Math.floor(timeInMilliseconds / 1000);

  const minutes = Math.floor(seconds / 60);

  const hours = Math.floor(minutes / 60);

  const days = Math.floor(hours / 24);

  

  if (days > 0) {

    return `${days}d ${hours % 24}h`;

  } else if (hours > 0) {

    return `${hours}h ${minutes % 60}m`;

  } else if (minutes > 0) {

    return `${minutes}m`;

  } else {

    return `${seconds}s`;

  }

};

  

export default function ContestsNotificationHandler() {

  const { currentUser } = useAuth();

  

  useEffect(() => {

    if (!currentUser) return;

  

    let timeoutIds = [];

  

    // Check if browser supports notifications

    const checkNotificationSupport = () => {

      if (!('Notification' in window)) {

        toast.error("Your browser doesn't support notifications");

        return false;

      }

      return true;

    };

  

    // Request notification permission

    const requestNotificationPermission = async () => {

      if (!checkNotificationSupport()) return false;

      try {

        const permission = await Notification.requestPermission();

        if (permission === 'granted') {

          toast.success("Notifications enabled successfully!");

          return true;

        } else {

          toast.error("Notification permission denied");

          return false;

        }

      } catch (error) {

        console.error('Error requesting notification permission:', error);

        return false;

      }

    };

  

    const checkNotifications = async () => {

      try {

        if (!currentUser) return;

        console.log('Checking for notifications...');

        const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));

        if (!userPrefsDoc.exists()) return;

        const userData = userPrefsDoc.data();

        const notifications = userData.notifications || {};

        const currentTime = new Date();

        // Process individual contest notifications

        if (Object.keys(notifications).length > 0) {

          Object.entries(notifications).forEach(async ([contestId, data]) => {

            // Skip if it's a platform notification that isn't a test

            if (data.isPlatformNotification && !data.isTest) return;

  

            // Calculate the contest time and creation time

            const contestTime = new Date(data.contestTime);

            const createdAt = new Date(data.createdAt);

  

            // For test: calculate reminderTime in minutes such that notification fires 2 sec after creation

            const reminderTime = data.isTest

              ? (contestTime.getTime() - (createdAt.getTime() + 2000)) / (60 * 1000)

              : data.reminderTime;

            // Calculate the time when the notification should be shown

            const notificationTime = new Date(contestTime.getTime() - (reminderTime * 60 * 1000));

            // For test notifications, show immediately if within 2 seconds of creation

            if (data.isTest && currentTime.getTime() - createdAt.getTime() <= 2000) {

              console.log(`Test notification detected for ${contestId}, showing immediately`);

              await showNotification(

                'Test Contest Reminder',

                `${contestId.split('-')[1]} on ${contestId.split('-')[0]} starts in ${Math.round(reminderTime)} minutes! (TEST)`

              );

              await removeNotificationImmediately(contestId);

              return;

            }

            // For regular notifications, check if it's time to show

            if (notificationTime <= currentTime) {

              console.log(`Time to show notification for ${contestId}`);

              showNotification(

                'Contest Reminder',

                `${contestId.split('-')[1]} on ${contestId.split('-')[0]} starts in ${Math.round(reminderTime)} minutes!`

              );

              await removeNotificationImmediately(contestId);

            } else {

              // Schedule the notification

              const timeUntilNotification = notificationTime.getTime() - currentTime.getTime();

              const timeDisplay = formatTimeUntilNotification(timeUntilNotification);

              console.log(`Scheduling notification for ${contestId} in ${timeDisplay} (${Math.round(reminderTime)} minutes before contest)`);

              const timeoutId = setTimeout(async () => {

                const contestName = contestId.split('-')[1];

                const platform = contestId.split('-')[0];

                showNotification(

                  'Contest Reminder',

                  `${contestName} on ${platform} starts in ${Math.round(reminderTime)} minutes!`

                );

                await removeNotificationImmediately(contestId);

              }, timeUntilNotification);

              timeoutIds.push(timeoutId);

            }

          });

        }

      } catch (error) {

        console.error('Error checking notifications:', error);

      }

    };

  

    const showNotification = async (title, body) => {

      // Always show toast notification

      toast.info(body);

  

      // Handle browser notification

      if (!checkNotificationSupport()) return;

  

      if (Notification.permission === 'granted') {

        try {

          if ('serviceWorker' in navigator) {

            const registration = await navigator.serviceWorker.ready;

            await registration.showNotification(title, {

              body,

              icon: '/assets/contests/default.png',

              tag: 'contest-reminder',

              renotify: true,

              data: { type: 'contest', url: '/contests' }

            });

          }

        } catch (error) {

          console.error('Error showing notification:', error);

        }

      } else if (Notification.permission !== 'denied') {

        const granted = await requestNotificationPermission();

        if (granted) {

          showNotification(title, body); // Retry showing notification if permission granted

        }

      }

    };

  

    // Function to immediately remove a notification from Firestore

    const removeNotificationImmediately = async (contestId) => {

      try {

        console.log(`Immediately removing notification for ${contestId}`);

        // Directly delete the notification field from Firestore

        await updateDoc(doc(db, 'userPreferences', currentUser.uid), {

          [`notifications.${contestId}`]: deleteField(),

          lastUpdated: new Date().toISOString()

        });

        console.log(`Notification for ${contestId} removed immediately`);

        // Force a refresh of the notifications in the UI

        if (typeof window !== 'undefined') {

          window.dispatchEvent(new CustomEvent('notificationRemoved', {

            detail: { contestId }

          }));

        }

      } catch (error) {

        console.error(`Error removing notification for ${contestId}:`, error);

      }

    };

  

    // Function to clean up expired notifications

    const cleanupExpiredNotifications = async () => {

      try {

        console.log('Cleaning up expired notifications');

        const userPrefsDoc = await getDoc(doc(db, 'userPreferences', currentUser.uid));

        if (!userPrefsDoc.exists()) return;

  

        const userData = userPrefsDoc.data();

        const notifications = userData.notifications || {};

        const currentTime = new Date();

        // Find all expired notifications and test notifications

        const fieldsToDelete = {};

        let removedCount = 0;

        Object.entries(notifications).forEach(([contestId, data]) => {

          // Remove if it's a test notification or if notification time has passed

          if (data.isTest) {

            fieldsToDelete[`notifications.${contestId}`] = deleteField();

            removedCount++;

            console.log(`Marked test notification for removal: ${contestId}`);

            return;

          }

  

          if (new Date(data.notificationTime) <= currentTime) {

            fieldsToDelete[`notifications.${contestId}`] = deleteField();

            removedCount++;

            console.log(`Marked expired notification for removal: ${contestId}`);

          }

        });

        if (removedCount > 0) {

          await updateDoc(doc(db, 'userPreferences', currentUser.uid), {

            ...fieldsToDelete,

            lastUpdated: new Date().toISOString()

          });

          console.log(`Removed ${removedCount} notifications successfully`);

        }

      } catch (error) {

        console.error('Error cleaning up expired notifications:', error);

      }

    };

  

    // Initial check

    checkNotifications();

    // Clean up expired notifications on component mount

    cleanupExpiredNotifications();

  

    // Check every minute for new notifications and clean up expired ones

    const intervalId = setInterval(() => {

      checkNotifications();

      cleanupExpiredNotifications();

    }, 60000);

  

    return () => {

      clearInterval(intervalId);

      timeoutIds.forEach(id => clearTimeout(id));

    };

  }, [currentUser]);

  

  return null;

}
```

---

### Updated `ShowNotification()`

### Purpose:

This function shows a **browser notification** or a **toast** depending on the user's **tab visibility** and whether it's a **test notification**.

### Step-by-step Breakdown:

```js
const isTabVisible = document.visibilityState === 'visible';
```
- Checks if the browser tab is currently active.
    
```js
if (isTest || isTabVisible) {
  toast.info(body);
}
```
- If it’s a test OR the tab is active → show a toast message using `toast.info`.
    

```js
if (!isTabVisible || isTest) {
```
- If tab is **not visible** or it’s a **test** → proceed to show browser notification.

```js
if (!checkNotificationSupport()) return;
```
- Check if browser supports notifications; if not, return.
    

```js
if (Notification.permission === 'granted') {
```
- If user already allowed notifications:
    
```js
const registration = await navigator.serviceWorker.ready;
await registration.showNotification(title, {
  body,
  icon: '/assets/contests/default.png',
  tag: isTest ? `test-${Date.now()}` : 'contest-reminder',
  renotify: true,
  requireInteraction: isTest,
  silent: !isTest,
  data: { type: 'contest', url: '/contests', isTest }
});
```

- Use the **Service Worker** to display a **persistent browser notification** with:
    - `title`: Title of the notification
    - `body`: Main content
    - `icon`: Image for the notification
    - `tag`: Unique if test (to avoid duplication)
    - `renotify`: If true, notify again even if a similar notification is already shown
    - `requireInteraction`: Keeps the notification until the user acts on it (only for tests)
    - `silent`: Don't play sound unless it's a test
    - `data`: Additional data (can be read when notification is clicked)

```js
} else if (Notification.permission !== 'denied') {
```
- If user hasn't **denied** permission:
    

```js
const granted = await requestNotificationPermission();
if (granted) {
  showNotification(title, body, isTest);
}
```
- Ask for permission and retry showing notification if permission is granted.
    
### ⏳ Summary of Behavior

| Type                     | Same Tab (Visible) | Different Tab | Tab Closed / Browser Closed |
| ------------------------ | ------------------ | ------------- | --------------------------- |
| **Test Notification**    | Toast + Push       | Push          | ✅ Works with Service Worker |
| **Regular Notification** | Toast only         | Push          | ✅ Works with Service Worker |

Use `true` as the **third argument** to mark it as a **test notification**:
```js
await showNotification(
  'Test Contest Reminder',
  `${contestId.split('-')[1]} on ${contestId.split('-')[0]} starts in ${Math.round(reminderTime)} minutes! (TEST)`,
  true // isTest = true
);
```
Without `true`, the notification will behave like a normal one, and:
- Won’t persist until interaction (`requireInteraction: false`)
- Won’t make sound (`silent: true`)
- May not trigger if tab is visible

---

# Doubt ❗❓

##### why the two file contain to things same

### 1. **Notification Handler (frontend)**

Used when **your app is open** and you manually trigger a notification.

**Example:**

```js
// User is on the site and contest starts now
showNotification('Contest Started!', {
  icon: '/assets/contests/codeforces.png',
  badge: '/assets/contests/default.png',
  ...
});
```

### 2. **firebase-messaging-sw.js (Service Worker)**

Used when app is **closed or in background**. Firebase triggers it via push.

**Example:**

```js
// You sent a push from server, user receives it when tab is closed
self.addEventListener('push', (event) => {
  // here payload comes from FCM
  showNotification(payload.notification.title, {
    icon: '/assets/contests/codeforces.png',
    badge: '/assets/contests/default.png',
    ...
  });
});
```

### Why both?

- App open → **Notification Handler**
    
- App closed → **firebase-messaging-sw.js**
    

Each case needs to show notification **independently**, so both must define how it looks.

---

### Summary

|File|Purpose|Trigger|
|---|---|---|
|`Notification Handler`|Manually shows notification|Inside app (foreground)|
|`firebase-messaging-sw.js`|Shows notification from Firebase push|In background (via FCM)|

So yes, they look similar, but serve **different use-cases**: one for **manual/local**, the other for **push/Firebase**.


```
{

          body: Hello,

          icon: `/assets/contests/${platform}.png`,

          badge: '/assets/contests/badge.png',

          tag: 'contest-reminder',

          data: {

            ...data.data,

            platform: platform,

            timestamp: Date.now()

          },
```