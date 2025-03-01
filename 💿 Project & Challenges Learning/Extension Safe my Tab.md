
`manifest.json`
```json
{
   "action": {  // Defines the extension's action button (popup, icon, and title)
      "default_icon": "assets/img/48.png",  // Default icon for the action button
      "default_popup": "popup.html",  // Specifies the popup HTML file that appears when clicking the extension icon
      "default_title": "Safe My Tab"  // Tooltip title when hovering over the extension icon
   },
   "author": "Gaurav Kr. Meena",  // Author of the extension
   "background": {  // Defines the background script for handling events and background tasks
      "service_worker": "assets/js/background.js"  // Specifies the background service worker script
   },
   "content_scripts": [ {  // Defines scripts that run on web pages
      "js": [ "assets/js/sha.js", "assets/js/noty.js", "assets/js/content.js", "assets/js/sponsor.js" ],  // Scripts injected into web pages
      "matches": [ "*://*/*" ],  // Runs on all websites
      "run_at": "document_start"  // Executes the scripts as soon as the page starts loading
   } ],
   "description": "Your app lock, but for the web. Protect any website with a password!",  // Description of the extension
   "homepage_url": "https://blogdesire.com",  // Homepage or website link of the extension
   "icons": {  // Icons used in different places like Chrome Web Store, Extension Manager, etc.
      "128": "assets/img/128.png",  // 128x128 icon for the extension
      "48": "assets/img/48.png"  // 48x48 icon for the extension
   },
   "key": "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtZTn8q/rMz565HBoXtqRV25oWKWAgShQY97C/L2EbvOzShPpbFJztPNlCB9DUrObU3AlYlxUwrz6tttHl/Cpftkp8uvk/FeHAmDSriTPPFxGuLnmGzidFJcvOwDY/xcVZs5GJEJ4dcjcdEBHpc60mF0IzUMFQ4R+lU8BkBAYjdnAAFbROoOq09iyU7Y1iosds+ijlolsEjRpBj7M30qWU3ITOhcv/ENPJezxm2k3zXla7Qu4B59wQKLiPgLsdHHyPLvquDCYDyaXTjkDsaDzGScUEFKMa+eegf5X/RvTgkREMlsVbWhbBlCQ6zjwVdglRuUTBJGA3Mi3WeD4cLxjAwIDAQAB",  // Unique key for verifying the extension's identity (used for publishing and updates)
   "manifest_version": 3,  // Manifest version (latest is v3, required for modern extensions)
   "name": "Web Lock | App lock for websites",  // Name of the extension
   "optional_permissions": [ "tabs" ],  // Optional permissions that can be requested at runtime
   "permissions": [ "storage", "unlimitedStorage" ],  // Permissions the extension needs to function
   "short_name": "weblock",  // Shortened version of the extension name (used in UI with space constraints)
   "update_url": "https://clients2.google.com/service/update2/crx",  // URL for updating the extension in Chrome Web Store
   "version": "1.34",  // Current version of the extension
   "web_accessible_resources": [ {  // Resources that can be accessed by web pages
      "matches": [ "\u003Call_urls>" ],  // Allows these resources to be accessed on any URL
      "resources": [ "assets/css/login.css", "assets/css/noty.css", "assets/js/locker.js", "assets/js/sponsor.js", "assets/js/sha.js", "assets/js/noty.js", "assets/img/up-arrow.svg", "forgot.html", "login.html", "blocked.html" ]  // List of files accessible by web pages
   } ]
}

```