---
description: Made By Me 💚
icon: dot
layout:
  width: wide
  title:
    visible: true
  description:
    visible: true
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: false
  metadata:
    visible: false
  tags:
    visible: true
---

# IP Addresses

IP address network classifications are divided into **five classes (A, B, C, D, and E)** based on their **first few bits** and **value range**.

IP Address `xxxxxxxx`.`xxxxxxxx`.`xxxxxxxx`.`xxxxxxxx` (32 bits)

00000000 = 0 and 11111111 = 255

```
[ Network id | Host id ]
Below we enclose network bit's inside '()' like (xxxxx)

Each Classess Network Range  in Binary:
A -> 0(0000000).0.0.0 - 0(1111111).255.255.255
B -> 10(000000.0).0.0 - 10(111111.255).255.255
C -> 110(00000.0.0).0 - 110(11111.255.255).255
D -> 1110(0000.0.0.0) - 1110(1111.255.255.255)
E -> 1111(0000.0.0.0) - 1111(1111.255.255.255)


No. of Networks  eachy type:
Network Bits = A=8, B=16, C=24, D=NA, E=NA
A : 2^(8-1) = 2^7 = 128 network
B : 2^(16-2) = 2^14 = 16384 Networks
C : 2^(24-3) = 2^21 = 2097152 Networks
D : 2^(32-4) = 2^28 = 26843546 Networks
E : 2^(32-4) = 2^28 = 26843546 Networks

Total 2^8 = 128  values are possible i.e.  0 to 127 

Network Range in Binary to  Decimal
A : 0(0000000) - 0(11111111) <=> 0 - 127 (0+2^7-1 = 0+128-1)
B : 10(000000) - 10(111111) <=> 128 - 191 (128+2^6-1 = 128+64-1)
C : 110(00000) - 110(11111) <=> 192 - 223 (192+2^5-1 = 192+32-1)
D : 1110(0000) - 1110(1111) <=> 224 - 239 (224+2^4-1 = 224+16-1)
E : 1111(0000) - 1111(1111) <=> 240 - 255 (240+2^4-1 = 240+16-1)

Network Range Decimal
A : 0.0.0.0 - 127.255.255.255 
B : 128.0.0.0 - 191.255.255.255 
C : 192.0.0.0 - 223.255.255.255
D : 224.0.0.0 - 239.255.255.255
E : 240.0.0.0 - 255.255.255.255
```

| Class | First Bits | Starting IP Range | Ending IP Range     | Default Subnet Mask | No. of Hosts |
| ----- | ---------- | ----------------- | ------------------- | ------------------- | ------------ |
| **A** | 0xxxxxxx   | **1.0.0.0**       | **127.255.255.255** | 255.0.0.0           | 16,777,214   |
| **B** | 10xxxxxx   | **128.0.0.0**     | **191.255.255.255** | 255.255.0.0         | 65,534       |
| **C** | 110xxxxx   | **192.0.0.0**     | **223.255.255.255** | 255.255.255.0       | 254          |
| **D** | 1110xxxx   | **224.0.0.0**     | **239.255.255.255** | N/A (Multicast)     | N/A          |
| **E** | 1111xxxx   | **240.0.0.0**     | **255.255.255.255** | N/A (Reserved)      | N/A          |

#### Key Points:

* **Class A**: Used for **large networks** (Governments, Large Orgs)
* **Class B**: Used for **medium-sized networks**
* **Class C**: Used for **small networks** (Most common for businesses)
* **Class D**: Used for **Multicasting** (No subnetting)
* **Class E**: Reserved for **Experimental** purposes
