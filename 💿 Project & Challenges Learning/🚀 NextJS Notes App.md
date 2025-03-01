
## Split Slug automatically try

---

Javascript
`str.trim()` -> remove whitespace from both end `trimStart()` and `trimEnd()`

`str.split(" ").join();`

1. **Spaces**: Spaces should be replaced with hyphens (`-`).
2. **Special Characters**: Characters like `!`, `@`, `#`, `$`, `%`, `^`, `&`, `*`, `(`, `)`, `+`, `=`, `{`, `}`, `[`, `]`, `|`, `\`, `:`, `;`, `"`, `'`, `<`, `>`, `,`, `?`, `/`, and `~` should be avoided.
3. **Accented Characters**: Characters with accents or diacritics should be converted to their unaccented equivalents (e.g., `é` to `e`).

A typical approach to generating slugs is to:

- Convert the string to lowercase.
- Replace spaces with hyphens.
- Remove or replace special characters.


---
```
/[\s+&]/g
```

- `[...]` → Defines a **character class** that matches any one of the specified characters.
- `\s` → Matches any whitespace (spaces, tabs, newlines).
- `+` → Matches the `+` symbol.
- `&` → Matches the `&` symbol.
- `g` → **Global flag** to match all occurrences.

---

```javascript
str.replace(/[\s+&]/g, '');
```
Replace all (`global`) space, new line' to `''`  

---

A **slug-friendly** string typically contains:

- **Lowercase letters** (`a-z`)
- **Numbers** (`0-9`)
- **Hyphens** (`-`)

To match all **non-slug-friendly** characters, use this regular expression:

```
/[^a-z0-9-]/gi
```

### Breakdown:

- `[^...]` → **Negates** the character class (matches anything **not** listed).
- `a-z` → Matches **lowercase** letters.
- `0-9` → Matches **digits**.
- `-` → Matches the **hyphen** (allowed in slugs).
- `g` → **Global** flag (matches all occurrences).
- `i` → **Case-insensitive** (allows uppercase letters too).

### Example:

```javascript
let str = "Hello! World@ 2024++Slug-Test";
let result = str.replace(/[^a-z0-9-]/gi, '');
console.log(result); // Output: "HelloWorld2024-Slug-Test"
```

This removes spaces, special characters (`! @ +`), while keeping alphanumeric characters and hyphens.

---