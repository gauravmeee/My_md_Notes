
**Ranking DES, AES, LEA, and LED Based on Key Factors for IoT & General Use**
1.  **Security, General-Purpose Use** : AES > LEA > LED > DES
2.  **Performance (Speed on CPUs & Software), Efficiency (Balance of Speed & Security)** : LEA > AES > LED > DES
3.  **Lightweight (Low Power & Minimal Resources), Suitability for IoT** : LED > LEA > AES > DES

---
### Why AES is considered more secure than LEA

##### Advanced Encryption Standard (AES)
AES uses a substitution-permutation network structure and operates on 128-bit blocks with key sizes of 128, 192, or 256 bits[1](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/)[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/). Its encryption process involves:
1. **Key Expansion**: The original key is used to derive a series of unique round keys[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/).
2. **Initial Round Key Addition**: The first round key is XORed with the plaintext block.
3. **Main Rounds**: Each round (10, 12, or 14 depending on key size) consists of four operations:
    - **SubBytes**: Each byte is replaced using a predefined substitution table (S-box)[1](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/).
    - **ShiftRows**: Bytes in each row are cyclically shifted[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/).
    - **MixColumns**: A specific mathematical operation mixes data within each column[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/).
    - **AddRoundKey**: The round key is XORed with the current state[1](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/).
4. **Final Round**: Similar to main rounds but without MixColumns.
    

##### Lightweight Encryption Algorithm (LEA)
LEA is a 128-bit block cipher with key sizes of 128, 192, or 256 bits[3](https://en.wikipedia.org/wiki/LEA_\(cipher\)). It uses ARX (Addition, Rotation, XOR) operations for 32-bit words. The encryption process involves:
1. **Key Schedule**: Generates round keys using modular addition and bitwise operations.
2. **Encryption Rounds**: 24, 28, or 32 rounds (depending on key size) of:
    - Modular addition of round keys and data words.
    - Bitwise rotations of data words.
    - Bitwise XOR operations.
        
##### Summary
1. **Proven Security**: AES has undergone extensive cryptanalysis and has no known practical attacks[1](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/). LEA, being newer, has had less time for thorough analysis.
2. **Complex S-box**: AES uses a highly non-linear substitution box, providing strong confusion[1](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/). LEA relies on simpler ARX operations, which may be more vulnerable to certain attacks.
3. **Diffusion Properties**: AES's MixColumns operation provides excellent diffusion, spreading changes across the entire state[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/). LEA's simpler structure may not achieve the same level of diffusion.
4. **Flexibility**: AES's larger block size (128 bits vs LEA's 64 bits for some versions) and variable rounds provide better security margins[3](https://en.wikipedia.org/wiki/LEA_\(cipher\)).
5. **Wide Adoption**: AES's widespread use has led to optimized, secure implementations across various platforms[2](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/).
While LEA offers good performance, especially in lightweight environments, AES's more complex structure, extensive analysis, and proven security make it the preferred choice for general-purpose, high-security applications.

---

### Why LEA Speeds and Pefromance is Better than LED even LED is More Lightweight
##### LED: More Lightweight
LED is more lightweight than LEA for several reasons:
1. **Smaller block size**: ==LED uses a 64-bit block size==, while LEA uses a 128-bit block size[1](https://eprint.iacr.org/2012/600.pdf)[2](https://www.informatica.si/index.php/informatica/article/view/4596). This smaller block size requires less memory and processing power.
2. **Simpler structure**: ==LED employs AES-like operations but with a simpler structure==, making it more suitable for resource-constrained devices[8](https://eprint.iacr.org/2019/1218.pdf).
3. **No key schedule**: LED doesn't use a key schedule, which reduces computational overhead and memory requirements[8](https://eprint.iacr.org/2019/1218.pdf).
4. **Lower resource usage**: LED requires fewer resources in terms of ROM/RAM compared to many other lightweight algorithms, including LEA[9](https://cit.iict.bas.bg/CIT-2024/v-24-1/10341-Volume24_Issue_1-02_paper.pdf).
##### LEA: Better Performance and Speed
Despite LED being more lightweight, LEA offers better performance and speed:
1. **Optimized for software**: LEA was designed specifically for efficient software implementation on common processors, particularly 32-bit systems[3](https://en.wikipedia.org/wiki/LEA_\(cipher\))[7](https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/).
2. **Simple operations**: LEA uses only Addition, Rotation, and XOR (ARX) operations, which are fast and efficient on most processors[3](https://en.wikipedia.org/wiki/LEA_\(cipher\))[7](https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/).
3. **32-bit word size**: LEA's 32-bit operations align well with modern processor architectures, leading to faster execution[3](https://en.wikipedia.org/wiki/LEA_\(cipher\)).
4. **Parallelization**: LEA's structure allows for efficient parallelization, further improving performance on multi-core processors[4](https://www.mdpi.com/1424-8220/14/1/975).
5. **Faster encryption**: LEA encrypts data about 1.5 to 2 times faster than AES in various software environments[3](https://en.wikipedia.org/wiki/LEA_\(cipher\)).

##### Balance of Lightweight and Performance
While LED is more lightweight, LEA strikes a better balance between lightweight design and performance:
1. **Efficient resource use**: LEA achieves high performance while still maintaining relatively low resource requirements, making it suitable for a wider range of devices[6](https://research.utwente.nl/files/328040877/Analysis_of_Lightweight_Cryptographic_Algorithms_on_IoT_Hardware_Platforms.pdf).
2. **Scalability**: LEA supports multiple key sizes (128, 192, and 256 bits) with corresponding round numbers, allowing for flexibility in security levels[9](https://cit.iict.bas.bg/CIT-2024/v-24-1/10341-Volume24_Issue_1-02_paper.pdf).
3. **Software-oriented design**: LEA's focus on software efficiency results in better performance on common processors, which are increasingly used in IoT and embedded systems[7](https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/).
In summary, LED is more lightweight and suitable for extremely resource-constrained devices, while LEA offers better performance and efficiency across a broader range of applications, particularly in software implementations on common processors.

---

## Citations

**Citations: Why LEA Speeds and Pefromance is Better than LED even LED is More Lightweight**
1. [https://eprint.iacr.org/2012/600.pdf](https://eprint.iacr.org/2012/600.pdf)
2. [https://www.informatica.si/index.php/informatica/article/view/4596](https://www.informatica.si/index.php/informatica/article/view/4596)
3. [https://en.wikipedia.org/wiki/LEA_(cipher)](https://en.wikipedia.org/wiki/LEA_\(cipher\))
4. [https://www.mdpi.com/1424-8220/14/1/975](https://www.mdpi.com/1424-8220/14/1/975)
5. [https://eprint.iacr.org/2015/732.pdf](https://eprint.iacr.org/2015/732.pdf)
6. [https://research.utwente.nl/files/328040877/Analysis_of_Lightweight_Cryptographic_Algorithms_on_IoT_Hardware_Platforms.pdf](https://research.utwente.nl/files/328040877/Analysis_of_Lightweight_Cryptographic_Algorithms_on_IoT_Hardware_Platforms.pdf)
7. [https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/](https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/)
8. [https://eprint.iacr.org/2019/1218.pdf](https://eprint.iacr.org/2019/1218.pdf)
9. [https://cit.iict.bas.bg/CIT-2024/v-24-1/10341-Volume24_Issue_1-02_paper.pdf](https://cit.iict.bas.bg/CIT-2024/v-24-1/10341-Volume24_Issue_1-02_paper.pdf)
10. [https://www.semanticscholar.org/paper/LEA:-A-128-Bit-Block-Cipher-for-Fast-Encryption-on-Hong-Lee/ee7f68347773a0100b1e7fc6a6a878d78b294184](https://www.semanticscholar.org/paper/LEA:-A-128-Bit-Block-Cipher-for-Fast-Encryption-on-Hong-Lee/ee7f68347773a0100b1e7fc6a6a878d78b294184)
11. [https://ieeexplore.ieee.org/document/8785584/](https://ieeexplore.ieee.org/document/8785584/)
12. [https://www.nec.com/en/global/techrep/journal/g17/n01/170114.html](https://www.nec.com/en/global/techrep/journal/g17/n01/170114.html)
13. [https://ieeexplore.ieee.org/document/10638985/](https://ieeexplore.ieee.org/document/10638985/)
14. [https://www.researchgate.net/publication/379349394_Lightweight_Cryptography_for_Internet_of_Things_A_Review](https://www.researchgate.net/publication/379349394_Lightweight_Cryptography_for_Internet_of_Things_A_Review)
15. [https://www.tandfonline.com/doi/full/10.1080/23742917.2017.1384917](https://www.tandfonline.com/doi/full/10.1080/23742917.2017.1384917)
16. [https://www.researchgate.net/publication/384392124_An_Efficient_Low-Latency_and_High_Throughput_LED_Cipher_Architecture_for_IoT_Security_on_a_Hardware_Platform](https://www.researchgate.net/publication/384392124_An_Efficient_Low-Latency_and_High_Throughput_LED_Cipher_Architecture_for_IoT_Security_on_a_Hardware_Platform)
17. [https://www.mdpi.com/2076-3417/13/18/10345](https://www.mdpi.com/2076-3417/13/18/10345)
18. [https://dl.acm.org/doi/10.1007/s42979-024-03275-5](https://dl.acm.org/doi/10.1007/s42979-024-03275-5)
19. [https://www.researchgate.net/publication/309774662_Lightweight_security_algorithm_for_low_power_IoT_devices](https://www.researchgate.net/publication/309774662_Lightweight_security_algorithm_for_low_power_IoT_devices)
20. [https://www.mdpi.com/1424-8220/24/12/4008](https://www.mdpi.com/1424-8220/24/12/4008)
21. [https://dl.acm.org/doi/10.1007/978-3-319-05149-9_1](https://dl.acm.org/doi/10.1007/978-3-319-05149-9_1)
22. [https://www.researchgate.net/figure/Comparison-to-other-encryption-algorithms_tbl1_259651631](https://www.researchgate.net/figure/Comparison-to-other-encryption-algorithms_tbl1_259651631)
23. [https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU](https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU)
24. [https://ieeexplore.ieee.org/document/10176846/](https://ieeexplore.ieee.org/document/10176846/)
25. [https://iieta.org/journals/ijsse/paper/10.18280/ijsse.140511](https://iieta.org/journals/ijsse/paper/10.18280/ijsse.140511)
26. [https://ieeexplore.ieee.org/document/10458747/](https://ieeexplore.ieee.org/document/10458747/)
27. [https://www.mdpi.com/2227-7080/13/1/3](https://www.mdpi.com/2227-7080/13/1/3)
28. [https://www.researchgate.net/publication/260791776_LEA_A_128-Bit_Block_Cipher_for_Fast_Encryption_on_Common_Processors](https://www.researchgate.net/publication/260791776_LEA_A_128-Bit_Block_Cipher_for_Fast_Encryption_on_Common_Processors)
29. [https://www.semanticscholar.org/paper/Efficient-Hardware-Implementation-of-the-Block-LEA-Lee-Kim/4e991161d369b68f39b0c3cc859abd7532f38f54](https://www.semanticscholar.org/paper/Efficient-Hardware-Implementation-of-the-Block-LEA-Lee-Kim/4e991161d369b68f39b0c3cc859abd7532f38f54)
30. [https://www.researchgate.net/publication/349097545_Performance_Evaluation_of_Lightweight_Encryption_Algorithms_for_IoT-Based_Applications](https://www.researchgate.net/publication/349097545_Performance_Evaluation_of_Lightweight_Encryption_Algorithms_for_IoT-Based_Applications)
31. [https://www.springerprofessional.de/en/hight-speed-low-area-vlsi-architecture-for-lea-encryption-algori/16893948](https://www.springerprofessional.de/en/hight-speed-low-area-vlsi-architecture-for-lea-encryption-algori/16893948)
32. [https://electricajournal.org/en/lwe-an-energy-efficient-lightweight-encryption-algorithm-for-medical-sensors-and-iot-devices-13991](https://electricajournal.org/en/lwe-an-energy-efficient-lightweight-encryption-algorithm-for-medical-sensors-and-iot-devices-13991)
33. [https://onomondo.com/blog/iot-security-issues-and-solutions-low-power-devices/](https://onomondo.com/blog/iot-security-issues-and-solutions-low-power-devices/)
34. [https://www.tutorialspoint.com/how-is-lightweight-cryptography-applicable-to-various-iot-devices](https://www.tutorialspoint.com/how-is-lightweight-cryptography-applicable-to-various-iot-devices)
35. [https://research.tees.ac.uk/ws/portalfiles/portal/49903399/Lightweight_Cryptography_for_Resource.pdf](https://research.tees.ac.uk/ws/portalfiles/portal/49903399/Lightweight_Cryptography_for_Resource.pdf)
36. [https://eprint.iacr.org/2023/821.pdf](https://eprint.iacr.org/2023/821.pdf)
37. [https://www.dline.info/dspai/fulltext/v1n2/v1n2_4.pdf](https://www.dline.info/dspai/fulltext/v1n2/v1n2_4.pdf)


**Citations: Why AES is considered more secure than LEA**
1. [https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/](https://www.kiteworks.com/risk-compliance-glossary/aes-256-encryption/)
2. [https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/](https://www.pandasecurity.com/en/mediacenter/what-is-aes-encryption/)
3. [https://en.wikipedia.org/wiki/LEA_(cipher)](https://en.wikipedia.org/wiki/LEA_\(cipher\))
4. [https://pubs.aip.org/aip/acp/article/3015/1/020002/2931576/An-enhanced-LED-cipher-algorithm-performance-for](https://pubs.aip.org/aip/acp/article/3015/1/020002/2931576/An-enhanced-LED-cipher-algorithm-performance-for)
5. [https://www.tutorialspoint.com/cryptography/data_encryption_standard.htm](https://www.tutorialspoint.com/cryptography/data_encryption_standard.htm)
6. [https://www.shiksha.com/online-courses/articles/difference-between-aes-and-des-ciphers-blogId-158769](https://www.shiksha.com/online-courses/articles/difference-between-aes-and-des-ciphers-blogId-158769)
7. [https://eprint.iacr.org/2012/600.pdf](https://eprint.iacr.org/2012/600.pdf)
8. [https://www.techtarget.com/searchsecurity/answer/The-difference-between-AES-encryption-and-DES-encryption](https://www.techtarget.com/searchsecurity/answer/The-difference-between-AES-encryption-and-DES-encryption)
9. [https://byjus.com/gate/difference-between-aes-and-des-ciphers/](https://byjus.com/gate/difference-between-aes-and-des-ciphers/)
10. [https://nordlayer.com/blog/aes-encryption/](https://nordlayer.com/blog/aes-encryption/)
11. [https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197-upd1.pdf](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.197-upd1.pdf)
12. [https://www.techtarget.com/searchsecurity/definition/Advanced-Encryption-Standard](https://www.techtarget.com/searchsecurity/definition/Advanced-Encryption-Standard)
13. [https://www.veritas.com/information-center/aes-encryption](https://www.veritas.com/information-center/aes-encryption)
14. [https://www.zenarmor.com/docs/network-security-tutorials/what-is-advanced-encryption-standard-aes](https://www.zenarmor.com/docs/network-security-tutorials/what-is-advanced-encryption-standard-aes)
15. [https://www.1kosmos.com/authentication/aes-encryption/](https://www.1kosmos.com/authentication/aes-encryption/)
16. [https://ieeexplore.ieee.org/document/7820845/](https://ieeexplore.ieee.org/document/7820845/)
17. [https://www.researchgate.net/figure/Encryption-and-Description-Process-of-LEA_fig1_285813354](https://www.researchgate.net/figure/Encryption-and-Description-Process-of-LEA_fig1_285813354)
18. [https://ieeexplore.ieee.org/document/8649937/](https://ieeexplore.ieee.org/document/8649937/)
19. [https://ieeexplore.ieee.org/document/6835064/](https://ieeexplore.ieee.org/document/6835064/)
20. [https://www.researchgate.net/figure/Encryption-operation-of-LED-block-cipher_fig1_336254454](https://www.researchgate.net/figure/Encryption-operation-of-LED-block-cipher_fig1_336254454)
21. [https://www.researchgate.net/figure/Encryption-process-of-the-LED-algorithm_fig3_351707097](https://www.researchgate.net/figure/Encryption-process-of-the-LED-algorithm_fig3_351707097)
22. [https://ieeexplore.ieee.org/document/10638985/](https://ieeexplore.ieee.org/document/10638985/)
23. [https://arxiv.org/abs/2108.12079](https://arxiv.org/abs/2108.12079)
24. [https://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm](https://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm)
25. [https://www.youtube.com/watch?v=j53iXhTSi_s](https://www.youtube.com/watch?v=j53iXhTSi_s)
26. [https://www.simplilearn.com/what-is-des-article](https://www.simplilearn.com/what-is-des-article)
27. [https://herovired.com/learning-hub/blogs/des-algorithm-in-cryptography/](https://herovired.com/learning-hub/blogs/des-algorithm-in-cryptography/)
28. [https://www.jetir.org/papers/JETIR2301029.pdf](https://www.jetir.org/papers/JETIR2301029.pdf)
29. [https://www.appsealing.com/aes-encryption/](https://www.appsealing.com/aes-encryption/)
30. [https://www.precisely.com/blog/data-security/aes-vs-des-encryption-standard-3des-tdea](https://www.precisely.com/blog/data-security/aes-vs-des-encryption-standard-3des-tdea)
31. [https://www.researchgate.net/publication/376841166_Neural_Network_Based_Data_Encryption_A_Comparison_Study_among_DES_AES_and_HE_Techniques](https://www.researchgate.net/publication/376841166_Neural_Network_Based_Data_Encryption_A_Comparison_Study_among_DES_AES_and_HE_Techniques)
32. [https://www.researchgate.net/publication/331988729_Comparison_of_AES_and_PRESENT_Block_Cipher_for_6LoWPAN_Based_Internet-of-Things](https://www.researchgate.net/publication/331988729_Comparison_of_AES_and_PRESENT_Block_Cipher_for_6LoWPAN_Based_Internet-of-Things)
33. [https://testbook.com/key-differences/difference-between-aes-and-des-ciphers](https://testbook.com/key-differences/difference-between-aes-and-des-ciphers)
34. [https://info.townsendsecurity.com/bid/72450/what-are-the-differences-between-des-and-aes-encryption](https://info.townsendsecurity.com/bid/72450/what-are-the-differences-between-des-and-aes-encryption)
35. [https://www.tutorialspoint.com/cryptography/advanced_encryption_standard.htm](https://www.tutorialspoint.com/cryptography/advanced_encryption_standard.htm)
36. [https://cybertalents.com/blog/advanced-encryption-standard-aes](https://cybertalents.com/blog/advanced-encryption-standard-aes)
37. [https://www.simplilearn.com/tutorials/cryptography-tutorial/aes-encryption](https://www.simplilearn.com/tutorials/cryptography-tutorial/aes-encryption)
38. [https://en.wikipedia.org/wiki/Advanced_Encryption_Standard](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard)
39. [https://www.cdvi.co.uk/learn-about-access-control/what-is-access-control/what-is-aes-encryption-and-how-does-it-work/](https://www.cdvi.co.uk/learn-about-access-control/what-is-access-control/what-is-aes-encryption-and-how-does-it-work/)
40. [https://eprint.iacr.org/2015/732.pdf](https://eprint.iacr.org/2015/732.pdf)
41. [http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf](http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf)
42. [https://github.com/pedroalbanese/leacrypt](https://github.com/pedroalbanese/leacrypt)
43. [https://www.informatica.si/index.php/informatica/article/view/4596](https://www.informatica.si/index.php/informatica/article/view/4596)
44. [https://eprint.iacr.org/2012/544.pdf](https://eprint.iacr.org/2012/544.pdf)
45. [https://www.kaspersky.com/blog/led-data-exfiltration/48523/](https://www.kaspersky.com/blog/led-data-exfiltration/48523/)
46. [https://www.ituonline.com/tech-definitions/what-is-data-encryption-standard-des/](https://www.ituonline.com/tech-definitions/what-is-data-encryption-standard-des/)
47. [https://sectigostore.com/blog/how-does-des-encryption-work-in-cryptography/](https://sectigostore.com/blog/how-does-des-encryption-work-in-cryptography/)
48. [https://en.wikipedia.org/wiki/Data_Encryption_Standard](https://en.wikipedia.org/wiki/Data_Encryption_Standard)
49. [https://www.zenarmor.com/docs/network-security-tutorials/what-is-data-encryption-standard-des](https://www.zenarmor.com/docs/network-security-tutorials/what-is-data-encryption-standard-des)
50. [https://nvlpubs.nist.gov/nistpubs/sp958-lide/250-253.pdf](https://nvlpubs.nist.gov/nistpubs/sp958-lide/250-253.pdf)
51. [https://www.techtarget.com/searchsecurity/definition/Data-Encryption-Standard](https://www.techtarget.com/searchsecurity/definition/Data-Encryption-Standard)
52. [https://www.lri.fr/~fmartignon/documenti/systemesecurite/4-DES.pdf](https://www.lri.fr/~fmartignon/documenti/systemesecurite/4-DES.pdf)

