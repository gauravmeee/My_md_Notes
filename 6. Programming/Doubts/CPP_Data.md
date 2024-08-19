
#### NULL & nullptr
`NULL`
 is an integer constant typically defined as `0`, which can lead to type ambiguity.

`nullptr` is a keyword introduced in C++11 that represents a null pointer of type std::nullptr_t, providing type safety.

---

### Common Integers in  C++

- **`int`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 4 bytes (32 bits), but may vary by platform.
  - **Range**: Generally −2,147,483,648 to 2,147,483,647 (32-bit).

- **`unsigned int`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 4 bytes (32 bits), like `int`.
  - **Range**: Generally 0 to 4,294,967,295 (32-bit).

- **`size_t`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Varies by platform; typically 4 bytes on 32-bit systems, 8 bytes on 64-bit systems.
  - **Range**: Large enough to hold the size of any object in memory, platform-dependent.

- **`short`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 2 bytes (16 bits).
  - **Range**: Generally −32,768 to 32,767.

- **`unsigned short`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 2 bytes (16 bits).
  - **Range**: Generally 0 to 65,535.

- **`long`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: Typically 4 bytes (32 bits) on 32-bit systems, 8 bytes (64 bits) on 64-bit systems.
  - **Range**: On a 32-bit system, typically −2,147,483,648 to 2,147,483,647; on a 64-bit system, it extends to a larger range.

- **`unsigned long`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: Typically 4 bytes (32 bits) or 8 bytes (64 bits).
  - **Range**: Varies with size; e.g., 0 to 4,294,967,295 (32-bit) or larger (64-bit).

- **`long long`**:
  - **Signed**: Can represent both positive and negative values.
  - **Size**: At least 8 bytes (64 bits).
  - **Range**: Generally −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (64-bit).

- **`unsigned long long`**:
  - **Unsigned**: Can only represent non-negative values.
  - **Size**: At least 8 bytes (64 bits).
  - **Range**: Generally 0 to 18,446,744,073,709,551,615 (64-bit).