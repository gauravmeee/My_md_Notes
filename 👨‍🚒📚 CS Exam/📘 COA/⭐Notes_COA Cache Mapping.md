> Created at CRL

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

### Direct Mapping


**Formulas :**
- **Offset Bits :** Represent **block size (words/bytes inside a block)**
	- Offset Bits = `log₂(Block Size)`

- **Tag Bits :** Represents **number of main memory blocks** competing for one cache line
	- Tag Bits = `log₂(Memory Size / Cache Size)` or `log₂(No. of Main Memory Blocks / No. of Cache Blocks)`

- **Block No. / Line** : Represent No. of Blocks
	- Main Memory Block Bits = `log₂(No. of Main Memory Blocks)`
	- Cache Line Bits = `log₂(Number of Cache Blocks)`

- **Address Bits :** Represent **addressable memory size**
	- Main Memory Address Bits = `log₂(Main Memory Size)`
	- Cache Memory Address Bits = `log₂(Cache Size)`

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
##### **Main Memory Address**
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


##### **Cache Memory Address**
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