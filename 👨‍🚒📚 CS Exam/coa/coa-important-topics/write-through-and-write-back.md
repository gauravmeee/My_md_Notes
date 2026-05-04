## **Write Through & Write Back**

**Definitions**

* **Write Through:** Every write operation <mark>updates both the cache (if present) and the main memory.</mark>
* **Write Back:** Write operations <mark>update only the cache</mark>; the main memory is updated later when the block is replaced (if dirty).
* **Write Allocate:** On a write miss, the block is first loaded into cache, then written into.
* **No-write Allocate:** On a write miss, data is written directly to memory without loading the block into cache.

**1. Write Through (No-write Allocate)**

* **Read**
  * **Hit:** Take directly from cache.
  * **Miss:** Read from memory and place the block into cache.
* **Write**
  * **Hit:** <mark>Write in both cache and main memory</mark> **(Write Through)**.
  * **Miss:** <mark>Write directly to main memory</mark> without bringing the block into cache **(No-write Allocate)**.

**2. Write Back (Write Allocate)**

* **Read**
  * **Hit:** Take directly from cache.
  * **Miss:** Read from memory; if the block being replaced is dirty, write it back to memory before replacement.
* **Write**
  * **Hit:** <mark>Write in cache and set **Dirty bit = 1**</mark> **(Write Back)**.
  * **Miss:** <mark>Bring block from main memory into cache, then update it in cache</mark> **(Write Allocate)**.