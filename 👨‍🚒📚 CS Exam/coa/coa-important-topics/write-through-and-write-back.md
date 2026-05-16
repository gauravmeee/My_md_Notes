---
title: Write Through & Write Back
---

**Definitions**

* **Write Through:** Every write operation ==updates both the cache (if present) and the main memory.==
* **Write Back:** Write operations ==update only the cache==; the main memory is updated later when the block is replaced (if dirty).
* **Write Allocate:** On a write miss, the block is first loaded into cache, then written into.
* **No-write Allocate:** On a write miss, data is written directly to memory without loading the block into cache.

**1. Write Through (No-write Allocate)**

* **Read**
  * **Hit:** Take directly from cache.
  * **Miss:** Read from memory and place the block into cache.
* **Write**
  * **Hit:** ==Write in both cache and main memory== **(Write Through)**.
  * **Miss:** ==Write directly to main memory== without bringing the block into cache **(No-write Allocate)**.

**2. Write Back (Write Allocate)**

* **Read**
  * **Hit:** Take directly from cache.
  * **Miss:** Read from memory; if the block being replaced is dirty, write it back to memory before replacement.
* **Write**
  * **Hit:** ==Write in cache and set **Dirty bit = 1**== **(Write Back)**.
  * **Miss:** ==Bring block from main memory into cache, then update it in cache== **(Write Allocate)**.