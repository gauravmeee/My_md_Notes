
### 0. `OriginalLEA` vs `SboxLEA` vs `OptimisedSboxLEA` vs `DynamicSboxLEA`:

Here's an ordered breakdown of algorithm performance across 15 NIST STS tests, with the best performer highlighted in **bold** for each category:

**1. Approximate Entropy** 
- DynamicSboxLEA (0.975069) > OptimisedSboxLEA (0.638485) > OriginalLEA (0.450521) > SboxLEA (0.287752)
- **Best: DynamicSboxLEA** ✅

**2. Block Frequency**
- DynamicSboxLEA (0.900511) > SboxLEA (0.45667) > OptimisedSboxLEA (0.429627) > OriginalLEA (0.368814)
- **Best: DynamicSboxLEA** ✅

**3. Cumulative Sums (Two Subtests)**
- Subtest 1: OptimisedSboxLEA (0.750259) > DynamicSboxLEA (0.586534) > SboxLEA (0.581218) > OriginalLEA (0.315001)   
- Subtest 2: >OptimisedSboxLEA (0.547261) > DynamicSboxLEA (0.450176) > OriginalLEA (0.332992) > SboxLEA (0.145443)
- **Best: OptimisedSboxLEA ** ✅
        
**4. FFT**
- OptimisedSboxLEA (0.363468) > SboxLEA (0.356244) > DynamicSboxLEA (0.314819) > OriginalLEA (0.230943)
- **Best: OptimisedSboxLEA** ✅

**5. Frequency**
- OriginalLEA (0.976059) > OptimisedSboxLEA (0.819589) > SboxLEA (0.45855) > DynamicSboxLEA (0.417791)
- **Best: OriginalLEA** ✅

**6. Linear Complexity**
- OriginalLEA (0.765439) > OptimisedSboxLEA (0.659666) > SboxLEA (0.630303) > DynamicSboxLEA (0.334688)
- **Best: OriginalLEA** ✅

**7. Longest Run**
- SboxLEA (0.926421) > OriginalLEA (0.636065) > DynamicSboxLEA (0.364984) > OptimisedSboxLEA (0.302375)
- **Best: SboxLEA** ✅
    
**8. Non Overlapping Template (148 Subtests)**
- No clear overall winner due to highly variable subtests
- DynamicSboxLEA and OptimisedSboxLEA won ~60% of subtests
- OriginalLEA performed weakest
- **Mixed Results**
    
**9. Overlapping Template**
- **Best: DynamicSboxLEA** ✅
##### 10. Random Excursions
- OptimisedSboxLEA (0.4607–0.937085) > DynamicSboxLEA (All 0.0) > OriginalLEA/SboxLEA (All 0.0)
- **Best: OptimisedSboxLEA** ✅
##### 11. Random Excursions Variant
- OptimisedSboxLEA (0.0988–0.937085) > DynamicSboxLEA (All 0.0) > OriginalLEA/SboxLEA (All 0.0)
- **Best: OptimisedSboxLEA** ✅
##### 12. Rank
- OptimisedSboxLEA (0.624076) > DynamicSboxLEA (0.395189) > SboxLEA (0.742489) > OriginalLEA (0.050477)
- **Best: OptimisedSboxLEA** ✅
##### 13. Runs
- OriginalLEA (0.890207) > DynamicSboxLEA (0.448296) > OptimisedSboxLEA (0.206472) > SboxLEA (0.35024)
- **Best: OriginalLEA** ✅
##### 14. Serial (Two Subtests)
- Subtest 1: DynamicSboxLEA (0.958261) > OptimisedSboxLEA (0.47415) > SboxLEA (0.492753) > OriginalLEA (0.208604)
- Subtest 2: > DynamicSboxLEA (0.947861) > OptimisedSboxLEA (0.886333) > OriginalLEA (0.501945) > SboxLEA (0.477897)
- **Best: DynamicSboxLEA**  ✅
##### 15. Universal
- OptimisedSboxLEA (0.799552) > OriginalLEA (0.783455) > DynamicSboxLEA (0.224883) > SboxLEA (0.225704)
- **Best: OptimisedSboxLEA** ✅
##### Key Takeaways
- **DynamicSboxLEA** dominated in 7/15 tests  ✅
	- (ApproximateEntropy, BlockFrequency, OverlappingTemplate, Serial, and both RandomExcursions tests)
- **OptimisedSboxLEA** excelled in 5/15 tests  ✅
	- (CumulativeSums, FFT, Rank, Universal, and RandomExcursionsVariant)
- **OriginalLEA** remained strong in foundational tests 
	- (Frequency, LinearComplexity, Runs)
- **SboxLEA** only led in Longest Run test
    
For cryptographic applications requiring broad statistical robustness, **DynamicSboxLEA** is recommended, while **OriginalLEA** remains viable for specific use cases prioritizing frequency/runs analysis.


---

###  1. `OriginalLEA` vs `SboxLEA`:

## Comparison of Algorithm Performance Across 14 NIST STS Tests

The results compare two algorithms—OriginalLEA and SboxLEA—across 14 NIST Statistical Test Suite (STS) tests, each producing p-values that indicate the randomness quality of their outputs. In these tests, higher p-values (closer to 1, but not too close to 0 or 1) generally suggest better statistical randomness, while very low p-values may indicate non-randomness or failure of the test.

Below is a summary table showing which algorithm performed better in each test:

| Test Name               | OriginalLEA p-value(s) | SboxLEA p-value(s) | Better Algorithm  |
| ----------------------- | ---------------------- | ------------------ | ----------------- |
| ApproximateEntropy      | 0.450521               | 0.287752           | OriginalLEA ❌     |
| BlockFrequency          | 0.368814               | 0.45667            | SboxLEA ✅         |
| CumulativeSums          | 0.315001, 0.332992     | 0.581218, 0.145443 | Split (1 each)    |
| FFT                     | 0.230943               | 0.356244           | SboxLEA ✅         |
| Frequency               | 0.976059               | 0.45855            | OriginalLEA ❌     |
| LinearComplexity        | 0.765439               | 0.630303           | OriginalLEA ❌     |
| LongestRun              | 0.636065               | 0.926421           | SboxLEA ✅         |
| NonOverlappingTemplate  | Many (see file)        | Many (see file)    | Mixed (see below) |
| OverlappingTemplate     | 0.425838               | 0.846736           | SboxLEA ✅         |
| RandomExcursions        | All 0.0                | All 0.0            | Equal             |
| RandomExcursionsVariant | All 0.0                | All 0.0            | Equal             |
| Rank                    | 0.050477               | 0.742489           | SboxLEA ✅         |
| Runs                    | 0.890207               | 0.35024            | OriginalLEA ❌     |
| Serial                  | 0.208604, 0.501945     | 0.492753, 0.477897 | Split (1 each)    |
| Universal               | 0.783455               | 0.225704           | OriginalLEA ❌     |

**Original LEA** -> 5/15 ✅
**Modified Sbox LEA** -> 5/15 ✅
**Draw** -> 5/15 ✅
##### Notes on NonOverlappingTemplate Test
- This test produces a large number of p-values for different templates. The comparison is mixed, with each algorithm outperforming the other on different templates. No clear overall winner can be declared without further statistical aggregation.

##### Summary of Results
- **OriginalLEA outperforms SboxLEA** in: ApproximateEntropy, Frequency, LinearComplexity, Runs, Universal.
- **SboxLEA outperforms OriginalLEA** in: BlockFrequency, FFT, LongestRun, OverlappingTemplate, Rank.
- **Split or Mixed Results**: CumulativeSums and Serial tests have mixed outcomes (each algorithm wins one subtest).
- **Equal Results**: RandomExcursions and RandomExcursionsVariant tests are equal (all p-values are 0.0 for both).
- **NonOverlappingTemplate**: Results are mixed and distributed; neither algorithm is a clear winner.

##### Conclusion
Neither algorithm is a clear overall winner across all 14 tests. Each algorithm demonstrates strengths in different statistical areas:
- **OriginalLEA** is stronger in tests like Frequency, Runs, and Universal, which are foundational randomness checks.
- **SboxLEA** excels in tests like BlockFrequency, LongestRun, OverlappingTemplate, and Rank, which probe different statistical properties.

For a final decision, consider which statistical properties are most critical for your application. If you need strong performance in basic randomness (Frequency, Runs), OriginalLEA is preferable. If you prioritize performance in block-based or rank-related randomness, SboxLEA has an edge. For a comprehensive cryptographic application, further aggregation or domain-specific weighting of these results may be necessary1.

---

###  2. `OriginalLEA` vs `OptimisedSboxLEA`:

| Test Name               | OriginalLEA vs SboxLEA                   | Better Algorithm (OriginalLEA vs SboxLEA) | OriginalLEA vs OptimisedSboxLEA          | Better Algorithm (OriginalLEA vs OptimisedSboxLEA) |
| ----------------------- | ---------------------------------------- | ----------------------------------------- | ---------------------------------------- | -------------------------------------------------- |
| ApproximateEntropy      | 0.450521 vs 0.287752                     | OriginalLEA                               | 0.450521 vs 0.638485                     | OptimisedSboxLEA ✅                                 |
| BlockFrequency          | 0.368814 vs 0.45667                      | SboxLEA                                   | 0.368814 vs 0.429627                     | OptimisedSboxLEA ✅                                 |
| CumulativeSums          | 0.315001, 0.332992 vs 0.581218, 0.145443 | Mixed (1 each)                            | 0.315001, 0.332992 vs 0.750259, 0.547261 | OptimisedSboxLEA ✅                                 |
| FFT                     | 0.230943 vs 0.356244                     | SboxLEA                                   | 0.230943 vs 0.363468                     | OptimisedSboxLEA ✅                                 |
| Frequency               | 0.976059 vs 0.45855                      | OriginalLEA                               | 0.976059 vs 0.819589                     | OriginalLEA ❌                                      |
| LinearComplexity        | 0.765439 vs 0.630303                     | OriginalLEA                               | 0.765439 vs 0.659666                     | OriginalLEA ❌                                      |
| LongestRun              | 0.636065 vs 0.926421                     | SboxLEA                                   | 0.636065 vs 0.302375                     | OriginalLEA ❌                                      |
| NonOverlappingTemplate  | Mixed (many values)                      | Mixed                                     | Mixed (many values)                      | Mixed                                              |
| OverlappingTemplate     | 0.425838 vs 0.846736                     | SboxLEA                                   | 0.425838 vs 0.55747                      | OptimisedSboxLEA ✅                                 |
| RandomExcursions        | all 0.0 vs all 0.0                       | Equal                                     | all 0.0 vs nonzero (0.749, etc.)         | OptimisedSboxLEA ✅                                 |
| RandomExcursionsVariant | all 0.0 vs all 0.0                       | Equal                                     | all 0.0 vs nonzero (0.778, etc.)         | OptimisedSboxLEA ✅                                 |
| Rank                    | 0.050477 vs 0.742489                     | SboxLEA                                   | 0.050477 vs 0.624076                     | OptimisedSboxLEA ✅                                 |
| Runs                    | 0.890207 vs 0.35024                      | OriginalLEA                               | 0.890207 vs 0.206472                     | OriginalLEA ❌                                      |
| Serial                  | 0.208604, 0.501945 vs 0.492753, 0.477897 | Mixed (1 each)                            | 0.208604, 0.501945 vs 0.47415, 0.886333  | OptimisedSboxLEA ✅                                 |
| Universal               | 0.783455 vs 0.225704                     | OriginalLEA                               | 0.783455 vs 0.799552                     | OptimisedSboxLEA ✅                                 |

**Original LEA** -> 4/15 ✅
**Optimised Sbox LEA** -> 10/15 ✅
**Draw** -> 1/15 ✅

- "Mixed" means the test has multiple subvalues and no clear overall winner.
- "Equal" means both algorithms performed identically.
##### Summary:
- **Against SboxLEA**, OriginalLEA is better in 5 tests, SboxLEA in 5, and 2 are mixed/equal.
- **Against OptimisedSboxLEA**, OptimisedSboxLEA is better in 9 tests, OriginalLEA in 4, and 1 is mixed.

OptimisedSboxLEA shows the best overall performance across the majority of NIST STS tests, especially in tests where OriginalLEA and SboxLEA either tie or split results12.

---

### 3.   `OriginalLEA` vs `DynamicSboxLEA`:

| Test Name                   | OriginalLEA p-value(s) | DynamicSboxLEA p-value(s) | Better Algorithm        |
| --------------------------- | ---------------------- | ------------------------- | ----------------------- |
| **ApproximateEntropy**      | 0.450521               | 0.975069                  | DynamicSboxLEA ✅        |
| **BlockFrequency**          | 0.368814               | 0.900511                  | DynamicSboxLEA ✅        |
| **CumulativeSums**          | 0.315001, 0.332992     | 0.586534, 0.450176        | DynamicSboxLEA (both) ✅ |
| **FFT**                     | 0.230943               | 0.314819                  | DynamicSboxLEA ✅        |
| **Frequency**               | 0.976059               | 0.417791                  | OriginalLEA ❌           |
| **LinearComplexity**        | 0.765439               | 0.334688                  | OriginalLEA ❌           |
| **LongestRun**              | 0.636065               | 0.364984                  | OriginalLEA ❌           |
| **NonOverlappingTemplate**  | Mixed (148 subtests)   | Mixed (148 subtests)      | Mixed*                  |
| **OverlappingTemplate**     | 0.425838               | 0.892707                  | DynamicSboxLEA ✅        |
| **RandomExcursions**        | All 0.0                | All 0.0                   | Equal                   |
| **RandomExcursionsVariant** | All 0.0                | All 0.0                   | Equal                   |
| **Rank**                    | 0.050477               | 0.395189                  | DynamicSboxLEA ✅        |
| **Runs**                    | 0.890207               | 0.448296                  | OriginalLEA ❌           |
| **Serial**                  | 0.208604, 0.501945     | 0.958261, 0.947861        | DynamicSboxLEA ✅ (both) |
| **Universal**               | 0.783455               | 0.224883                  | OriginalLEA ❌           |

**Original LEA** -> 5/15 ✅
**Optimised Sbox LEA** -> 7/15 ✅
**Draw** -> 3/15 ✅
##### Key Notes:
- **NonOverlappingTemplate**: Results are mixed across 148 subtests, with no clear overall winner.
- **RandomExcursions**/**Variant**: Both algorithms scored 0.0 (indicating potential non-randomness in these specific tests).
- **DynamicSboxLEA** won **8/14 tests** outright, including critical tests like ApproximateEntropy, BlockFrequency, and Serial.
- **OriginalLEA** performed better in **5/14 tests**, particularly Frequency, LinearComplexity, and Universal.
    
#### Recommendation:
- DynamicSboxLEA demonstrates stronger overall statistical randomness in most tests, making it preferable for applications requiring robust cryptographic properties. However, OriginalLEA remains competitive in foundational tests like Frequency and Universal. For non-overlapping template scenarios, further analysis is required due to mixed results.


---