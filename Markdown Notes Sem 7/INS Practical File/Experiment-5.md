
<h1 align="center">EXPERIMENT-4</h1>

#### Aim: 
To implement a program to show encryption and decryption using Hill Cipher

### Theory:

Hill cipher is a polygraphic substitution cipher based on linear algebra. Each letter is represented by a number modulo 26. Often the simple scheme A-0, B1, ..., Z-25 is used, but this is not an essential feature of the cipher. To encrypt a message, each block of n letters (considered as an n-component vector) is multiplied by an invertible `nxn` matrix, against modulus 26. To decrypt the message, each block is multiplied by the inverse of the matrix used for encryption. The matrix used for encryption is the cipher key, and it should be chosen randomly from the set of invertible `nxn` matrices (modulo 26)

**Encryption**
In order to encrypt a message using the Hill cipher, the sender and receiver must first agree upon a key matrix A of size n x n. A must be invertible mod 26. The plaintext will then be enciphered in blocks of size n. In the following example A is a `3x3` matrix and the message will be enciphered in blocks of `3` characters.

$$
\begin{bmatrix} 2 & 1 & 1 \\ 3 & 2 & 3 \\ 2 & 1 & 2 \end{bmatrix} \times \begin{bmatrix} A \\ L \\ L \end{bmatrix} \equiv 
\begin{bmatrix} 2 & 1 & 1 \\ 3 & 2 & 3 \\ 2 & 1 & 2 \end{bmatrix} \times \begin{bmatrix} 0 \\ 11 \\ 11 \end{bmatrix} \equiv 
\begin{bmatrix} 22 \\ 3 \\ 7 \end{bmatrix} \pmod{26} \equiv 
\begin{bmatrix} W \\ D \\ H \end{bmatrix}
$$

**Decryption**
Decryption follows Encryption but uses the inverse of the encryption matrix instead.
$$
\begin{bmatrix} 2 & 1 & 1 \\ 3 & 2 & 3 \\ 2 & 1 & 2 \end{bmatrix}^{-1} \times 
\begin{bmatrix} W \\ D \\ H \end{bmatrix} \equiv 
\begin{bmatrix} 4 & 9 & 15 \\ 15 & 17 & 6 \\ 24 & 0 & 1 \end{bmatrix} \times 
\begin{bmatrix} 22 \\ 3 \\ 7 \end{bmatrix} \equiv 
\begin{bmatrix} 0 \\ 11 \\ 11 \end{bmatrix} \pmod{26} \equiv 
\begin{bmatrix} A \\ L \\ L \end{bmatrix}
$$

### Code:
```cpp
#include <iostream>
#include <cmath>
using namespace std;

float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];

void GetKeyMatrix() {
    cout << "Enter 3x3 matrix for key (should have inverse):\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
            m[i][j] = a[i][j];
        }
    }
    char mess[3];
    cout << "Enter a string of 3 letters (A to Z): ";
    cin >> mess;
    for(int i = 0; i < 3; i++) {
        msg[i][0] = mess[i] - 'A';
    }
}

void encrypt() {
    // Initialize en matrix to 0
    for(int i = 0; i < 3; i++) {
        en[i][0] = 0;
    }
    // Matrix multiplication
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 1; j++) {
            for(int k = 0; k < 3; k++) {
                en[i][j] = en[i][j] + a[i][k] * msg[k][j];
            }
        }
    }
    cout << "Encrypted string is: ";
    for(int i = 0; i < 3; i++) {
        cout << (char)(fmod(en[i][0], 26) + 'A');
    }
    cout << endl;
}

void inversematrix() {
    float p, q;
    // Initialize the inverse matrix as identity matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    }
    // Gauss-Jordan elimination
    for(int k = 0; k < 3; k++) {
        for(int i = 0; i < 3; i++) {
            p = m[i][k];
            q = m[k][k];
            for(int j = 0; j < 3; j++) {
                if(i != k) {
                    m[i][j] = m[i][j] * q - p * m[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }
    // Normalize the inverse matrix
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            b[i][j] = b[i][j] / m[i][i];
        }
    }
    cout << "Inverse Matrix is:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

void decrypt() {
    // Initialize de matrix to 0
    for(int i = 0; i < 3; i++) {
        de[i][0] = 0;
    }
    inversematrix();
    // Matrix multiplication with inverse
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 1; j++) {
            for(int k = 0; k < 3; k++) {
                de[i][j] = de[i][j] + b[i][k] * en[k][j];
            }
        }
    }
    cout << "Decrypted string is: ";
    for(int i = 0; i < 3; i++) {
        cout << (char)(fmod(fmod(de[i][0], 26) + 26, 26) + 'A');
    }
    cout << endl;
}

int main() {
    GetKeyMatrix();
    encrypt();
    decrypt();
    return 0;
}
```

### Output:
![[Image Output 5.png]]