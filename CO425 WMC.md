

#  [L30: Wireless Local Area Network(WLAN) Architecture, Components, Application | Mobile Computing](https://youtu.be/RBc7MyE9RTQ)


# IEEE 802.11 wireless standards

Wireless standards are set of services and protocols that determine how a wi-fi  network operates

Wifi(wireless Fidelity) : wireless technology standard for wireless internet access 


> 1997
### IEEE 802.11

Speed - 2Mbps
Frequency - 2.4 GHz
Modulation Method - FHSS, DSSS

*Note:* Spread Spectrum Techniques:


> 1999
### IEEE 802.11b ( Wifi 1)

Speed - 11 Mbps
Frequency - 2.4 GHz
Modulation Method - DSSS, CCK

*Note:* 802.11b kickstarts wifies popularity

### IEEE 802.11a ( Wifi 2)
It is a Extension of Wifi 1

Speed - 54 Mbps
Frequency - 5 GHz
Modulation Method - OFDM

*Note:* 
5 GHz has more difficulties with objects that were in the signal path, So the range was poor.
11a comes after 11b because of OFDM Technology


> 2003
### IEEE 802.11g ( Wifi 3)

Speed - 54 Mbps
Frequency - 2.4 GHz
Modulation Method - OFDM

*Note:* 
upgrade the speed up to 54 Mbps while retaining the usage of reliable 2.4GHz
this result in the widespread adoption of the standards


> 2009
### IEEE 802.11n ( Wifi 4)

Speed - 600 Mbps
Frequency - 2.4/5 GHz
Modulation Method - MIMO, OFDM

*Note:* 
This version had slow initial adoption.
it supported multi channel usage, each channel support max data rate up to 600 Mbps



Modulation Schemes Summary:

- **FHSS - Frequency Hopping Spread Spectrum**: A technique where the signal rapidly switches frequencies to minimize interference and improve security.

- **DSSS - Direct Sequence Spread Spectrum**: A method that spreads the signal over a wide frequency band to reduce interference and increase security.

- **OFDM - Orthogonal Frequency Division Multiplexing**: A multiplexing technique that divides a communication channel into multiple orthogonal sub-channels to enhance data transmission efficiency.

- **CCK - Complementary Code Keying**: A modulation scheme used in wireless networks for improved data transmission efficiency.

- **MIMO - Multiple Input and Multiple Output**: A technology that uses multiple antennas at both the transmitter and receiver to improve communication performance.


# [Hidden Station Problem And Exposed Station Problem in Computer Networks Explained in Hindi](https://youtu.be/Xr_S4kr4fR8)

### Hidden Station Problem

**Definition**: The hidden station problem occurs in wireless networks when two devices, which cannot hear each other, try to communicate with a third device. This can cause interference and data collisions at the third device because the two hidden stations do not know of each other's transmissions.

**Diagram**:

```
   .        . 
      .  .
       .
 A --> B <--C
       .
      . .
   .       .
```

- **A** and **C** are hidden from each other but both can communicate with **B**.
- If **A** and **C** transmit simultaneously, **B** may experience interference or collision because it cannot detect both transmissions.

### Exposed Station Problem

**Definition**: The exposed station problem occurs when a device is prevented from transmitting even though its transmission would not cause interference to ongoing transmissions from other devices.

**Diagram**:

```
   .        .   .
      .  .          .
       .              .
 A --> B        C----> D
       .              .
      . .           .
   .        .   . 
```

- **A** is trying to communicate with **B**, while **C** is trying to communicate with **D*.
- **C** might avoid transmitting because it detects **A**'s ongoing transmission to **B**, even though **C**'s transmission would not interfere with **A**'s communication with **B**.
