---
title: Cache Mapping
---

##### 1. Direct Mapping
- Each main memory block maps to exactly one fixed cache line. 
- $\text{Cache Line} = (\text{Block Number}) \bmod (\text{Number of Cache Lines})$

##### 2. Set Associative Mapping
- Cache is divided into sets; a block maps to one set but can occupy any line within that set.
- $\text{Set Number} = (\text{Block Number}) \bmod (\text{Number of Sets})$ 

##### 3. Fully Associative Mapping: 
- Any main memory block can be placed in any cache line.

**Comparisons:**

| Property           | Direct mapped      | Fully associative | k-way set associative |
| ------------------ | ------------------ | ----------------- | --------------------- |
| No. of sets        | = no. of lines     | 1                 | lines / k             |
| Ways per set       | 1                  | = no. of lines    | k                     |
| Index field        | Cache line bits    | None              | Set bits              |
| Tag size           | Smallest           | Largest           | Middle                |
| Hardware cost      | Cheapest           | Most expensive    | Moderate              |
| Conflict misses    | Highest            | None              | Reduced               |
| Search on lookup   | Direct (1 compare) | All lines         | k compares            |
| Replacement policy | Not needed         | Required          | Required              |

**Quick Derivation Steps** (for exam problems)

Given: `Main memory size`, `Cache size`, `Block size`, `k (ways)`.

- **Step 1** - `Offset bits = log₂(block size)`
- **Step 2** -  `No. of MM blocks = MM size / block size` → `MM block bits = log₂(no. of MM blocks`
- **Step 3** -  `No. of cache lines = Cache size / block size`
- **Step 4** - `No. of sets = cache lines / k` → `Set bits = log₂(no. of sets)`
	- If `k = 1` → `set bits = cache line bits` (direct mapped)
	- If `k = all lines` → `set bits = 0` (fully associative)
- **Step 5** - `Tag bits = MM addr bits − set bits − offset bits`
- **Verify:** Tag + Set + Offset = total MM address bits ✓

```
Main Memory Address :
┌──────────────────────────────────────┬────────────────────┐
│          Main Memory Block no        │   Byte Offset      │
└──────────────────────────────────────┴────────────────────┘
         ⬋             ⬊                      ⬇
┌──────────┬───────────────────────────┬────────────────────┐
│     Tag  │         Cache Line        │   Byte Offset      │
└──────────┴───────────────────────────┴────────────────────┘
```

## 1. Direct Mapping

**Formulas :**

* **Offset Bits :** Represent **block size (words/bytes inside a block)**
  * Offset Bits = `log₂(Block Size)`
* **Tag Bits :** Represents **number of main memory blocks** competing for one cache line
  * Tag Bits = `log₂(Memory Size / Cache Size)` or `log₂(No. of Main Memory Blocks / No. of Cache Blocks)`
* **Block No. / Line** : Represent No. of Blocks
  * Main Memory Block Bits = `log₂(No. of Main Memory Blocks)`
  * Cache Line Bits = `log₂(Number of Cache Blocks)`
* **Address Bits :** Represent **addressable memory size**
  * Main Memory Address Bits = `log₂(Main Memory Size)`
  * Cache Memory Address Bits = `log₂(Cache Size)`

**Mental model**

```
• Byte offset for Cache and Main Memory is SAME
  → Block size is SAME
  → MM Block Size = CM Block Size = Block Size

• Main Memory Block Bits ≥ Cache Line Bits
  → No. MM Blocks ≥ No. CM Blocks

• Main Memory Address Bits ≥ Cache Address Bits
  → MM Blocks × Block Size > CM Blocks × Block Size
  → Total Main Memory Size > Total Cache Size

• Tag Bits:
  → For ONE cache block, how many main memory blocks can map to it
  → 2^(Tag Bits) = No. of MM blocks per cache block
```

```
Main Memory Block Number
= [ TAG | INDEX ]

INDEX  → selects the cache line
TAG    → identifies which memory block is in that line
OFFSET → selects data inside the block
```

**Main Memory Address**

```
┌──────────┬───────────────────────────┬────────────────────┐
│     Tag  │         Cache Line        │   Byte Offset      │
└──────────┴───────────────────────────┴────────────────────┘
<---------------- Main Memory Address Bits ---------------->
                           ↓
                  log2(Main Memory Size)


-> Main Memory Address Bits - Offset Bits
	= log₂(Main Memory Size) - log₂(Block Size)
	= log₂(Main Memory Size / Block Size) = 
	= log₂(Number of Main Memory Blocks)
	= Main Memory Block Bits

           
┌──────────┬───────────────────────────┬────────────────────┐
│     Tag  │         Cache Line        │   Byte Offset      │
└──────────┴───────────────────────────┴────────────────────┘
<------- Main Memory Block Bits -------> <--- Offset Bits --->
                 ↓                               ↓
         log₂(No. of Main Memory Blocks)     log₂(Block Size)
```

**Cache Memory Address**

```
┌──────────┬───────────────────────────┬────────────────────┐
│     Tag  │         Cache Line        │   Byte Offset      │
└──────────┴───────────────────────────┴────────────────────┘
           <---------- Cache Memory Address Bits ----------->
                               ↓
                       log2(Cache Memory Size)


-> Cache Memory Address Bits - Offset Bits
	= log₂(Cache Size) - log₂(Block Size)
	= log₂(Cache Size / Block Size) = 
	= log₂(Number of Cache Blocks)
	= Cache Line Bits

           
┌──────────┬───────────────────────────┬────────────────────┐
│     Tag  │         Cache Line        │   Byte Offset      │
└──────────┴───────────────────────────┴────────────────────┘
            <---- Cache Block Bits ---> <--- Offset Bits --->
                         ↓                       ↓
             log₂(No. of Cache Blocks)    log₂(Block Size)
```

---

## 2. Set Associative Mapping (k-way)

### Address Format

```
┌──────────────┬─────────────────┬──────────────────┐
│     Tag      │    Set index    │   Byte Offset    │
└──────────────┴─────────────────┴──────────────────┘
```

**Key relationship**

```
No. of sets = No. of cache lines / k
```

Where k = associativity (ways per set). Each MM block maps to exactly one set (via set index), but can go in any of the k lines within that set.

**Formulas**

| Field          | Formula                                   |
| -------------- | ----------------------------------------- |
| Offset bits    | log₂(block size)                          |
| Set index bits | log₂(no. of sets) = log₂(cache lines / k) |
| Tag bits       | MM addr bits − set bits − offset bits     |

**How placement works**

1. Use set index bits → find the set.
2. Search all k lines in that set for a tag match.
3. If hit → return data. If miss → load block into one of the k lines (use replacement policy).

**Special cases — this is the one to memorize**

|k (ways)|No. of sets|Equivalent to|
|---|---|---|
|1|= no. of cache lines|Direct mapped|
|= no. of cache lines|1|Fully associative|
|2, 4, 8 …|cache lines / k|k-way set associative|

**Direct mapped is 1-way set associative. Fully associative is n-way set associative.** All three are the same structure — just different values of k.

**Key properties :**

- Reduces conflict misses vs direct mapped (k blocks can share a set without evicting each other).
- Cheaper hardware than fully associative (only k comparators per set, not n total).
- Replacement policy needed within each set.
- Most commonly used in practice — L1/L2/L3 caches are typically 4-way, 8-way, or 16-way.

---
## 3. Fully Associative Mapping

### Address Format

```
┌────────────────────────────────────┬──────────────────┐
│               Tag                  │   Byte Offset    │
└────────────────────────────────────┴──────────────────┘
```

No index/line field at all. The entire main memory block number becomes the tag.

**Formulas**

|Field|Formula|
|---|---|
|Offset bits|log₂(block size)|
|Tag bits|log₂(no. of MM blocks) = MM addr bits − offset bits|
|Index bits|0 — there is no index|

**Mental model**

```
No. of sets     = 1         (entire cache is one big set)
Ways per set    = no. of cache lines
Tag = entire MM block number
```

Any MM block can be placed in any cache line. On a lookup, all cache lines are searched in parallel using dedicated comparators — one per line.

**Key properties**

- **No conflict misses** — blocks never evict each other just because they share an index.
- **Most expensive hardware** — requires `n` comparators for `n` cache lines.
- **Replacement policy is critical** — since any line can hold any block, you need LRU/FIFO/Random to decide eviction.
- Tag size is the largest of the three types (holds full block number).

