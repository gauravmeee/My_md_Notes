
# [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)
```
Input: 
s = "the sky is blue"

Output:
"blue is sky the"
```

By Me :)
```cpp
string reverseWords(string s) {
	int n = s.length();
	int i = 0;  // starting position of every word
	string result = ""; // empty string

	while (i < n) {
		// Skip spaces until 'i' point to starting of word
		while (i < n && s[i] == ' ') {
			i++;
		}
		
		// count the length of the current word
		int cnt = 0;
		while (i+cnt < n && s[i+cnt] != ' ') {
			cnt++;
		}

		// If cnt>0 , that is there is word not whitespace or ending ⭐
		if(cnt!=0){
			string word = s.substr(i, cnt); // substr(start_pos, length)
			// if result already have word, give space(" ") before adding next word
			result = result == "" ? word : word + " " + result;
		}
		
		// Move to the next word
		i = i + cnt;
	}
	return result;
}

// TC -> O(n)
// SC -> O(n)
```

by [Reverse Words in a String | LeetCode 151 | C++, Java, Python](https://www.youtube.com/watch?v=vhnRAaJybpA&ab_channel=KnowledgeCenter)
```cpp
string reverseWords(string s) {
	int n = s.length();
	int i = 0; // starting position of every word
	string result = ""; // empty string

	while (i < n) {
		// Skip spaces until 'i' point to starting of word
		while (i < n && s[i] == ' ') {
			i++;
		}

		if (i >= n) break; // execute when string ending with " " ⭐

		// next index of word end.
		int j = i;
		while (j < n && s[j] != ' ') {
			j++;
		}
		// size of string  = end_ind - start_ind + 1
		// but here j+1 out of bound i.e s[j]=' ' we will consider last index = j-1
		string word = s.substr(i, j - i); // substr(start_pos, length)

		if (result.length() == 0) result = word;
		else result = word + " " + result;

		// Move to the next word
		i = j;
	}

	return result;
}

// TC -> O(n)
// SC -> O(n)
```

---

# [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

By me :)

```cpp
#define for_up(n) for(int i=0; i<n ; i++)
string longestPalindrome(string s) {
	int n=s.length();
	int l,r,temp; // l : starting of sub-string, r : ending of sub-string
	int si=0; // Store the longest length of palindromic substring
	string ans="";

	for_up(n){
		// for odd length palindrome : s[i-1] = <i> = s[i-2]
		l = i, r = i, temp=0 ;
		// considering s[i] as center, expand it left and right
		while(l-1>=0 and r+1<n and s[l-1]==s[r+1]){
			temp++;
			l--;
			r++;
		}

		temp=temp*2+1; // size = [j-i+1] or temp*2 + 1
		if(temp>=si){
			si = temp; // si = max(temp, si)
			ans = s.substr(l,temp);
		}
		
		// for even length palindrome  : s[i]=s[i+1]
		l = i, r = i+1, temp=0 ;
		// consindering s[i] and s[i+1] expand it left and right
		while(l>=0 and r<n and s[l]==s[r]){
			temp++;
			l--;
			r++;
		}

		temp=temp*2; //  = [j-i+1]
		if(temp>=si){
			si = temp; // si = max(temp, si)
			ans = s.substr(l+1,temp);
		}
	}
	return ans;
}

// TC -> O(n^2)
// SC -> O(1)
```


by [Longest Palindromic Substring - Python - Leetcode 5](https://www.youtube.com/watch?v=XYQecbcd6_c&ab_channel=NeetCode)
```python
def longestPalindrome(self, s):
        res = ""
        
        for i in range(len(s)):

            # for odd length
            l,r =i,i
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if(r-l+1>len(res)):
                    res = s[l:r+1]
                l-=1
                r+=1

             # for even length
            l,r =i, i+1
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if(r-l+1>len(res)):
                    res = s[l:r+1]
                l-=1
                r+=1

        return res

# TC -> O(n^2)
# SC -> O(1)
```

---

### **Ques.** Write a C++ program to find the **word with the highest frequency** in a given string. If multiple words have the same maximum frequency, print the one that appears **first** in the string.
 
Input:  
```
"apple banana apple orange banana apple"
```

Output:  
```
apple
```

**Constraints:**
- The input string contains only lowercase English letters and spaces.
- Words are separated by a single space.

**Solution by GPT** ⭐
```cpp
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

string maxFreqWord(string str) {
    unordered_map<string, int> freq;
    stringstream ss(str);
    string word, maxWord;
    int maxFreq = 0;

    while (ss >> word) {
        freq[word]++;
        if (freq[word] > maxFreq) {
            maxFreq = freq[word];
            maxWord = word;
        }
    }
    return maxWord;
}

int main() {
    string s = "apple banana apple orange banana apple";
    cout << "Max frequency word: " << maxFreqWord(s);
    return 0;
}
```

**Note:** `>>` Operator in `while (ss >> word)`
- the `>>` is the **stream extraction operator** (same as in `cin >> x`).
- `ss` is a `stringstream` initialized with the input string.
- `ss >> word` extracts the **next word** (separated by whitespace) from the stream and stores it in the variable `word`.
    