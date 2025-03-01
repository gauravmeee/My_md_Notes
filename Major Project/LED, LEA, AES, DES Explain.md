

Introduction to Advanced Encryption Standard (AES) - https://youtu.be/3MPkc-PFSRI
AES Encryption and Decryption - https://youtu.be/4KiwoeDJFiA


---

### **Comparison of DES, AES, LEA, and LED Encryption Algorithms**

| Feature              | **DES (Data Encryption Standard)**       | **AES (Advanced Encryption Standard)**               | **LEA (Lightweight Encryption Algorithm)**           | **LED (Light Encryption Device)**                           |
| -------------------- | ---------------------------------------- | ---------------------------------------------------- | ---------------------------------------------------- | ----------------------------------------------------------- |
| **Type**             | Symmetric Block Cipher                   | Symmetric Block Cipher                               | Symmetric Block Cipher                               | Symmetric Block Cipher                                      |
| **Block Size**       | 64-bit                                   | 128-bit                                              | 128-bit                                              | 64-bit                                                      |
| **Key Sizes**        | 56-bit (with 8-bit parity)               | 128, 192, 256-bit                                    | 128, 192, 256-bit                                    | 64, 128, 192, 256-bit                                       |
| **Structure**        | Feistel Network                          | Substitution-Permutation Network (SPN)               | ARX (Addition-Rotation-XOR)                          | SPN (Substitution-Permutation Network)                      |
| **Number of Rounds** | 16                                       | 10 (128-bit key), 12 (192-bit key), 14 (256-bit key) | 24 (128-bit key), 28 (192-bit key), 32 (256-bit key) | 48 (64-bit key), 96 (128-bit key)                           |
| **Security Level**   | Weak (vulnerable to brute force attacks) | Strong (widely used for secure encryption)           | Secure (lightweight and efficient)                   | Secure (optimized for ultra-low-power devices)              |
| **Performance**      | Slow by modern standards                 | Fast and efficient                                   | High-speed encryption for embedded systems           | Very lightweight, optimized for ultra-low-power IoT devices |
| **Target Use**       | Legacy encryption, no longer secure      | Standard encryption for security applications        | High-speed encryption on CPUs & embedded systems     | Ultra-low-power devices like IoT, RFID, and smart cards     |

**Key Differences**
- **DES** is outdated and insecure due to its **small key size (56-bit)**.
- **AES** is the most widely used encryption standard with **high security and efficiency**.
- **LEA** is optimized for **fast encryption on software-based platforms** (CPUs, embedded systems).
- **LED** is designed for **ultra-lightweight hardware environments** like **IoT and RFID**.



---

### **Comparison: LEA vs LED for IoT**

| Feature               | **LEA (Lightweight Encryption Algorithm)**                           | **LED (Light Encryption Device)**                                                         |
| --------------------- | -------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| **Security**          | Stronger security (128-bit block size)                               | Moderate security (64-bit block size)                                                     |
| **Performance**       | High-speed encryption (optimized for software, CPUs)                 | Low-power, hardware-efficient but slower                                                  |
| **Power Consumption** | More computationally intensive                                       | Ultra-low power, ideal for energy-constrained devices                                     |
| **Target Devices**    | Embedded systems, mobile devices, general IoT                        | Ultra-constrained IoT (RFID, smart cards, tiny sensors)                                   |
| **Implementation**    | Uses **ARX operations** (Addition, Rotation, XOR) for fast execution | Uses **SPN structure** (Substitution-Permutation Network), optimized for minimal hardware |

**Which is Better?**
- **For performance:** **LEA** (faster on general IoT devices like embedded systems and CPUs).
- **For low-power IoT (e.g., RFID, tiny sensors):** **LED** (ultra-low power, better for hardware-based encryption).
- **For security:** **LEA** (stronger encryption due to its 128-bit block size vs. 64-bit in LED).

**Final Choice:**
- Use **LEA** if your IoT device has **better processing power and needs speed**.
- Use **LED** if your IoT device is **ultra-low-power and hardware-constrained**.



---

### DES

![](https://miro.medium.com/v2/resize:fit:1400/0*G-3TrjJYByrqHqLo)


![](https://miro.medium.com/v2/resize:fit:1400/0*pTCtuaGHXqBc1oxX)


---
### AES

![](https://miro.medium.com/v2/resize:fit:1400/0*oF8Vw7SCKQSfTyHd)

![](https://www.researchgate.net/publication/374616329/figure/fig2/AS:11431281197652207@1697039231489/Advanced-Encryption-Standard.ppm)


---

### LEA



![](https://www.researchgate.net/profile/Neungsoo-Park/publication/285813354/figure/fig1/AS:959991255150596@1605891159391/Encryption-and-Description-Process-of-LEA.png)



![](https://upload.wikimedia.org/wikipedia/commons/3/3a/LEA_enc_round_function.png)


---

