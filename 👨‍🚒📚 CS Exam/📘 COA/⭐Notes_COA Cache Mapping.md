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
- Offset Bits = `log₂(Block Size)`
- Tag Bits = `log₂(Memory Size / Cache Size)` or `log₂(No. of Main Memory Blocks / No. of Cache Blocks)`
- Main Memory Block Bits = `log₂(No. of Main Memory Blocks)`
- Cache Line Bits = `log₂(Number of Cache Blocks)`
- Main Memory Address Bits = `log₂(Main Memory Size)`
- Cache Memory Address Bits = `log₂(Cache Size)`
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

-