
### Goal : Make LEA Flexible (To fluctuate Between LED for low power and LEA for better security)


1. LEA key sizes of 128, 192, or 256 bits,  
	- If (Ultra low powered IOT) -> Change it to 64 bits key size
	- & Implement scalable encryption and decryption operations to adapt to different key sizes while maintaining a simple architecture[1](https://eprint.iacr.org/2015/732.pdf).

2. LEA use Simple modular arithmetic operations (ARX)
	- If (Sufficiend Powered device, but need Critical infor) -> Integrate S-box

3. LEA use Key Scheduling
	- If (Ultra low powered device) -> Eliminate or Reduce Key Scheduling
	- If (Sufficient power) -> Enhance Key Scheduling

4. LEA Use  these no. of rounds ____
	- If(Low powered IOT) -> Reduce no. of Rounds
	- If(High powered IOT) -> Increase no. of Rounds



---

> Refined by Ai
#### FLEA: Flexible Lightweight Encryption Algorithm

**1. Adaptive Key and Block Sizes**
- **Default**: 128-bit block size with 128, 192, or 256-bit key sizes
- **Ultra-low power mode**: 64-bit block size with 64 or 128-bit key sizes
- Implement a scalable structure that can efficiently handle different block and key sizes

**2. Configurable Operations**
- **Default**: ARX (Addition, Rotation, XOR) operations
- **Enhanced security mode**: Integrate lightweight S-boxes (e.g., 4x4 or 8x8) that can be optionally activated
- Implement a hybrid approach where S-boxes can be selectively used in critical rounds

**3. Flexible Key Scheduling**
- **Ultra-low power mode**: Minimal or no key scheduling (similar to LED)
- **Default mode**: Standard LEA key scheduling
- **Enhanced security mode**: More complex key scheduling with increased diffusion

**4. Adaptive Round Structure**
- Base number of rounds: 24 for 128-bit key, 28 for 192-bit key, 32 for 256-bit key
- **Low-power mode**: Reduce rounds by 25% (e.g., 18, 21, 24 rounds)
- **High-security mode**: Increase rounds by 25% (e.g., 30, 35, 40 rounds)

**5. Power-Aware Optimization**
- Implement a power monitoring system that can dynamically adjust the algorithm's parameters based on available resources
- Allow for runtime switching between modes based on power availability and security requirements
    
**6. Modular Design**
- Design the algorithm with modular components that can be easily enabled or disabled
- Implement a configuration interface that allows easy switching between modes

**7. Selective Feature Activation**
- Allow for selective activation of security features (e.g., S-boxes, additional rounds) for specific data blocks or based on data sensitivity
    
 **8. Efficient Implementation**
- Optimize the code for both 8-bit and 32-bit architectures to ensure efficiency across a wide range of devices
- Use efficient register scheduling and minimize inner loops for better performance on resource-constrained devices
    
**9. Security Analysis**
- Conduct thorough security analysis for each mode to ensure that even in low-power configurations, the algorithm maintains an acceptable level of security
- Implement safeguards to prevent unintended weakening of the algorithm when switching modes
    
**10. Standardization and Certification**
- Develop clear guidelines for implementing and using FLEA in different scenarios
- Seek certification and standardization to ensure widespread adoption and trust in the algorithm
    
This approach creates a highly flexible encryption algorithm that can adapt to various power and security requirements while maintaining the core strengths of both LED and LEA. The modular design allows for easy customization and optimization for specific use cases, making FLEA suitable for a wide range of IoT devices and applications.

---

### 5 changes to LEA to Make Balanced between Security and Performance (Without making Flexible)

To optimize LEA without making it flexible, we can focus on enhancing its performance, security, and efficiency. Here are five key changes to make LEA better balanced and optimized:

##### 1. Implement Efficient Register Scheduling
Optimize register usage for both 8-bit and 32-bit architectures to improve performance on resource-constrained devices:
- Minimize inner loops and optimize them at the instruction set level
- Construct the algorithm in a partly unrolled fashion for reasonable speed
- Efficiently schedule registers, considering the limited number of general-purpose registers in low-end processors[1](https://eprint.iacr.org/2015/732.pdf)
    
##### 2. Enhance Key Scheduling
Improve the key scheduling algorithm to increase resistance against related-key attacks while maintaining efficiency:
- Implement a more complex key derivation process
- Increase the diffusion of key material throughout the rounds
- Balance security improvements with computational efficiency[2](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645)
##### 3. Integrate Lightweight S-boxes
Add lightweight S-boxes to improve non-linearity and resistance to linear and differential cryptanalysis:
- Implement 4x4 or 8x8 S-boxes for enhanced security
- Carefully design S-boxes to minimize performance impact
- Integrate S-boxes in critical parts of the algorithm to maximize security gains[2](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645)[3](https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1)

##### 4. Optimize for Hardware Implementation
Improve LEA's performance in hardware environments:
- Implement parallelization techniques for speed-optimized versions
- Design resource-shared structures for area-optimized versions
- Utilize on-the-fly key scheduling or schedule two keys simultaneously to reduce clock cycles[4](https://www.mdpi.com/1424-8220/14/1/975)

#### 5. Implement Side-Channel Attack Countermeasures
Enhance LEA's resistance to side-channel attacks without significantly impacting performance:
- Apply a lightweight masking technique to prevent differential power analysis
- Implement the masking process efficiently to minimize performance overhead
- Ensure that intermediate values differ from those expected by potential attackers[6](http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf)
    
These optimizations aim to create a more balanced version of LEA that improves security and performance while maintaining its lightweight nature, making it suitable for a wide range of IoT devices and applications.

---
## How we Make LEA , more simple structure so more lightweight, and increase security


To make LEA (Lightweight Encryption Algorithm) simpler, more lightweight, and increase its security, several modifications can be considered:

#### Simplify Structure
1. **Reduce block size**: Decrease the ==128-bit block size to 64 bits==, which would require less memory and processing power[1](https://eprint.iacr.org/2015/732.pdf). ✅
2. **Eliminate key schedule**: ==Remove the key schedule==, as LED (Light Encryption Device) does, to reduce computational overhead and memory requirements[1](https://eprint.iacr.org/2015/732.pdf). ✅
3. **Optimize for byte-wise operations**: Split 32-bit word operations into four byte-wise operations to take advantage of efficient byte-wise rotations[1](https://eprint.iacr.org/2015/732.pdf).


> Note: Key Schedule A key schedule is an algorithm used in cryptography to generate a series of subkeys from a single master key[1](https://www.vpnunlimited.com/help/cybersecurity/key-schedule)[2](https://nordvpn.com/cybersecurity/glossary/key-schedule/). It is a crucial component of symmetric encryption algorithms, such as the Advanced Encryption Standard (AES)[3](https://en.wikipedia.org/wiki/AES_key_schedule). The purpose of a key schedule is to:
4. Expand the original key into multiple round keys
5. Enhance the security of the encryption process
6. Increase the complexity of the algorithm
    
#### Increase Lightweight Properties
1. **Minimize inner loops**: Find the minimum inner loops and optimize them at the instruction set level to reduce code size[1](https://eprint.iacr.org/2015/732.pdf).
2. **Efficient register scheduling**: Implement efficient register scheduling due to the limited number of general-purpose registers in resource-constrained devices[1](https://eprint.iacr.org/2015/732.pdf).
3. **Scalable encryption/decryption**: Implement scalable encryption and decryption operations to adapt to different key sizes while maintaining a simple architecture[1](https://eprint.iacr.org/2015/732.pdf). ✅

#### Enhance Security
1. **Introduce S-boxes**: Integrate S-boxes for improved non-linearity, enhancing resistance to linear and differential cryptanalysis[8](https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1). ✅
2. **Enhanced key scheduling**: Implement a more complex key scheduling algorithm to increase resistance against related-key attacks[8](https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1). ✅
3. **Implement masking techniques**: Apply masking processes to prevent differential side-channel attacks, although this may impact performance[2](http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf).
4. **Increase number of rounds**: Consider increasing the number of rounds for each key size to improve security, balancing this with performance requirements[5](https://www.ijitee.org/wp-content/uploads/papers/v9i2S/B10261292S19.pdf).
5. **Use arbitrary constants**: Incorporate arbitrary constants in the algorithm to provide better confusion and diffusion in encryption[5](https://www.ijitee.org/wp-content/uploads/papers/v9i2S/B10261292S19.pdf).
    
By implementing these modifications, LEA can become more lightweight and secure. However, it's crucial to carefully balance simplicity, performance, and security to ensure the algorithm remains suitable for resource-constrained IoT devices while providing adequate protection against various attacks.

---
---


# Citations:


**Citations: 5 changes to LEA to Make Balanced between Security and Performance (Without making Flexible)**
1. [https://eprint.iacr.org/2015/732.pdf](https://eprint.iacr.org/2015/732.pdf)
2. [https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645)
3. [https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1](https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1)
4. [https://www.mdpi.com/1424-8220/14/1/975](https://www.mdpi.com/1424-8220/14/1/975)
5. [https://ijeer.forexjournal.co.in/archive/volume-10/ijeer-100232.html](https://ijeer.forexjournal.co.in/archive/volume-10/ijeer-100232.html)
6. [http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf](http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf)
7. [http://www.eecs.northwestern.edu/~memik/courses/452/presentations/sec_2.pdf](http://www.eecs.northwestern.edu/~memik/courses/452/presentations/sec_2.pdf)
8. [https://thesai.org/Downloads/Volume11No1/Paper_89-LEA_SIoT_Hardware_Architecture_of_Lightweight_Encryption.pdf](https://thesai.org/Downloads/Volume11No1/Paper_89-LEA_SIoT_Hardware_Architecture_of_Lightweight_Encryption.pdf)
9. [https://www.researchgate.net/publication/3044898_Improving_Memory_Encryption_Performance_in_Secure_Processors](https://www.researchgate.net/publication/3044898_Improving_Memory_Encryption_Performance_in_Secure_Processors)
10. [https://www.researchgate.net/publication/343412555_High_throughput_unified_architecture_of_LEA_algorithm_for_image_encryption](https://www.researchgate.net/publication/343412555_High_throughput_unified_architecture_of_LEA_algorithm_for_image_encryption)
11. [https://ieeexplore.ieee.org/document/6643114/](https://ieeexplore.ieee.org/document/6643114/)
12. [https://dl.acm.org/doi/10.1145/1150019.1136502](https://dl.acm.org/doi/10.1145/1150019.1136502)
13. [https://www.researchgate.net/publication/259651631_Efficient_Hardware_Implementation_of_the_Lightweight_Block_Encryption_Algorithm_LEA](https://www.researchgate.net/publication/259651631_Efficient_Hardware_Implementation_of_the_Lightweight_Block_Encryption_Algorithm_LEA)
14. [https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU](https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU)
15. [https://www.mdpi.com/1424-8220/22/21/8527](https://www.mdpi.com/1424-8220/22/21/8527)
16. [https://ieeexplore.ieee.org/document/10550599/](https://ieeexplore.ieee.org/document/10550599/)
17. [https://assets-eu.researchsquare.com/files/rs-2033728/v1_covered.pdf?c=1663873069](https://assets-eu.researchsquare.com/files/rs-2033728/v1_covered.pdf?c=1663873069)
18. [https://en.wikipedia.org/wiki/LEA_(cipher)](https://en.wikipedia.org/wiki/LEA_\(cipher\))
19. [https://arxiv.org/abs/2309.10722](https://arxiv.org/abs/2309.10722)
20. [https://www.academia.edu/82491219/128_Bit_LEA_Block_Encryption_Architecture_to_Improve_the_Security_of_IoT_Systems_with_Limited_Resources_and_Area](https://www.academia.edu/82491219/128_Bit_LEA_Block_Encryption_Architecture_to_Improve_the_Security_of_IoT_Systems_with_Limited_Resources_and_Area)



**Citations : How we Make LEA , more simple structure so more lightweight, and increase security**
1. [https://eprint.iacr.org/2015/732.pdf](https://eprint.iacr.org/2015/732.pdf)
2. [http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf](http://www.apsipa.org/proceedings_2016/HTML/paper2016/294.pdf)
3. [https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=5097645)
4. [https://ijeer.forexjournal.co.in/archive/volume-10/ijeer-100232.html](https://ijeer.forexjournal.co.in/archive/volume-10/ijeer-100232.html)
5. [https://www.ijitee.org/wp-content/uploads/papers/v9i2S/B10261292S19.pdf](https://www.ijitee.org/wp-content/uploads/papers/v9i2S/B10261292S19.pdf)
6. [https://www.mdpi.com/1424-8220/14/1/975](https://www.mdpi.com/1424-8220/14/1/975)
7. [https://en.wikipedia.org/wiki/LEA_(cipher)](https://en.wikipedia.org/wiki/LEA_\(cipher\))
8. [https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1](https://papers.ssrn.com/sol3/Delivery.cfm/24a2b4c2-a725-4b44-a3b3-f3cc6dee0be8-MECA.pdf?abstractid=5097645&mirid=1)
9. [https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU](https://www.researchgate.net/publication/282839971_Optimization_of_Lightweight_Encryption_Algorithm_LEA_using_Threads_and_Shared_Memory_of_GPU)
10. [https://ieeexplore.ieee.org/document/10550599/](https://ieeexplore.ieee.org/document/10550599/)
11. [https://ieeexplore.ieee.org/document/8649937/](https://ieeexplore.ieee.org/document/8649937/)
12. [https://www.tandfonline.com/doi/full/10.1080/23742917.2017.1384917](https://www.tandfonline.com/doi/full/10.1080/23742917.2017.1384917)
13. [https://www.researchgate.net/publication/259651631_Efficient_Hardware_Implementation_of_the_Lightweight_Block_Encryption_Algorithm_LEA](https://www.researchgate.net/publication/259651631_Efficient_Hardware_Implementation_of_the_Lightweight_Block_Encryption_Algorithm_LEA)
14. [https://www.researchgate.net/figure/Encryption-and-Description-Process-of-LEA_fig1_285813354](https://www.researchgate.net/figure/Encryption-and-Description-Process-of-LEA_fig1_285813354)
15. [https://www.researchgate.net/publication/376576431_Lightweight_Cryptography_Concepts_and_Algorithms_A_Survey](https://www.researchgate.net/publication/376576431_Lightweight_Cryptography_Concepts_and_Algorithms_A_Survey)
16. [https://ieeexplore.ieee.org/document/7899139/](https://ieeexplore.ieee.org/document/7899139/)
17. [https://www.mdpi.com/2076-3417/13/7/4398](https://www.mdpi.com/2076-3417/13/7/4398)
18. [https://github.com/pedroalbanese/leacrypt](https://github.com/pedroalbanese/leacrypt)
19. [https://www.scitepress.org/Papers/2024/127929/127929.pdf](https://www.scitepress.org/Papers/2024/127929/127929.pdf)
20. [https://research.tees.ac.uk/ws/portalfiles/portal/49903399/Lightweight_Cryptography_for_Resource.pdf](https://research.tees.ac.uk/ws/portalfiles/portal/49903399/Lightweight_Cryptography_for_Resource.pdf)
21. [https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/](https://pmc.ncbi.nlm.nih.gov/articles/PMC3926597/)
22. [https://ieeexplore.ieee.org/document/5529851/](https://ieeexplore.ieee.org/document/5529851/)
23. [https://ieeexplore.ieee.org/document/10176846/](https://ieeexplore.ieee.org/document/10176846/)
24. [https://www.researchgate.net/publication/312571915_An_improved_LEA_block_encryption_algorithm_to_prevent_side-channel_attack_in_the_IoT_system](https://www.researchgate.net/publication/312571915_An_improved_LEA_block_encryption_algorithm_to_prevent_side-channel_attack_in_the_IoT_system)
25. [https://www.researchgate.net/publication/360344064_Optimization_of_AES-128_Encryption_Algorithm_for_Security_Layer_in_ZigBee_Networking_of_Internet_of_Things](https://www.researchgate.net/publication/360344064_Optimization_of_AES-128_Encryption_Algorithm_for_Security_Layer_in_ZigBee_Networking_of_Internet_of_Things)
26. [https://ieeexplore.ieee.org/document/6643114/](https://ieeexplore.ieee.org/document/6643114/)
27. [https://thesai.org/Downloads/Volume11No1/Paper_89-LEA_SIoT_Hardware_Architecture_of_Lightweight_Encryption.pdf](https://thesai.org/Downloads/Volume11No1/Paper_89-LEA_SIoT_Hardware_Architecture_of_Lightweight_Encryption.pdf)
28. [https://thesai.org/Publications/ViewPaper?Volume=9&Issue=11&Code=IJACSA&SerialNo=37](https://thesai.org/Publications/ViewPaper?Volume=9&Issue=11&Code=IJACSA&SerialNo=37)
29. [https://eprint.iacr.org/2020/1534](https://eprint.iacr.org/2020/1534)