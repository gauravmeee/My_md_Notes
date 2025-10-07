
### Buffer

**Buffer in Lexical Analysis**

- **Purpose:** To read input source code efficiently and provide characters to the lexer.
- Lexical analyzer works on **one character at a time**, but reading file character by character is slow.
- **Buffering** ==improves speed by reading chunks of data at once.==
    

**Common Technique – Two Buffer Scheme:**

1. **Two buffers of size N each** (front and back).
2. **Forward pointer:** Scans characters for the current lexeme.
3. **Lexeme beginning pointer:** Marks the start of the current token.
4. When forward reaches end of first buffer, load second buffer, and vice versa.
5. Helps **recognize tokens spanning across buffer boundary**.
    

**Benefits:**
- Efficient reading from source file.
- Handles large source files without storing whole file in memory.
- Supports lookahead for token recognition.
    
**Flow:**
```text
[Lexeme Begin] ---> [Forward Pointer scanning] ---> End of buffer? ---> Load next buffer if needed
```

I can also draw a **small two-buffer diagram** to make it easy to visualize. Do you want me to?