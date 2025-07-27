
# [Push Notifications with Service worker](https://youtu.be/oDIYl3G613E) 
>Notes by NotebookLM
### Project Structure

The basic project structure consists of three files:

- **`index.html`**: The main HTML file for your web application.
- **`script.js`** (or your main JavaScript file): Contains the logic for checking API support, registering the service worker, and requesting notification permission.
- **`sw.js`** (service worker file): This JavaScript file runs in the background and is responsible for listening for push events and displaying notifications.

### Code Implementation

#### 1. `index.html`

This file sets up the basic webpage and includes your main JavaScript file. It also contains a button that users can click to enable notifications, following best user experience practices.

```jsx
<!DOCTYPE html>
<html>
<head>
    <title>Push Notifications Example</title>
</head>
<body>
    <h1>Push Notifications Example</h1>
    <!-- A button to prompt the user for notification permission -->
    <!-- The requestNotificationPermission function will be called on click -->
    <button onclick="requestNotificationPermission()" id="enableNotifications">Enable Notifications</button>
    <!-- Include your main JavaScript file -->
    <script src="script.js"></script>
</body>
</html>
```

#### 2. `script.js` (Main JavaScript File)

This file orchestrates the setup, including checking for API support, registering the service worker, and handling notification permission requests.

```jsx
// Function to check for necessary API support (Service Worker and Notification)
async function checkApiSupport() {
    // Check if 'serviceWorker' is present in the Navigator object
    if (!('serviceWorker' in navigator)) {
        throw new Error("Service Worker is not supported in this browser.");
    }
    // Check if 'Notification' API is present in the window object
    if (!('Notification' in window)) {
        throw new Error("Notification API is not supported in this browser.");
    }
}

// Function to register the Service Worker file
async function registerServiceWorker() {
    console.log("Attempting to register service worker...");
    // The navigator.serviceWorker.register() method registers the 'sw.js' file
    const registration = await navigator.serviceWorker.register('sw.js');
    console.log("Service Worker registered successfully:", registration);
    return registration; // Returns the ServiceWorkerRegistration instance
}

// Function to request notification permission from the user
// This should ideally be called by a user action, like a button click, for better UX
async function requestNotificationPermission() {
    try {
        // Ensure Notification API is supported before attempting to request permission
        if (!('Notification' in window)) {
            console.warn("Notification API not supported. Cannot request permission.");
            return;
        }

        // Use the Notification API's requestPermission() method to show a permission pop-up
        const permissionResult = await Notification.requestPermission();
        console.log("Notification permission status:", permissionResult);

        // If permission is not 'granted', log an error or inform the user
        if (permissionResult !== 'granted') {
            console.error("Notification permission was not granted. Current state:", Notification.permission);
            // For 'denied' status, the user must reset permissions manually from browser settings
        } else {
            console.log("Notification permission granted!");
            // Once granted, you might want to hide the "Enable Notifications" button
            const enableButton = document.getElementById('enableNotifications');
            if (enableButton) {
                enableButton.style.display = 'none';
            }
            // At this point, you would typically subscribe the user to a Push Service.
            // This part is covered in a follow-up video according to the source.
        }
    } catch (error) {
        console.error("Error during notification permission request:", error);
    }
}

// Main asynchronous function to initialise the application setup
async function main() {
    try {
        // Step 1: Check for Service Worker and Notification API support
        await checkApiSupport();
        console.log("Service Worker and Notification APIs are supported.");

        // Step 2: Register the service worker
        const registration = await registerServiceWorker();

        // Step 3: Demonstrate showing a notification via the registered service worker
        // This confirms that the service worker is ready to display notifications.
        // Note: Actual push notifications come from a server via the service worker.
        // This is a client-side triggered test notification.
        console.log("Attempting to show a test notification via Service Worker registration...");
        await registration.showNotification('Hello World from SW!', {
            body: 'This is a test notification generated by script.js through the service worker registration.',
            // You can also add an icon, vibration patterns, and other options here.
            // icon: '/path/to/your/icon.png',
            // vibrate:
        });
        console.log("Test notification displayed.");

        // Step 4: Manage the visibility of the "Enable Notifications" button
        const enableButton = document.getElementById('enableNotifications');
        if (enableButton) {
            const currentPermission = Notification.permission; // Get current permission state
            if (currentPermission === 'granted') {
                enableButton.style.display = 'none'; // Hide if already granted
            } else if (currentPermission === 'denied') {
                enableButton.disabled = true;
                enableButton.textContent = 'Notifications Blocked (Reset in Browser Settings)';
                console.warn("Notification permission is 'denied'. User must reset manually.");
            } else {
                enableButton.style.display = 'block'; // Show if 'default' (prompt needed)
            }
        }
    } catch (error) {
        console.error("Application initialization failed:", error);
        // You might want to update the UI to inform the user about the error.
    }
}

// Call the main function to start the application setup when the script loads
main();

// Make the requestNotificationPermission function globally accessible for the button's onclick attribute
window.requestNotificationPermission = requestNotificationPermission;
```

#### 3. `sw.js` (Service Worker File)

This file is initially very simple, primarily for confirming its registration. Future logic for handling server-pushed messages would reside here.

```jsx
// This console log statement confirms that the service worker file has been loaded and registered.
console.log('Service Worker file loaded!');

// In a follow-up video, this file would contain logic to listen for 'push' events
// from a server and then display notifications using the Notification API.

/*
Example (future implementation mentioned in source):
self.addEventListener('push', (event) => {
    // A push event arrives from the server
    const data = event.data.json(); // Process the push message data
    console.log('Push received:', data);

    // Display a notification using the Notification API
    self.registration.showNotification(data.title, {
        body: data.body,
        icon: data.icon // Icon and other options can be included
    });
});
*/
```

### Key Concepts and Flow

- **Push Notifications vs. Local Notifications**: Push notifications originate from a server (e.g., for new emails or flight delays) and can be received even if the app or website is not open, drawing the user back. Local notifications are triggered while actively using an app and are generally considered bad for user experience (UX).
- **Required APIs**:
    - **Service Worker API**: A script that runs in the background, separate from the main browser thread. It handles events from the backend without blocking the main thread. It is central to enabling push notifications.
    - **Notification API**: Responsible for creating and displaying notifications to the user.
    - **Push API**: Gives web applications the ability to receive messages pushed to them from a server.
- **Basic Flow**:
    1. **Permission Request**: The web application first requests notification permission from the user using `Notification.requestPermission()`. It's recommended to do this based on a user action (like clicking an "Enable Notifications" button) rather than immediately upon page load, to avoid confusing users.
    2. **Service Worker Registration**: The `script.js` file registers `sw.js` as a service worker using `navigator.serviceWorker.register()`.
    3. **Subscription to Push Service**: If permission is granted, the service worker then subscribes to a Push Service using the Push API. This step enables the service worker to receive push events from a server. (Note: The process of subscribing to a Push Service is a topic for a follow-up video).
    4. **Receiving Push Events**: When a push event arrives from the server, the service worker awakens in the background.
    5. **Displaying Notification**: The service worker uses the information from the push message and the Notification API to display a notification to the client. The `showNotification()` method on the service worker registration instance is used for this purpose, accepting a title and an options object (for body, icon, vibration, etc.).

### Important Considerations

- **User Experience (UX)**: Do not directly prompt users for notification permission when they land on your webpage. Instead, provide a clear option (e.g., an "Enable Notifications" button) within a relevant context in the user journey (e.g., after booking a flight for flight updates).
- **Permission States**: The `Notification.permission` property can be `'default'`, `'granted'`, or `'denied'`. You can use this to control the visibility or functionality of your "Enable Notifications" button. If permission is `'denied'`, users typically need to manually reset it in their browser settings.
- **Service Worker Lifecycle**: Service workers are registered once. If you make updates to your `sw.js` file, the updated service worker will re-register, and you might see console logs again.
- **Asynchronous Operations**: Registering service workers and requesting permissions are asynchronous operations, so using `async/await` is crucial for proper flow control.

---

Think of the entire push notification system like a **personal post office box** for your website on your computer.

- The **Service Worker (`sw.js`)** is like a dedicated postal worker for your website, always waiting in the background, even when you've closed the main browser window.
- When you **`registerServiceWorker()`**, you're essentially setting up this postal worker.
- The **Notification API** is like the "display window" on your post office box that shows you a new mail alert.
- When you **`requestNotificationPermission()`**, you're giving the postal worker permission to show you new mail alerts (notifications) from your website. You wouldn't want the postal worker just shoving alerts in your face without permission, right? That's why the button for a better UX.
- The **Push API** is the special system that allows the server (the sender of the mail) to directly send a message to your postal worker, even if you're not currently looking at your post office box.
- When a new push message arrives, your postal worker (Service Worker) wakes up and uses the display window (Notification API) to show you the "New Mail!" alert.

This way, your website can tap you on the shoulder with important updates even when you're busy with other things, just like getting a text message about new mail without having to constantly check your physical mailbox.


---
---

# [How to add Push Notifications to a Next.js App w/ Firebase Cloud Messaging! (Tutorial for Beginners)](https://www.youtube.com/watch?v=W-rlFj0d0RQ&t=1104s)

> Notes by NotebookLM
### 1. Understanding Push Notifications and Firebase Cloud Messaging (FCM)

- **What are Push Notifications?**
    - They are small alerts or "pings" that appear on your phone or computer screen.
    - Examples include new message alerts, order delivery updates, or any information requiring your attention.
    - Push notifications work across **iOS, Android, and the web**.
- **What is Firebase Cloud Messaging (FCM)?**
    - FCM is a **free Google service** provided by Firebase.
    - It supports both **mobile native push notifications** and **web push notifications** (which work in browsers like Google Chrome and Safari).
    - Once correctly implemented, FCM allows you to **send push notifications to all your users**.
- **Why use FCM?**
    - **Centralised Sending:** Send a large number of notifications from **one single platform**.
    - **Google Analytics Integration:** Directly links with Google Analytics, enabling cool features like sending **personalised messages to targeted audience segments**. This also allows for A/B testing notifications.
    - **Scalability & Cost-Effective:** Built by Google, ensuring it scales well and is cost-effective.
    - **User Engagement:** A powerful tool to keep users engaged and informed.

### 2. Sending Notifications with FCM

- **Two Main Ways to Send Notifications:**
    1. **Firebase Console (GUI):** This is an **online portal** that is super user-friendly and easy to use.
    2. **Trusted Environment:** This refers to your own backend, such as **Firebase Cloud Functions** or **route handlers in Next.js** (e.g., using Next.js 14/15 App Router). This allows you to create your own logic for sending notifications.
- **Notification Flow:**
    - Notifications are sent from either the **trusted environment** or the **Firebase Console**.
    - They then go to the **Firebase backend service**.
    - From there, you decide whether to push them to **Android, iOS, or web platforms**.
    - Finally, your users see the notification.
- **Types of Messages You Can Send:**
    1. **Notification Messages:**
        - These are **handled by FCM** itself.
        - You specify the title, body, images, etc., and FCM blasts it out, serving it in the native format for iOS and Android devices.
    2. **Data Messages:**
        - These are sent to the client, but **what the client does with the data is completely up to you**.
        - You write the code that processes the push notification data. This is the type typically covered in web tutorials as it allows for custom behaviour.
- **Targeting and Customisation:**
    - You can send messages to **single devices, multiple devices, or a subset of devices** subscribed to a specific notification topic.
    - Integration with Google Analytics allows sending to **segmented parts of your audience**, including running A/B tests.
    - Custom data can be included in messages, for example, a `link` to redirect the user when they click the notification.

### 3. Implementing Push Notifications in a Next.js App (Tutorial Walkthrough)

- **Initial Setup & Prerequisites:**
    - The tutorial uses a GitHub repository that you need to clone.
    - After cloning, run `npm install` to install dependencies.
    - **VS Code** is recommended as the code editor.
- **Firebase Project Configuration:**
    1. **Create/Select a Firebase Project:** Go to `firebase.google.com`, navigate to the console, and create a new project (e.g., "fcm demo YouTube") or select an existing one. **Enable Google Analytics** for the project.
    2. **Register Web App:** In your Firebase project settings, click the web icon (</>) to register a new web app. Give it a name (e.g., "fcm demo YouTube") and click "Register App".
    3. **Copy Firebase Config:** Copy the generated code snippet (Firebase configuration).
        - Paste this configuration into `firebase.ts` (the client-side Firebase initialization file).
        - Also, paste it into `public/firebase-messaging-sw.js` (the service worker file).
    4. **Generate Service Account Key:** For sending notifications from your backend (trusted environment), you need a service key. In Firebase project settings, navigate to "Service accounts" and click "Generate new private key". This downloads a `service-key.json` file. Drag this file into your project and rename it to `service-key.json`.
    5. **Generate VAPID Key Pair:** For web push notifications, you need a VAPID key. In Firebase project settings, go to "Cloud Messaging", then "Web Push Certificates", and click "Generate key pair". Copy the public key generated.
        - Paste this VAPID public key into your `.env.local` file (or equivalent environment variable setup for Next.js).
- **HTTPS for Service Workers:**
    - To use service workers, your application **must run over HTTPS**, which is a secure connection.
    - For local development, the Next.js project uses the **`experimental.https` flag**.
    - You'll access your app via `https://localhost:3000`.

### 4. Handling Notifications: Foreground vs. Background States

- Your app can be in two main states regarding notification handling:
    1. **Foreground State:** The app is currently open and active on the user's screen (e.g., the tab is focused).
        - In this state, you might handle notifications by displaying **toast notifications** within the app itself. You can also choose to show the native notification API.
    2. **Background State:** The app is not in the foreground (e.g., it's in a different tab, the browser is minimised, or even closed).
        - In this state, the **service worker** is responsible for receiving and displaying the notification to the user.

### 5. Service Workers (Background Notification Handling)

- **What is a Service Worker?**
    - A service worker is a **script that your browser runs in the background**.
    - It is **separate from the web page** and enables features that don't require the web page or user interaction.
    - This "background functionality" allows it to perform tasks like **push notifications, background synchronisation, and network request interception/caching**, even when the user is not actively using the app or the page is closed.
    - It lives in the `public` folder of your project, making it publicly accessible and allowing it to install itself onto the browser.
- **Debugging Service Workers:**
    - You can inspect service workers in your browser's developer tools (e.g., right-click, inspect -> Application tab -> Service Workers).
    - Here, you can see registered service workers, start/stop them, and view their console logs for debugging.
- **Service Worker States:**
    1. **Registration State:** The service worker is installed onto your browser. It then runs in the background, waiting for commands (like push messages).
    2. **Installation and Activation:** During this phase, it caches any resources it needs to carry out its job. Once installed, it can take control of pages.
    3. **Programmed Actions:** After activation, it performs tasks you program it to do, such as listening for future push notifications or notification clicks.
- **Key Code Snippets (`public/firebase-messaging-sw.js`):**
    - It initializes Firebase messaging using the provided configuration.
    - **`onBackgroundMessage`:** This listener handles incoming messages when the app is in the background.
        - It prepares the content of the notification (title, body, icon).
        - It extracts a `link` from the message payload (checking `fcmOptions.link` from backend or `data.link` from console).
        - `self.registration.showNotification(title, options)` is called to **display the notification** on the screen.
    - **`notificationclick` Event Listener:** This listener defines what happens when a user clicks a background notification.
        - It closes the notification upon click.
        - It then checks for an associated `URL` in the notification data.
        - If the user already has the relevant tab open and focused, it will **refocus that existing tab**.
        - Otherwise, it will **open a new browser window** to the specified URL.
        - **Important Note:** To ensure an existing tab is refocused rather than opening a new window, **always provide the full URL** (e.g., `https://localhost:3000/contact`) instead of a relative URL (e.g., `/contact`).

### 6. Foreground Notification Handling (using `useFcmToken` custom hook)

- The tutorial provides a custom React hook called `useFcmToken` (`useFcmToken.tsx`) to manage foreground notifications and token acquisition.
- **FCM Token Acquisition:**
    - The `loadToken` function (within `useFcmToken`) manages getting the FCM registration token.
    - A helper function, `getNotificationPermissionAndToken`, first checks if the browser supports notifications.
    - It then checks the user's current **notification permission status** (granted, denied, or default/unasked).
    - If permission is not denied, it will **request permission** from the user (displaying the "This website wants to show notifications" prompt).
    - The `fetchToken` function is then called. It uses the `getToken` function from Firebase Messaging, passing in the messaging instance and the **VAPID public key**.
    - The **FCM token is unique per user and per device/browser**. It is crucial for sending notifications specifically to that user's device.
    - **Retry Mechanism:** The hook includes a retry mechanism to handle cases where the service worker might not be immediately installed and active, ensuring the token is acquired reliably after a few attempts.
- **Foreground Message Listener (`onMessage`):**
    - Within the `useFcmToken` hook, an `onMessage` listener is registered for incoming FCM messages when the app is in the foreground.
    - This listener ensures that if notification permission is denied, no action is taken.
    - When a message is received in the foreground, it can display a **toast notification** (e.g., using Sonner from Shadcn) with the message title and body.
    - It can optionally display a native browser notification in the foreground using the standard `new Notification()` API.
    - It also handles click events on these native foreground notifications, preventing default behavior and **redirecting the user to a specified link** (e.g., using `router.push` in Next.js).
    - A **cleanup function** is returned from the `useEffect` hook to unsubscribe from the listener when the component unmounts or dependencies change, preventing duplicate listeners.

### 7. Sending Notifications from the Backend (Trusted Environment)

- **API Endpoint:** The Next.js app includes an API endpoint (e.g., `send-notification` route handler) that acts as the trusted environment.
- **Firebase Admin SDK:**
    - The backend code initializes the Firebase Admin SDK. This setup ensures that the SDK is only initialized once to prevent unexpected behavior in server-rendered environments.
    - The **`service-key.json`** file (generated earlier) is used here to authenticate the Admin SDK, giving it administrative permissions to interact with Firebase services on your behalf.
- **Sending Logic:**
    - The endpoint receives the user's FCM **token, title, message, and link** from the frontend.
    - It constructs a message payload using types defined by `Firebase admin messaging`.
    - The **`webpush` options** are used to specify the link to open when the user clicks the notification, ensuring a standard approach.
    - The core action is `admin.messaging().send(payload)`, which sends the notification to the device associated with the provided token.

### 8. Managing FCM Registration Tokens (Best Practices)

- **Importance of Storing Tokens:**
    - It is crucial to **save these unique FCM tokens in a database** (e.g., when a user logs in or registers on your website).
    - **Reason 1: Custom Backend Sending:** If you want to send custom, targeted notifications to specific users or groups from your backend (trusted environment) without using the Firebase Console, you need to know their tokens.
    - **Reason 2: Real-time Communication (e.g., Chat Apps):** For applications like chat messaging, you need access to users' tokens on the server side to send messages to specific recipients.
- **Implementation Suggestion:**
    - When fetching a new token (e.g., within the `loadToken` function), check your database to see if the token already exists.
    - If it's a new token, **save it to your database**.
    - If it exists, you don't need to save it again, but you might want to compare and update it if it has changed.
- **Further Reading:** The official Firebase documentation on "Concepts and best practices" for Cloud Messaging (specifically managing FCM registration tokens) is highly recommended for deeper understanding.

**Analogy:**

Think of **Firebase Cloud Messaging (FCM)** as a **global postal service** for your app.

- **Push notifications** are like the **letters or parcels** being delivered.
- You can send these letters either from your **local post office (Firebase Console GUI)** or from your **trusted private messenger service (your backend/trusted environment)**.
- **FCM tokens** are like **unique postal codes** for each of your users' devices. When you send a letter, you use this specific postal code to make sure it reaches the right recipient.
- The **service worker** is like a **dedicated mailbox attendant** always running in the background of your user's browser. Even if the user isn't actively looking at your website (they're on another tab or have closed it), this attendant is constantly checking for new mail (notifications) and will pop them up for the user to see.
- If the user _is_ actively on your website, your app can also handle the notification in the **foreground**, perhaps displaying it as a subtle pop-up inside the app itself, like a quick note appearing on their desk while they're working.
- Storing **FCM tokens in your database** is like keeping a detailed address book of all your users' unique postal codes. This allows you to send targeted letters (notifications) to specific people or groups whenever you need to, without having to manually look them up every time.