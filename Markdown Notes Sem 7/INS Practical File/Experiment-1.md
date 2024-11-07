
<h1 align="center">EXPERIMENT-1</h1>

#### Aim: 
To implement a program to show encryption and decryption through Caesar Ciphers

### Theory:

The Caesar Cipher, also known as a shift cipher, is one of the earliest and simplest encryption techniques. This method of encryption involves replacing each letter in a message (referred to as *plaintext*) with a different letter that is a fixed number of positions shifted within the alphabet. 

For the **Encryption** Process a message, each letter in the plaintext is shifted according to a numerical key. For example, if the letter "C" is at position 3 in the alphabet, a key of +3 would shift "C" forward three positions to become "F." This shift is applied uniformly to every letter in the plaintext, resulting in an encoded message, or *ciphertext*. If shifting reaches the end of the alphabet, it wraps around to the beginning (e.g., shifting "Z" by +1 results in "A").

![[Image Theory 1.png]]

**Decryption**, or reversing the encryption process, is achieved by shifting each letter in the ciphertext backward by the same key value. For instance, with a key of +3, shifting an "F" by -3 returns to the original "C." This simplicity of the Caesar Cipher makes it an excellent starting point for understanding cryptographic principles, though it is not secure by modern standards.

### Code:

```
#include <iostream>
using namespace std;

string encode(string pt, int key) {
    string result = "";
    for (int i = 0; i < pt.length(); i++) {
        if (isupper(pt[i])) {
            result += char((pt[i] + key - 65) % 26 + 65);
        } else if (islower(pt[i])) {
            result += char((pt[i] + key - 97) % 26 + 97);
        } else {
            result += pt[i];  // Non-alphabet characters remain the same
        }
    }
    return result;
}

string decode(string ct, int key) {
    string result = "";
    for (int i = 0; i < ct.length(); i++) {
        if (isupper(ct[i])) {
            result += char((ct[i] - key - 65 + 26) % 26 + 65);
        } else if (islower(ct[i])) {
            result += char((ct[i] - key - 97 + 26) % 26 + 97);
        } else {
            result += ct[i];  // Non-alphabet characters remain the same
        }
    }
    return result;
}

int main() {
    string pt, encoded, decoded;
    int key;

    cout << "Input the plain text: ";
    getline(cin, pt);
    cout << "Input the key value: ";
    cin >> key;
    encoded = encode(pt, key);
    cout << "**************************************************************" << endl;

    cout << "Encoded cipher text: " << encoded << endl;
    decoded = decode(encoded, key);
    cout << "Decoded plain text: " << decoded << endl;
```

### Output:

![[Image Output 1.png]]

