

### LEA+ S-BOX Algorithm
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
def encrypt_image(data: bytes, key: bytes) -> bytes:
    data = pad(data)
    round_keys = generate_round_keys(key)
    encrypted = b''.join(lea_encrypt_block(data[i:i+16], round_keys) for i in range(0, len(data), 16))
    return encrypted

def decrypt_image(data: bytes, key: bytes) -> bytes:
    round_keys = generate_round_keys(key)
    decrypted = b''.join(lea_decrypt_block(data[i:i+16], round_keys) for i in range(0, len(data), 16))
    return unpad(decrypted)

# --- MAIN ---
image_path = './lung.png'
image_bytes, shape = image_to_bytes(image_path)
key = os.urandom(16)  # 128-bit key

# # Encrypt
# enc = encrypt_image(image_bytes, key)
# with open("encrypted_lea_sbox.bin", "wb") as f: f.write(enc)
# cv2.imwrite("encrypted_image.png", bytes_to_image(enc[:np.prod(shape)], shape))

# # Decrypt
# with open("encrypted_lea_sbox.bin", "rb") as f: enc_data = f.read()
# dec = decrypt_image(enc_data, key)
# cv2.imwrite("decrypted_image.png", bytes_to_image(dec, shape))

# print("Displaying the decrypted image for timing measurement.")
# # Convert to an image and display/save
# cv2.imshow('LEA Encrypted Image', bytes_to_image(enc[:np.prod(shape)], shape))
# cv2.imshow('LEA Decrypted Image', bytes_to_image(dec, shape))
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# print("Process completed successfully.")
```
### Encryption time Calculate
```python
import time

start = time.time()
ciphertext = encrypt_image(image_bytes, key)
end = time.time()

print("Encryption Time:" , end-start)
```
### Decryption Time Calculate
```python

start = time.time()
plaintext = decrypt_image(ciphertext, key)
end = time.time()
print("Decryption Time:", end-start)
```
### Entropy Check
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



encrypted_data = encrypt_image(image_bytes, key)


chacha20_entropy = calculate_entropy(encrypted_data)

print(f"Entropy of encrypted data (LEA+SBOX): {chacha20_entropy} bits/byte")


```
