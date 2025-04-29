
To determine which encryption algorithm is better between the original LEA (File 1) and the Modified LEA + SBOX (File 2), we need to analyze the results from various statistical tests that assess randomness and unpredictability, which are crucial for encryption algorithms.

### Original LEA
```python
import struct
import time

def rol(x, r):
    """Rotate left"""
    return ((x << r) | (x >> (32 - r))) & 0xFFFFFFFF

def ror(x, r):
    """Rotate right"""
    return ((x >> r) | (x << (32 - r))) & 0xFFFFFFFF


def bytes_to_words(b):
    """16 bytes -> 4 words"""
    return list(struct.unpack('<4I', b))

def words_to_bytes(w):
    """4 words -> 16 bytes"""
    return struct.pack('<4I', *w)

def lea_encrypt_block(block, round_keys):
    X = bytes_to_words(block)
    
    # Initial mixing
    X[0] ^= X[1]
    X[1] ^= X[2]
    X[2] ^= X[3]
    X[3] ^= X[0]
    
    for rk in round_keys:
        # Round function
        X[0] = rol((X[0] + (X[1] ^ rk[0])) & 0xFFFFFFFF, 3)
        X[1] = rol((X[1] + (X[2] ^ rk[1])) & 0xFFFFFFFF, 5)
        X[2] = rol((X[2] + (X[3] ^ rk[2])) & 0xFFFFFFFF, 9)
        X[3] = rol((X[3] + (X[0] ^ rk[3])) & 0xFFFFFFFF, 11)
        
        # Additional mixing step
        X[0] ^= rol(X[2], 7)
        X[1] ^= rol(X[3], 11)
        X[2] ^= rol(X[0], 13)
        X[3] ^= rol(X[1], 17)
    
    return words_to_bytes(X)

def lea_decrypt_block(block, round_keys):
    X = bytes_to_words(block)
    
    for rk in reversed(round_keys):
        # Reverse additional mixing step
        X[3] ^= rol(X[1], 17)
        X[2] ^= rol(X[0], 13)
        X[1] ^= rol(X[3], 11)
        X[0] ^= rol(X[2], 7)
        
        # Reverse round function
        X[3] = (ror(X[3], 11) - (X[0] ^ rk[3])) & 0xFFFFFFFF
        X[2] = (ror(X[2], 9) - (X[3] ^ rk[2])) & 0xFFFFFFFF
        X[1] = (ror(X[1], 5) - (X[2] ^ rk[1])) & 0xFFFFFFFF
        X[0] = (ror(X[0], 3) - (X[1] ^ rk[0])) & 0xFFFFFFFF
    
    # Reverse initial mixing
    X[3] ^= X[0]
    X[2] ^= X[3]
    X[1] ^= X[2]
    X[0] ^= X[1]
    
    return words_to_bytes(X)

def generate_round_keys(key, rounds=24):
    K = list(struct.unpack('<4I', key))
    round_keys = []
    
    # Constants for key schedule
    delta = [
        0x9e3779b9,  # Golden ratio
        0x517cc1b7,  # sqrt(2)
        0x428a2f98,  # sqrt(3)
        0x71374491   # sqrt(5)
    ]
    
    for i in range(rounds):
        # Simplified key schedule
        rk = [0] * 4
        for j in range(4):
            # Simplified mixing
            temp = rol(K[j], j * 5) ^ delta[j]
            temp = (temp + rol(K[(j+1)%4], j*7)) & 0xFFFFFFFF
            temp ^= (i * delta[j]) & 0xFFFFFFFF
            
            rk[j] = temp
            
            # Update key state for next round
            K[j] = rol(K[j], 13) ^ temp
            
        round_keys.append(rk)
    return round_keys

def pad(data):
    pad_len = 16 - len(data) % 16
    return data + bytes([pad_len] * pad_len)

def unpad(data):
    pad_len = data[-1]
    return data[:-pad_len]

def encrypt_img_data(data: bytes, key: bytes) -> bytes:
    round_keys = generate_round_keys(key)
    
    chunks = [data[i:i+16] for i in range(0, len(data), 16)]
    if len(chunks[-1]) < 16:
        chunks[-1] = pad(chunks[-1])
    
    return b''.join(lea_encrypt_block(chunk, round_keys) for chunk in chunks)

def decrypt_img_data(data: bytes, key: bytes) -> bytes:
    round_keys = generate_round_keys(key)
    
    chunks = [data[i:i+16] for i in range(0, len(data), 16)]
    
    return unpad(b''.join(lea_decrypt_block(chunk, round_keys) for chunk in chunks))
```

![[OriginalLEA-Flowchart.png]]


### 🔠 **Typical Meaning of J, M, H, T in Crypto Contexts**

|Symbol|Common Role in Cryptography|
|---|---|
|**J**|Often used as a round counter or index in loops (like `i` in your key schedule).|
|**M**|Message block – the plaintext or ciphertext chunk being processed.|
|**H**|Hash state – frequently seen in hash functions or MAC constructions (e.g., HMAC).|
|**T**|Temporary variable, tag, or transformation – often stores intermediate values.|

## Code Explanation

Here is a detailed Mermaid flow diagram with explanations for the provided code:Explanation:

**1. Utility Functions:**
- `rol(x, r)` and `ror(x, r)`: These functions perform left and right rotation of a 32-bit value `x` by `r` bits, respectively.
- `bytes_to_words(b)` and `words_to_bytes(w)`: These functions convert between 16 bytes and 4 32-bit words, using the `struct` module for efficient packing and unpacking.

**2. LEA Encryption:**
- `lea_encrypt_block(block, round_keys)`: This function encrypts a 16-byte input block using the LEA algorithm and the provided round keys.
- It first converts the input block to 4 32-bit words.
- It performs an initial mixing of the words.
- It then iterates through the round keys, applying the round function and additional mixing steps to the words.
- Finally, it converts the final 4 words back to 16 bytes and returns the encrypted block.
- `lea_decrypt_block(block, round_keys)`: This function decrypts a 16-byte input block using the LEA algorithm and the provided round keys.
- It first converts the input block to 4 32-bit words.
- It iterates through the round keys in reverse order, reversing the round function and additional mixing steps.
- It then reverses the initial mixing of the words.
- Finally, it converts the final 4 words back to 16 bytes and returns the decrypted block.

**3. Key Schedule:**
- `generate_round_keys(key, rounds=24)`: This function generates the round keys for the LEA algorithm based on the provided 16-byte key.
- It first converts the key to 4 32-bit words.
- It initializes the key schedule constants.
- It then iterates through the required number of rounds, computing the round key for the current round and updating the key state for the next round.
- Finally, it returns the list of round keys.

**4. Padding:**
- `pad(data)`: This function pads the input data to a multiple of 16 bytes, as required by the LEA algorithm.
- It calculates the padding length required to make the data length a multiple of 16 bytes.
- It appends the padding bytes to the data and returns the padded data.
- `unpad(data)`: This function removes the padding from the decrypted data.
- It extracts the padding length from the last byte of the data.
- It removes the padding bytes from the end of the data and returns the unpadded data.

**5. Encryption/Decryption:**
- `encrypt_img_data(data, key)`: This function encrypts the input data using the LEA algorithm and the provided key.
- It first generates the round keys from the provided key.
- It splits the input data into 16-byte chunks, padding the last chunk if it's less than 16 bytes.
- It then encrypts each chunk using the `lea_encrypt_block` function and concatenates the encrypted chunks.
- Finally, it returns the encrypted data.
- `decrypt_img_data(data, key)`: This function decrypts the input data using the LEA algorithm and the provided key.
- It first generates the round keys from the provided key.
- It splits the input data into 16-byte chunks.
- It decrypts each chunk using the `lea_decrypt_block` function and concatenates the decrypted chunks.
- Finally, it removes the padding from the decrypted data and returns the unpadded data.

The flow diagram provides a detailed breakdown of the functionality and logic of the provided code, making it easier to understand the overall structure and the role of each component.

---

### Modified LEA+SBOX
```python
import numpy as np
import cv2
import os
import struct


# --- S-box ---
sbox = bytes([(i * 73) % 256 for i in range(256)])
inv_sbox = [0] * 256
for i, val in enumerate(sbox):
    inv_sbox[val] = i

# --- Utility functions ---
def rol(x, r):  # Rotate left
    return ((x << r) | (x >> (32 - r))) & 0xFFFFFFFF

def ror(x, r):  # Rotate right
    return ((x >> r) | (x << (32 - r))) & 0xFFFFFFFF

def bytes_to_words(b):  # 16 bytes -> 4 words
    return list(struct.unpack('<4I', b))

def words_to_bytes(w):  # 4 words -> 16 bytes
    return struct.pack('<4I', *w)

# --- LEA Round Function ---
def lea_encrypt_block(block, round_keys):
    X = bytes_to_words(block)
    for rk in round_keys:
        X[0] = rol((X[0] + (X[1] ^ rk[0])) & 0xFFFFFFFF, 3)
        X[1] = rol((X[1] + (X[2] ^ rk[1])) & 0xFFFFFFFF, 5)
        X[2] = rol((X[2] + (X[3] ^ rk[2])) & 0xFFFFFFFF, 9)
        X[3] = rol((X[3] + (X[0] ^ rk[3])) & 0xFFFFFFFF, 11)
        # Apply S-box
        for i in range(4):
            X[i] = int.from_bytes(bytes([sbox[b] for b in X[i].to_bytes(4, 'little')]), 'little')
    return words_to_bytes(X)

def lea_decrypt_block(block, round_keys):
    X = bytes_to_words(block)
    for rk in reversed(round_keys):
        # Apply inverse S-box
        for i in range(4):
            X[i] = int.from_bytes(bytes([inv_sbox[b] for b in X[i].to_bytes(4, 'little')]), 'little')
        X[3] = (ror(X[3], 11) - (X[0] ^ rk[3])) & 0xFFFFFFFF
        X[2] = (ror(X[2], 9) - (X[3] ^ rk[2])) & 0xFFFFFFFF
        X[1] = (ror(X[1], 5) - (X[2] ^ rk[1])) & 0xFFFFFFFF
        X[0] = (ror(X[0], 3) - (X[1] ^ rk[0])) & 0xFFFFFFFF
    return words_to_bytes(X)

# --- Key schedule (simplified for 128-bit key) ---
def generate_round_keys(key, rounds=24):
    K = list(struct.unpack('<4I', key))
    round_keys = []
    for i in range(rounds):
        rk = [(K[j] + i + j) & 0xFFFFFFFF for j in range(4)]
        round_keys.append(rk)
    return round_keys

# --- Padding ---
def pad(data):
    pad_len = 16 - len(data) % 16
    return data + bytes([pad_len] * pad_len)

def unpad(data):
    pad_len = data[-1]
    return data[:-pad_len]

# --- Image Conversion ---
def image_to_bytes(image_path):
    image = cv2.imread(image_path, cv2.IMREAD_UNCHANGED)
    return image.tobytes(), image.shape

def bytes_to_image(data, shape):
    return np.frombuffer(data, dtype=np.uint8).reshape(shape)

# --- Full File Encryption/Decryption ---
def encrypt_img_data(data: bytes, key: bytes) -> bytes:
    data = pad(data)
    round_keys = generate_round_keys(key)
    encrypted = b''.join(lea_encrypt_block(data[i:i+16], round_keys) for i in range(0, len(data), 16))
    return encrypted

def decrypt_img_data(data: bytes, key: bytes) -> bytes:
    round_keys = generate_round_keys(key)
    decrypted = b''.join(lea_decrypt_block(data[i:i+16], round_keys) for i in range(0, len(data), 16))
    return unpad(decrypted)
```

![[ModifiedLEA-Flowchart.png]]


#### LEA encryption block works with the S-box integrated

![[S-box Integration in LEA.png]]
## Code Explanation

The provided code is an implementation of the LEA (Lightweight Encryption Algorithm) cipher, which is a symmetric-key cryptographic algorithm. The code includes functions for encrypting and decrypting data, as well as utility functions for converting between bytes and words, and for padding and unpadding data.

Here's a breakdown of the code:

**1. S-box and Inverse S-box:** 
- The code defines an S-box and its inverse, which are used in the encryption and decryption processes.

**2. Utility Functions:**
- `rol(x, r)` and `ror(x, r)`: Rotate left and right, respectively, a 32-bit integer `x` by `r` bits.
- `bytes_to_words(b)` and `words_to_bytes(w)`: Convert between a 16-byte block and a list of 4 32-bit words.

**3. LEA Round Function:**
- `lea_encrypt_block(block, round_keys)`: Encrypts a 16-byte block using the provided round keys.
- `lea_decrypt_block(block, round_keys)`: Decrypts a 16-byte block using the provided round keys.

**4. Key Schedule:**
- `generate_round_keys(key, rounds=24)`: Generates the round keys from the 128-bit key.

**5. Padding:**
- `pad(data)`: Pads the input data to a multiple of 16 bytes.
- `unpad(data)`: Removes the padding from the decrypted data.

**6. Image Conversion:**
- `image_to_bytes(image_path)`: Converts an image file to a bytes object and its shape.
- `bytes_to_image(data, shape)`: Converts a bytes object and its shape back to an image.

**7. Full File Encryption/Decryption:**
- `encrypt_img_data(data, key)`: Encrypts the input data (e.g., an image) using the provided key.
- `decrypt_img_data(data, key)`: Decrypts the encrypted data using the provided key.

The code provides a way to encrypt and decrypt image data using the LEA cipher. The `encrypt_img_data` and `decrypt_img_data` functions can be used to encrypt and decrypt any data, not just image data.

To use this code, you would typically call the `encrypt_img_data` or `decrypt_img_data` functions with the appropriate data and key. For example:

```python
# Encrypt an image

image_path = 'input_image.png'

key = b'my_secret_key_123'

encrypted_data = encrypt_img_data(image_to_bytes(image_path)[0], key)

# Save the encrypted data to a file

# Decrypt the encrypted data

decrypted_data = decrypt_img_data(encrypted_data, key)

decrypted_image = bytes_to_image(decrypted_data, image_to_bytes(image_path)[1])

cv2.imwrite('decrypted_image.png', decrypted_image)
```

This code would encrypt the input image using the provided key, and then decrypt the encrypted data back to the original image.

---
# Compare Results

which one result is better for encryption algorithm. 
1. **File1** = `resultsOriginalLEA.txt`
2. **File2** = `resultsModifiedLEA.txt`
```txt
=== ApproximateEntropy ===
File1 Values:  [0.450521]
File2 Values:  [0.287752]
  Value 1: File1 > File2 by 0.162769

=== BlockFrequency ===
File1 Values:  [0.368814]
File2 Values:  [0.45667]
  Value 1: File2 > File1 by 0.087856

=== CumulativeSums ===
File1 Values:  [0.315001, 0.332992]
File2 Values:  [0.581218, 0.145443]
  Value 1: File2 > File1 by 0.266217
  Value 2: File1 > File2 by 0.187549

=== FFT ===
File1 Values:  [0.230943]
File2 Values:  [0.356244]
  Value 1: File2 > File1 by 0.125301

=== Frequency ===
File1 Values:  [0.976059]
File2 Values:  [0.45855]
  Value 1: File1 > File2 by 0.517509

=== LinearComplexity ===
File1 Values:  [0.765439]
File2 Values:  [0.630303]
  Value 1: File1 > File2 by 0.135136

=== LongestRun ===
File1 Values:  [0.636065]
File2 Values:  [0.926421]
  Value 1: File2 > File1 by 0.290356

=== NonOverlappingTemplate ===
File1 Values:  [0.236206, 0.006447, 0.293899, 0.076878, 0.94096, 0.404844, 0.988229, 0.197514, 0.834242, 0.674361, 0.318866, 0.857247, 0.63909, 0.99455, 0.601062, 0.974499, 0.729577, 0.028372, 0.696187, 0.713444, 0.116715, 0.598145, 0.167222, 0.498606, 0.229521, 0.635585, 0.634717, 0.739865, 0.27649, 0.856197, 0.376714, 0.895249, 0.316025, 0.108686, 0.233366, 0.859978, 0.889698, 0.462504, 0.312352, 0.267699, 0.521402, 0.427314, 0.347642, 0.483408, 0.214994, 0.351263, 0.550034, 0.744224, 0.750204, 0.204093, 0.221963, 0.930557, 0.313013, 0.550002, 0.533739, 0.61342, 0.857031, 0.63048, 0.149837, 0.817341, 0.658121, 0.872262, 0.674628, 0.99545, 0.409506, 0.80377, 0.260728, 0.792539, 0.713345, 0.609363, 0.427863, 0.860591, 0.89293, 0.45521, 0.236206, 0.823367, 0.637922, 0.622877, 0.917272, 0.439395, 0.164977, 0.472473, 0.918384, 0.224767, 0.881442, 0.514421, 0.263716, 0.110845, 0.226041, 0.11055, 0.859792, 0.902044, 0.520703, 0.62641, 0.372419, 0.374496, 0.228998, 0.813356, 0.345563, 0.79021, 0.389159, 0.018097, 0.758097, 0.302459, 0.626777, 0.746864, 0.028375, 0.021297, 0.808089, 0.157866, 0.653948, 0.972035, 0.045703, 0.37886, 0.826759, 0.574683, 0.270004, 0.550002, 0.771949, 0.506786, 0.762102, 0.67053, 0.02201, 0.545306, 0.782713, 0.135263, 0.793396, 0.628612, 0.787812, 0.31643, 0.538787, 0.851693, 0.918885, 0.313415, 0.590566, 0.967748, 0.877634, 0.364604, 0.321773, 0.67063, 0.552046, 0.199699, 0.270875, 0.864589, 0.384992, 0.826267, 0.758416, 0.45521]
File2 Values:  [0.429686, 0.353751, 0.828345, 0.563544, 0.897801, 0.896845, 0.901701, 0.626077, 0.615084, 0.400936, 0.547733, 0.697842, 0.986586, 0.516543, 0.375617, 0.398991, 0.251595, 0.951233, 0.958812, 0.721022, 0.362641, 0.38277, 0.162629, 0.52922, 0.796019, 0.959934, 0.972973, 0.257765, 0.928323, 0.52153, 0.838742, 0.055345, 0.035206, 0.698239, 0.02398, 0.516068, 0.934615, 0.08019, 0.873134, 0.59735, 0.440393, 0.916809, 0.058621, 0.472656, 0.998011, 0.259161, 0.439659, 0.512113, 0.047615, 0.976141, 0.519241, 0.850901, 0.998068, 0.518098, 0.98768, 0.01575, 0.24224, 0.287002, 0.097843, 0.201295, 0.623843, 0.001375, 0.307611, 0.153302, 0.682615, 0.44771, 0.062129, 0.182743, 0.12653, 0.326447, 0.996736, 0.913442, 0.235155, 0.966694, 0.429686, 0.192209, 0.725664, 0.38804, 0.472534, 0.897662, 0.883278, 0.557053, 0.748631, 0.98328, 0.064334, 0.895814, 0.350087, 0.407059, 0.386079, 0.455898, 0.552923, 0.148995, 0.447888, 0.493527, 0.990515, 0.078758, 0.512397, 0.43831, 0.742256, 0.063766, 0.790026, 0.820392, 0.397605, 0.341429, 0.321749, 0.574847, 0.900186, 0.622777, 0.620978, 0.505215, 0.992001, 0.877002, 0.348812, 0.733156, 0.764826, 0.337304, 0.728176, 0.359202, 0.016303, 0.279091, 0.959447, 0.161951, 0.300435, 0.874769, 0.008315, 0.697345, 0.323221, 0.684542, 0.174397, 0.478952, 0.52954, 0.846031, 0.484055, 0.975972, 0.762134, 0.177751, 0.210866, 0.648606, 0.204349, 0.905933, 0.399601, 0.599205, 0.581195, 0.046343, 0.094644, 0.904584, 0.289898, 0.966694]
  Value 1: File2 > File1 by 0.19348
  Value 2: File2 > File1 by 0.347304
  Value 3: File2 > File1 by 0.534446
  Value 4: File2 > File1 by 0.486666
  Value 5: File1 > File2 by 0.043159
  Value 6: File2 > File1 by 0.492001
  Value 7: File1 > File2 by 0.086528
  Value 8: File2 > File1 by 0.428563
  Value 9: File1 > File2 by 0.219158
  Value 10: File1 > File2 by 0.273425
  Value 11: File2 > File1 by 0.228867
  Value 12: File1 > File2 by 0.159405
  Value 13: File2 > File1 by 0.347496
  Value 14: File1 > File2 by 0.478007
  Value 15: File1 > File2 by 0.225445
  Value 16: File1 > File2 by 0.575508
  Value 17: File1 > File2 by 0.477982
  Value 18: File2 > File1 by 0.922861
  Value 19: File2 > File1 by 0.262625
  Value 20: File2 > File1 by 0.007578
  Value 21: File2 > File1 by 0.245926
  Value 22: File1 > File2 by 0.215375
  Value 23: File1 > File2 by 0.004593
  Value 24: File2 > File1 by 0.030614
  Value 25: File2 > File1 by 0.566498
  Value 26: File2 > File1 by 0.324349
  Value 27: File2 > File1 by 0.338256
  Value 28: File1 > File2 by 0.4821
  Value 29: File2 > File1 by 0.651833
  Value 30: File1 > File2 by 0.334667
  Value 31: File2 > File1 by 0.462028
  Value 32: File1 > File2 by 0.839904
  Value 33: File1 > File2 by 0.280819
  Value 34: File2 > File1 by 0.589553
  Value 35: File1 > File2 by 0.209386
  Value 36: File1 > File2 by 0.34391
  Value 37: File2 > File1 by 0.044917
  Value 38: File1 > File2 by 0.382314
  Value 39: File2 > File1 by 0.560782
  Value 40: File2 > File1 by 0.329651
  Value 41: File1 > File2 by 0.081009
  Value 42: File2 > File1 by 0.489495
  Value 43: File1 > File2 by 0.289021
  Value 44: File1 > File2 by 0.010752
  Value 45: File2 > File1 by 0.783017
  Value 46: File1 > File2 by 0.092102
  Value 47: File1 > File2 by 0.110375
  Value 48: File1 > File2 by 0.232111
  Value 49: File1 > File2 by 0.702589
  Value 50: File2 > File1 by 0.772048
  Value 51: File2 > File1 by 0.297278
  Value 52: File1 > File2 by 0.079656
  Value 53: File2 > File1 by 0.685055
  Value 54: File1 > File2 by 0.031904
  Value 55: File2 > File1 by 0.453941
  Value 56: File1 > File2 by 0.59767
  Value 57: File1 > File2 by 0.614791
  Value 58: File1 > File2 by 0.343478
  Value 59: File1 > File2 by 0.051994
  Value 60: File1 > File2 by 0.616046
  Value 61: File1 > File2 by 0.034278
  Value 62: File1 > File2 by 0.870887
  Value 63: File1 > File2 by 0.367017
  Value 64: File1 > File2 by 0.842148
  Value 65: File2 > File1 by 0.273109
  Value 66: File1 > File2 by 0.35606
  Value 67: File1 > File2 by 0.198599
  Value 68: File1 > File2 by 0.609796
  Value 69: File1 > File2 by 0.586815
  Value 70: File1 > File2 by 0.282916
  Value 71: File2 > File1 by 0.568873
  Value 72: File2 > File1 by 0.052851
  Value 73: File1 > File2 by 0.657775
  Value 74: File2 > File1 by 0.511484
  Value 75: File2 > File1 by 0.19348
  Value 76: File1 > File2 by 0.631158
  Value 77: File2 > File1 by 0.087742
  Value 78: File1 > File2 by 0.234837
  Value 79: File1 > File2 by 0.444738
  Value 80: File2 > File1 by 0.458267
  Value 81: File2 > File1 by 0.718301
  Value 82: File2 > File1 by 0.08458
  Value 83: File1 > File2 by 0.169753
  Value 84: File2 > File1 by 0.758513
  Value 85: File1 > File2 by 0.817108
  Value 86: File2 > File1 by 0.381393
  Value 87: File2 > File1 by 0.086371
  Value 88: File2 > File1 by 0.296214
  Value 89: File2 > File1 by 0.160038
  Value 90: File2 > File1 by 0.345348
  Value 91: File1 > File2 by 0.306869
  Value 92: File1 > File2 by 0.753049
  Value 93: File1 > File2 by 0.072815
  Value 94: File1 > File2 by 0.132883
  Value 95: File2 > File1 by 0.618096
  Value 96: File1 > File2 by 0.295738
  Value 97: File2 > File1 by 0.283399
  Value 98: File1 > File2 by 0.375046
  Value 99: File2 > File1 by 0.396693
  Value 100: File1 > File2 by 0.726444
  Value 101: File2 > File1 by 0.400867
  Value 102: File2 > File1 by 0.802295
  Value 103: File1 > File2 by 0.360492
  Value 104: File2 > File1 by 0.03897
  Value 105: File1 > File2 by 0.305028
  Value 106: File1 > File2 by 0.172017
  Value 107: File2 > File1 by 0.871811
  Value 108: File2 > File1 by 0.60148
  Value 109: File1 > File2 by 0.187111
  Value 110: File2 > File1 by 0.347349
  Value 111: File2 > File1 by 0.338053
  Value 112: File1 > File2 by 0.095033
  Value 113: File2 > File1 by 0.303109
  Value 114: File2 > File1 by 0.354296
  Value 115: File1 > File2 by 0.061933
  Value 116: File1 > File2 by 0.237379
  Value 117: File2 > File1 by 0.458172
  Value 118: File1 > File2 by 0.1908
  Value 119: File1 > File2 by 0.755646
  Value 120: File1 > File2 by 0.227695
  Value 121: File2 > File1 by 0.197345
  Value 122: File1 > File2 by 0.508579
  Value 123: File2 > File1 by 0.278425
  Value 124: File2 > File1 by 0.329463
  Value 125: File1 > File2 by 0.774398
  Value 126: File2 > File1 by 0.562082
  Value 127: File1 > File2 by 0.470175
  Value 128: File2 > File1 by 0.05593
  Value 129: File1 > File2 by 0.613415
  Value 130: File2 > File1 by 0.162522
  Value 131: File1 > File2 by 0.009247
  Value 132: File1 > File2 by 0.005662
  Value 133: File1 > File2 by 0.43483
  Value 134: File2 > File1 by 0.662557
  Value 135: File2 > File1 by 0.171568
  Value 136: File1 > File2 by 0.789997
  Value 137: File1 > File2 by 0.666768
  Value 138: File2 > File1 by 0.284002
  Value 139: File1 > File2 by 0.117424
  Value 140: File2 > File1 by 0.235303
  Value 141: File1 > File2 by 0.152445
  Value 142: File2 > File1 by 0.399506
  Value 143: File2 > File1 by 0.31032
  Value 144: File1 > File2 by 0.818246
  Value 145: File1 > File2 by 0.290348
  Value 146: File2 > File1 by 0.078317
  Value 147: File1 > File2 by 0.468518
  Value 148: File2 > File1 by 0.511484

=== OverlappingTemplate ===
File1 Values:  [0.425838]
File2 Values:  [0.846736]
  Value 1: File2 > File1 by 0.420898

=== RandomExcursions ===
File1 Values:  [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
File2 Values:  [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
  Value 1: Equal
  Value 2: Equal
  Value 3: Equal
  Value 4: Equal
  Value 5: Equal
  Value 6: Equal
  Value 7: Equal
  Value 8: Equal

=== RandomExcursionsVariant ===
File1 Values:  [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
File2 Values:  [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
  Value 1: Equal
  Value 2: Equal
  Value 3: Equal
  Value 4: Equal
  Value 5: Equal
  Value 6: Equal
  Value 7: Equal
  Value 8: Equal
  Value 9: Equal
  Value 10: Equal
  Value 11: Equal
  Value 12: Equal
  Value 13: Equal
  Value 14: Equal
  Value 15: Equal
  Value 16: Equal
  Value 17: Equal
  Value 18: Equal

=== Rank ===
File1 Values:  [0.050477]
File2 Values:  [0.742489]
  Value 1: File2 > File1 by 0.692012

=== Runs ===
File1 Values:  [0.890207]
File2 Values:  [0.35024]
  Value 1: File1 > File2 by 0.539967

=== Serial ===
File1 Values:  [0.208604, 0.501945]
File2 Values:  [0.492753, 0.477897]
  Value 1: File2 > File1 by 0.284149
  Value 2: File1 > File2 by 0.024048

=== Universal ===
File1 Values:  [0.783455]
File2 Values:  [0.225704]
  Value 1: File1 > File2 by 0.557751
```
## Key Findings:

File 1 = Original LEA
File 2 = Modified LEA + Sbox
1. **Approximate Entropy**: File 1 (0.450521) has higher entropy than File 2 (0.287752), indicating that File 1 is more unpredictable and thus potentially better for encryption in terms of entropy. 
2. **Block Frequency**: File 2 (0.45667) performs better than File 1 (0.368814), suggesting that File 2 has a more uniform distribution of blocks, which can be beneficial for encryption. ✅
3. **Cumulative Sums**: File 2 shows a higher value in one of the tests (0.581218), indicating better performance in this aspect. ✅
4. **FFT**: File 2 (0.356244) outperforms File 1 (0.230943), suggesting that File 2 might have less periodic patterns, which is desirable. ✅
5. **Frequency**: File 1 (0.976059) significantly outperforms File 2 (0.45855), indicating that File 1 has a more uniform distribution of bits, which is crucial for encryption.
6. **Linear Complexity**: File 1 (0.765439) is higher than File 2 (0.630303), suggesting that File 1 might be more resistant to linear attacks.
7. **Longest Run**: File 2 (0.926421) performs better than File 1 (0.636065), indicating that File 2 has longer sequences without repetition, which can be beneficial. ✅
8. **NonOverlappingTemplate**: File 2 generally shows better performance across many values, indicating a more complex pattern. ✅
9. **OverlappingTemplate**: File 2 (0.846736) significantly outperforms File 1 (0.425838), suggesting better randomness in overlapping sequences. ✅
10. **Rank**: File 2 (0.742489) is much higher than File 1 (0.050477), indicating that File 2 has a better distribution of ranks, which is important for encryption. ✅
11. **Runs**: File 1 (0.890207) outperforms File 1 (0.35024), suggesting that File 1 has fewer runs of consecutive bits, which can be beneficial for encryption.
12. **Serial**: File 2 performs slightly better in one test but worse in another. ✅
13. **Universal**: File 1 (0.783455) outperforms File 2 (0.225704), indicating that File 1 might be more unpredictable in a universal statistical test.
    
Total Test = 13
File 1 Better  = 5/13
File 2 Better = 8/13 ✅
## Conclusion:

Both algorithms have strengths and weaknesses. **File 1 (Original LEA)** excels in terms of entropy, frequency, linear complexity, and universality, which are important for encryption. However, **File 2 (Modified LEA + SBOX)** shows better performance in block frequency, cumulative sums, FFT, longest run, non-overlapping template, overlapping template, and rank tests, indicating improved randomness and complexity.

For encryption purposes, **File 1** might be considered better if predictability and uniformity are prioritized, while **File 2** could be preferred if complexity and resistance to certain statistical attacks are more important. Ultimately, the choice depends on the specific security requirements and threat models of the application.

---

# Scripts to Test Encryption/Decryption Time and Entropy

#### Test Encryption Time
```python
import time
start = time.time()
ciphertext = encrypt_img_data(img_data, key)
end = time.time()
print("Encryption Time:" , end-start)
```

### Test Decryption Time
```python
start = time.time()
plaintext = decrypt_img_data(encrypted_img_data, key)
end = time.time()
print("Decryption Time:", end-start)
```

### Test Entropy
```python
import numpy as np
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
import cv2
import os

# Function to calculate entropy
def calculate_entropy(data):
    # Calculate the frequency of each byte value
    value_counts = np.bincount(np.frombuffer(data, dtype=np.uint8))

    # Calculate the probability of each byte value
    probabilities = value_counts / len(data)

    # Calculate entropy using the formula: H(X) = -Σ p(x) * log2(p(x))
    entropy = -np.sum(probabilities * np.log2(probabilities + np.finfo(float).eps))

    return entropy

encrypted_data = encrypt_img_data(img_data, key)
entropy = calculate_entropy(encrypted_data)
print(f"Entropy of encrypted data (LEA+SBOX): {entropy} bits/byte")

```

**Modified LEA+SBOX :**
```
Encryption Time (LEA+SBOX): 0.33358144760131836
Decryption Time (LEA+SBOX): 0.3326265811920166
Entropy of encrypted data (LEA+SBOX): 7.996055672150714 bits/byte
```

**LEA Original :**
```
Encryption Time (Original LEA): 0.2222888469696045
Decryption Time (Original LEA): 0.23563313484191895
Entropy of encrypted data (Original LEA): 7.99678919073556 bits/byte
```

#### Performance Metrics

1. **Encryption Time**:
    - **Modified LEA + SBOX**: 0.333581 seconds
    - **Original LEA**: 0.222288 seconds
    - **Original LEA** is faster by approximately 0.111 seconds.
        
2. **Decryption Time**:
    - **Modified LEA + SBOX**: 0.332627 seconds
    - **Original LEA**: 0.235633 seconds
    - **Original LEA** is faster by approximately 0.097 seconds.
        
3. **Entropy**:
    - **Modified LEA + SBOX**: 7.996056 bits/byte
    - **Original LEA**: 7.996789 bits/byte
    - **Original LEA** has slightly higher entropy, indicating slightly better randomness.
        
---

# Conclusion


- **Original LEA** is faster and has slightly higher entropy, better frequency, linear complexity, and universality, making it suitable for applications requiring speed and predictability.
    
- **Modified LEA + SBOX** offers better performance in ==block frequency==, ==cumulative sums==, ==FFT==, ==longest run==, ==non-overlapping template==, ==overlapping template==, and ==rank tests==, suggesting improved randomness and complexity, which might be beneficial for applications prioritizing these aspects.