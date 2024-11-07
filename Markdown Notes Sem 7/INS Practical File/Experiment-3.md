
<h1 align="center">EXPERIMENT-3</h1>

#### Aim: 
To implement a program to show encryption and decryption through Play-Fair Cipher
### Theory:

The Playfair cipher is a **manual symmetric encryption technique** and was the first known substitution cipher to encrypt pairs of letters, rather than single letters like traditional ciphers. The Playfair cipher is based on a **5x5 matrix** of letters. The letters of the alphabet are filled into the matrix, excluding the letter 'J' (or another letter, as decided). The ciphertext is formed by encrypting pairs of letters, where each pair of letters is replaced based on their position in the matrix.

**Steps:**

1. **Key Table Generation**:
    - The key is used to create a 5x5 grid.
    - A unique sequence of letters is placed in the grid (duplicates are removed).
    - The letter 'J' is omitted or replaced by 'I' (both represent the same position).
2. **Encryption**:
    - Each pair of plaintext letters is processed by their positions in the table.
    - If the letters are in the same row, they are replaced by the letters immediately to their right.
    - If the letters are in the same column, they are replaced by the letters immediately below.
    - Otherwise, each letter is replaced by the letter in its row and column of the other letter.
3. **Decryption**:
    - The process is reversed to get back the original plaintext.
### Code:

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Playfair {
private:
    string key;
    char matrix[5][5];
    map<char, pair<int, int>> charPos;
    void createMatrix() {
        bool used[26] = {false};
        int row = 0, col = 0;
        // Convert key to lowercase and remove duplicates
        for (char& c : key) {
            c = tolower(c);
            if (c == 'j') c = 'i';
        }
        // Add key to matrix
        for (char c : key) {
            if (!used[c - 'a']) {
                matrix[row][col] = c;
                charPos[c] = make_pair(row, col);
                used[c - 'a'] = true;
                col++;
                if (col == 5) {
                    col = 0;
                    row++;
                }
            }
        }
        // Fill remaining spaces
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == 'j') continue;
            if (!used[c - 'a']) {
                matrix[row][col] = c;
                charPos[c] = make_pair(row, col);
                col++;
                if (col == 5) {
                    col = 0;
                    row++;
                }
            }
        }
    }

    pair<char, char> cipher_pair(char a, char b, bool encrypting) {
        // Convert to lowercase and handle j
        a = tolower(a);
        b = tolower(b);
        if (a == 'j') a = 'i';
        if (b == 'j') b = 'i';
        int row1 = charPos[a].first, col1 = charPos[a].second;
        int row2 = charPos[b].first, col2 = charPos[b].second;
        if (row1 == row2) {  // same row
            if (encrypting) {
                col1 = (col1 + 1) % 5;
                col2 = (col2 + 1) % 5;
            } else {
                col1 = (col1 + 4) % 5;
                col2 = (col2 + 4) % 5;
            }
        }
        else if (col1 == col2) {  // same column
            if (encrypting) {
                row1 = (row1 + 1) % 5;
                row2 = (row2 + 1) % 5;
            } else {
                row1 = (row1 + 4) % 5;
                row2 = (row2 + 4) % 5;
            }
        }
        else {  // rectangle case
            swap(col1, col2);
        }
        return make_pair(matrix[row1][col1], matrix[row2][col2]);
    }
public:
    Playfair(string key) : key(key) {
        createMatrix();
    }
    string encipher(string plainText) {
        string text = plainText;
        // Remove non-alphabetic characters and convert to lowercase
        string cleaned;
        for (char c : text) {
            if (isalpha(c)) {
                cleaned += tolower(c);
            }
        }
        text = cleaned;
        // Add 'x' between double letters and at the end if needed
        for (size_t i = 0; i < text.length(); i += 2) {
            if (i + 1 == text.length()) {
                text += 'x';
            }
            else if (text[i] == text[i + 1]) {
                text.insert(i + 1, "x");
            }
        }
        string result;
        for (size_t i = 0; i < text.length(); i += 2) {
            pair<char, char> p = cipher_pair(text[i], text[i + 1], true);
            result += p.first;
            result += p.second;
        }
        return result;
    }
    string decipher(string cipherText) {
        string result;
        for (size_t i = 0; i < cipherText.length(); i += 2) {
            pair<char, char> p = cipher_pair(cipherText[i], cipherText[i + 1], false);
            result += p.first;
            result += p.second;
        }
        return result;
    }
};

int main() {
    string key;
    
    cout << "Enter the key: ";
    getline(cin, key);  // Allow user to input the key
    Playfair p(key);
    string plainText;
    cout << "Enter the plain text: ";
    getline(cin, plainText);
    string encrypted = p.encipher(plainText);
    string decrypted = p.decipher(encrypted);
    cout << "Original text: " << plainText << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;
    return 0;
}
```

### Output:
![[Image Output 3.png]]