---
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# 🤖 Notes+GPT\_Python Regex Implementation

The logic of writing a regex (regular expression) formula lies in understanding **patterns** in the data you want to match. Here’s a step-by-step guide:

1. **Understand the Data**

Analyze the format of the data you want to match:

* Is it a **fixed format** (e.g., phone numbers: `123-456-7890`)?
* Does it have **variable parts** (e.g., names: `John`, `John Doe`)?
* Are there any **common delimiters** (e.g., `/`, `-`, `.`)?

2. **Break Down the Data**

Identify individual parts of the pattern:

* **Characters**: Letters, digits, special symbols.
* **Length**: Fixed length or variable length.
* **Repetition**: Is something repeated? (e.g., multiple digits).
* **Optional Parts**: Are any parts optional?

3. **Build the Regex Step-by-Step**

Use **special characters** and **quantifiers** to describe the data.

**Common Regex Components**

| Character/Pattern   | Description                                                                                                         | Example                                 |
| ------------------- | ------------------------------------------------------------------------------------------------------------------- | --------------------------------------- |
| \|                  | Represents the `OR` operator.                                                                                       | Logical OR                              |
| `.`                 | Matches any single character except a newline character.                                                            | `a.b` matches `aab`, `acb`              |
| `\` (without `r""`) | Escapes a special character (if not used `r` prefix i.e. raw string)                                                | `\.` matches `.` literally              |
| `\`                 | Indicates that the next character is a literal.                                                                     |                                         |
| `\d`                | Matches a digit (`0-9`)                                                                                             | `\d{3}` matches `123`                   |
| `\b`                | **Word Boundary Anchor:** Matches the position **between** a word character (`\w`) and a non-word character (`\W`). | `\bcat\b` Matches `cat` as a whole word |
| `\w`                | Matches a word character (`a-z`, `A-Z`, `0-9`, `_`)                                                                 | `\w+` matches `hello123`                |
| `\s`                | Matches whitespace                                                                                                  | `\s` matches a space or tab             |
| `[]`                | Indicates a character set or range of characters.                                                                   | `[aeiou]` matches any vowel             |
| `^`                 | Matches the beginning of the input string.                                                                          | `^Hello` matches `Hello world`          |
| `$`                 | Matches the end of the string                                                                                       | `world$` matches `Hello world`          |
| `*`                 | Matches the preceding character zero or more times.                                                                 | `a*` matches `aaa` or empty             |
| `+`                 | Matches the preceding character one or more times.                                                                  | `a+` matches `aaa` but not empty        |
| `?`                 | Matches the preceding character zero or one time.                                                                   | `a?` matches `a` or empty               |
| `()`                | Groups patterns                                                                                                     | `(abc)+` matches `abcabc`               |
| `{}`                | Identifies a range for matching patterns.                                                                           |                                         |
| `{n}`               | Matches exactly `n` repetitions                                                                                     | `a{3}` matches `aaa`                    |
| `{n,m}`             | Matches between `n` and `m` repetitions                                                                             | `a{1,3}` matches `a`, `aa`, `aaa`       |
| **Note:**           |                                                                                                                     |                                         |

* `r` → **Raw string** → Treats backslashes (`\`) as literal characters.
* `/` → **Literal slash** → Matches the `/` character.

**Examples**

**1. Phone Number**

* Match formats like `123-456-7890`:
* Three digits, a hyphen, three digits, another hyphen, and four digits.

```regex
    \d{3}-\d{3}-\d{4}
```

**2. Email Address**

* Match formats like `user@example.com`:
* Word characters (`\w`) or `.` before `@`.
* A domain name with a `.com`, `.org`, etc.

```regex
\b\w+(\.\w+)*@\w+\.\w+\b
```

**3. Date**

* Match formats like `DD/MM/YYYY` or `YYYY-MM-DD`:
* Two digits, separator (`/` or `-`), two digits, separator, four digits.

```regex
(\d{2}[-/]\d{2}[-/]\d{4})
	or 
(\d{4}[-/]\d{2}[-/]\d{2})
```

***

**Test Your Regex:**

* Use online tools like [Regex101](https://regex101.com/) or [Pythex](https://pythex.org/) to test your regex.
*   In Python, you can test it like this:

    ```python
    import re

    pattern = r'\d{3}-\d{3}-\d{4}'
    text = "Call me at 123-456-7890 or 987-654-3210."
    matches = re.findall(pattern, text)
    print(matches)  # Output: ['123-456-7890', '987-654-3210']
    ```

**Key tips:**

* Start small and incrementally refine the regex.
* Use `\` to escape special characters like `.`, `?`, `*`, etc.
* Always test with different edge cases (e.g., invalid inputs).

By analyzing the structure of the data and applying these components, you can write any regex formula!
