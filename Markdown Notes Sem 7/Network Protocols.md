


# [TCP/IP Protocol Suite with Real Life Examples | Why TCP/IP Used | Fundamentals of Networking](https://youtu.be/TVr0RZ1-74g)


```             
                                       ☁️ Server (eg. google)
                                       / 
                                      /
These layer are manage by           🌐 www /Internet
OS in device automatically          /
┌---------┐                        /
| A Layer |                      📶 Internet Service Provider (ISP)
|---------|                      / 
| T Layer |                     /
|---------|                    /
| I Layer |                  🛜 Router / Wifi Access Point
|---------|                 /
| L Layer |                /
└---------┘  ↰            /
             💻---------⬏
             Device
```


Certainly! Let's refine and expand on this explanation while keeping it in a teaching format with examples.

---

In every device, the way data is sent and received over the internet follows a specific structure of layers, which are managed by the operating system (OS). These layers ensure that data reaches its destination correctly and securely.

Imagine you want to visit a website like `www.google.com` on your browser. When you type the website address and press enter, the data flow through several layers in your device and the network, ultimately displaying the webpage on your screen. Let’s break down these layers:

### Application Layer
When you open a website like `www.google.com`, your browser communicates using the `http://` or `https://` protocols. Here’s what happens at this layer:
- **Encryption & Decryption:** If you're using `https://`, your data is encrypted before being sent out, ensuring security. When the data is received, it’s decrypted so it can be understood by your browser.
- **Domain Name System (DNS):** The website address you type, such as `www.google.com`, isn’t directly understood by computers. They need an IP address, which is like a phone number for servers. The DNS, working at this layer, translates the domain name (`www.google.com`) into an IP address of the nearest Google server so your request can be routed correctly.

For example, when you enter `www.google.com`, DNS might translate it to an IP address like `172.217.12.206`, which your browser will use to reach Google’s server.

*Note:* Even if you’re using other applications like WhatsApp, which doesn’t use `http` or `https`, they still operate under the Application Layer. These applications might use proprietary protocols for encrypting and transferring data, but they still follow the same layering structure.

### Transport Layer
In your device, you might have several applications running simultaneously, like your browser, email client, or messaging apps. The Transport Layer is responsible for managing how data is sent and received by these different applications. It does this by assigning a **port number** to each application, ensuring that data intended for your web browser doesn’t accidentally end up in your email client.

- **TCP (Transmission Control Protocol)**: This is used when you need a reliable connection. For example, when you’re loading a webpage, TCP ensures that all data packets arrive correctly and in the right order.
- **UDP (User Datagram Protocol)**: This is used for faster, but less reliable connections. It’s often used for live streaming or online gaming, where speed is more critical than perfect accuracy.

For instance, when you load a website, TCP might use port 80 for `http` or port 443 for `https`. Meanwhile, your email application might be using port 25 for sending emails.

### Internet Layer
This layer deals with IP addresses, which are like the virtual addresses for devices on the internet. When you connect to a Wi-Fi network, your Internet Service Provider (ISP) assigns an **IP address** to your device through the router. This IP address is used to identify your device on the internet.

- **IP Address:** Think of it as your device's home address on the internet. Just as a letter needs your home address to reach you, data packets need your IP address to find your device.

For example, when your browser sends a request to Google’s server, it uses your IP address as the return address so Google knows where to send the webpage data back.

*Note:* To send data, your device needs the IP address of the destination server (like Google’s server). Similarly, the server needs your IP address to send data back to you.

### Link Layer
This layer is responsible for the physical connection between your device and the network, usually through a **MAC address**. The MAC address is unique to each network device, like your computer’s Wi-Fi card or the router. It ensures that data packets can be directed to the correct hardware.

- **MAC Address:** Think of it as the physical address of a device on a local network. It’s like the unique serial number of your device’s network interface. 

When you send data, the data packet first travels to the router using the MAC address. The router then forwards the data to the ISP, and it continues on to the internet. When the response comes back, it follows the same path in reverse.

For instance, when you send a request from your laptop to the router, your laptop’s MAC address ensures the data packet reaches the correct device (the router) before it’s sent out to the wider internet.

*Note:* The MAC address is only needed for communication between devices on the same local network, like between your device and the router. Once the data packet leaves your local network, the MAC address isn’t used anymore.

### Summary of Addresses in Your System:
- **Port Number:** Used at the Transport Layer to identify the specific application sending or receiving data.
- **IP Address:** Used at the Internet Layer to identify the device on the internet.
- **MAC Address:** Used at the Link Layer to identify the physical device on a local network.

