
# Cryptography

| Topics                   | Subtopics                   |
| ------------------------ | --------------------------- |
| Symmetric Ciphers        | DES, AES                    |
| Public Key Encryption    | RSA, ECC                    |
| Digital Signatures       | Algorithms and verification |
| Authentication Protocols | Key exchange, certificates  |
| System Security          | Cryptographic applications  |
# Symmetric Ciphers - Overview

**Definition:**  
Symmetric cipher (or secret-key cipher) uses the _same key_ for both encryption and decryption. It ensures confidentiality as long as the shared key remains secret.

**Key Characteristics:**

- Single shared secret key
    
- High encryption/decryption speed
    
- Suitable for bulk data encryption
    
- Requires secure key distribution
    

**Basic Process:**

1. **Encryption:** Ciphertext = E(K, Plaintext)
    
2. **Decryption:** Plaintext = D(K, Ciphertext)  
    (Where _K_ is the secret key)
    

**Types of Symmetric Ciphers:**

1. **Stream Ciphers:** Encrypt data bit-by-bit or byte-by-byte using a keystream (e.g., RC4).
    
2. **Block Ciphers:** Encrypt data in fixed-size blocks (e.g., AES, DES, Blowfish).
    

**Advantages:**

- Fast and efficient
    
- Less computationally intensive than asymmetric encryption
    

**Disadvantages:**

- Key distribution problem
    
- Scalability issue (requires n(n−1)/2 keys for n users)
    
- No inherent authentication or non-repudiation
    

**Examples:**

- DES (Data Encryption Standard)
    
- AES (Advanced Encryption Standard)
    
- 3DES, Blowfish, RC5
---
---


# Public Key Encryption, Digital Signatures

**Public Key Encryption (Asymmetric Encryption):**  
Uses a _pair of keys_: a **public key** (shared openly) and a **private key** (kept secret).

**Process:**

1. **Encryption:** Ciphertext = E(Public Key, Plaintext)
    
2. **Decryption:** Plaintext = D(Private Key, Ciphertext)
    

**Key Properties:**

- Different keys for encryption and decryption
    
- Eliminates key distribution problem
    
- Slower than symmetric encryption
    

**Examples:**

- RSA (Rivest-Shamir-Adleman)
    
- ECC (Elliptic Curve Cryptography)
    
- ElGamal
    

**Advantages:**

- Secure key exchange
    
- Enables authentication and non-repudiation
    

**Disadvantages:**

- Slower computation
    
- Larger key sizes required for equivalent security
    

---

**Digital Signatures:**  
Used to verify _authenticity_, _integrity_, and _non-repudiation_ of a message.

**Process:**

1. Sender generates a _hash_ of the message.
    
2. Sender encrypts the hash using their _private key_ → Digital Signature.
    
3. Receiver decrypts the signature using sender’s _public key_ and compares hash values.
    

**Properties:**

- Authenticity: Confirms sender’s identity
    
- Integrity: Detects message tampering
    
- Non-repudiation: Sender cannot deny authorship
    

**Common Algorithms:**

- RSA Digital Signature
    
- DSA (Digital Signature Algorithm)
    
- ECDSA (Elliptic Curve DSA)

---
---

# Authentication Protocols

**Definition:**  
Authentication protocols are cryptographic procedures used to verify the identity of communicating parties before data exchange.

**Objectives:**

- Verify user or entity identity
    
- Prevent impersonation
    
- Ensure data integrity and confidentiality
    

**Basic Types:**

1. **Password-Based Authentication:** Uses passwords or PINs; simple but vulnerable to replay and brute-force attacks.
    
2. **Challenge-Response Protocols:** Server sends a random challenge; client responds with encrypted/hashed result (e.g., using shared key).
    
3. **Mutual Authentication:** Both parties authenticate each other (used in SSL/TLS).
    
4. **Token-Based Authentication:** Uses tokens or session keys generated during login (e.g., Kerberos).
    
5. **Certificate-Based Authentication:** Relies on digital certificates issued by a trusted CA (Certificate Authority).
    

**Common Protocols:**

- **Kerberos:** Uses tickets and symmetric cryptography for mutual authentication in a distributed network.
    
- **Needham-Schroeder Protocol:** Uses nonce-based challenge-response with symmetric keys.
    
- **TLS/SSL Handshake:** Uses public-key cryptography for mutual authentication and session key establishment.
    
- **OAuth / OpenID Connect:** Used for web-based federated authentication.
    

**Threats:**

- Replay attacks
    
- Man-in-the-Middle (MitM) attacks
    
- Password guessing and credential theft
    

**Countermeasures:**

- Use of nonces/timestamps
    
- Encrypted channels (TLS/SSL)
    
- Multi-factor authentication

---
---

# System Security

**Definition:**  
System Security involves protecting computer systems and data from unauthorized access, misuse, modification, or denial of service.

**Goals (CIA Triad):**

1. **Confidentiality:** Prevent unauthorized disclosure of information.
    
2. **Integrity:** Ensure data accuracy and prevent unauthorized modification.
    
3. **Availability:** Ensure systems and data are accessible when needed.
    

**Key Components:**

1. **Authentication:** Verifying user identity.
    
2. **Authorization:** Granting access rights based on privileges.
    
3. **Accounting (Auditing):** Tracking user actions and system events.
    
4. **Access Control:** Mechanisms like DAC (Discretionary), MAC (Mandatory), and RBAC (Role-Based).
    

**Security Mechanisms:**

- **Encryption:** Protects data confidentiality.
    
- **Firewalls:** Filter network traffic based on rules.
    
- **Intrusion Detection/Prevention Systems (IDS/IPS):** Detect or block malicious activity.
    
- **Antivirus/Antimalware:** Protect against malware threats.
    
- **Patching & Updates:** Fix known vulnerabilities.
    
- **Backup & Recovery:** Protect against data loss.
    

**Common Threats:**

- Malware (virus, worm, trojan, ransomware)
    
- Phishing & social engineering
    
- Denial of Service (DoS/DDoS)
    
- Insider threats
    
- Zero-day exploits
    

**Best Practices:**

- Implement least privilege principle
    
- Regular software updates
    
- Strong password and MFA policies
    
- Network segmentation and monitoring
    
- Incident response planning