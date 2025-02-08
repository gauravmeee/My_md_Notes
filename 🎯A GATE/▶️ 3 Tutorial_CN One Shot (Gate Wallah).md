
# [Computer Networks One Shot | CS & IT Engineering Maha Revision | Target GATE 2025](https://youtu.be/hlHXNmbozd8)


Layer 2 and Layer 1 Device Never be a Node.  Only Layer 3 Device can be node
Cannot be a Node - Hub, Switch, Bridge
Can be a Node - Router


Transport Layer doen't have any device - because not required

Gateway - Layer 7 Device
Router - Layer 3 Device

Difference between Gateway and Router
- Heterogeneous Network - Gateway (Powerful Routing) used for protocol converter
- Homogeneous Network (Both Network with same protocols) - Routing


Client Server Model  - 24x7 Model, Client can communicate and server will fulfill its request



Application - Transport
Port(DNA) - Socket(TCP/UDP)

TCP - Connection oriented and Reliable protocol
UDP - Connection less and unreliable protocol (But UDP is fast)

DHCB -> Broad Cast Mode -> cannot stablish connection -> Cannot Use TCP
RIP - Used in Routing -> If we use connection for each, it will be complex -> so use UDP

For Connections, The Node should no each others IP address 


Stateless - No state is maintined/Accounted how much data send or received

Statefullness in Transport Layer and Application Layers are not dependent

FTP - 2 TCP Connection (Control (maintain state/log) + Data)


TcP - Logical Connection (log maintain which socket is connected to which)
Circuit Switching - Phyiscal Connection

DNS Resolver = Host Name + Query =  Host Id + Port no.


3 Tier `www.pw.live` Hierarchy have only one TLD
4 tier `www.dtu.ac.in` 2 TLD
`dtu` -> Authoritative Name server
`ac` -> 2nd TLD
`in` -> Root Name Server
TLD - Top Level domain `.com`, `.edu` `.org`, `.in`


Http 1.0 -> one time use tcp connection -> 1 object (html, image or video ) -> autoclose connection
Syn - connection request
Syn + Ack - Connection Ack
HTTP Request - GET


HTTP 1.1 -> Back to Back object transfer (in pipeline fashion)

Modern Browser operate in - Pipeline Mode
Connection Established
Connection Established ? -> Request Base html file
Which Objects are Required? (written in Base html) -> Back to Back send object


Mail Transmit -> SMTP protocol
Mail Download -> Imap protocol 

IMAP -> modern protocol
POP -> old protocol -> doesnot support parrallel login, doesnot support labelling, heirarchy folder , different inboxes etc.


SMTP - 1 Tcp connection for both (command+mail)
FTP Server - Server of Files
FTP - 2 TCP connection - control + data


TCP is intelligent protocol , and so it doen't lead fragmentation of IP address


#### Transport Layer

Transmitted byte = LastByteSent - LastByteAcked

CWND - Congestion Window 
RWND - Flow

Congestion Control Important ⭐


### Network


IP address network classifications are divided into **five classes (A, B, C, D, and E)** based on their **first few bits** and **value range**.

IP Address `11111111`.`11111111`.`11111111`.`11111111` (32 bits)

11111111 => 255
```
Each Classess Network Range  in Binary:
A -> 0(0000000).0.0.0 - 0(1111111).255.255.255
B -> 10(000000.0).0.0 - 10(111111.255).255.255
C -> 110(00000.0.0).0 - 110(11111.255.255).255
D -> 1110(0000.0.0.0) - 1110(1111.255.255)
E -> 1111(0000.0.0.0) - 1111(1111.255.255)


No. of Networks  eachy type:
Network Bits = A=8, B=16, C=24, D=NA, E=NA
A : 2^(8-1) = 2^7 = 128 network
B : 2^(16-2) = 2^14 = 16384 Networks
C : 2^(24-3) = 2^21 = 2097152 Networks
D : 2^(32-4) = 2^28 = 26843546 Networks
E : 2^(32-4) = 2^28 = 26843546 Networks

2^8 = 128 
0 - (2^7-1 = 128-1) = 127
128 - (128+2^6-1 = 128+64-1 = 191)
192 - (192+2^5-1 = 192+32-1 = 223)
224 - (224+2^4-1 = 224+16-1 = 240)
240 - (240+2^4-1 = 240+16-1 = 255)

Network Range in Binary to  Decimal
A -> 0(0000000) - 0(11111111) <=> 0 - 127
B -> 10(000000) - 10(111111) <=> 128 - 191
C -> 110(00000) - 110(11111) <=> 192 - 223
D -> 1110(0000) - 1110(1111) <=> 224 - 239
E -> 1111(0000) - 1111(1111) <=> 240 - 255

Network Range Decimal
A -> 0.0.0.0 - 127.255.255.255 
B -> 128.0.0.0 - 191.255.255.255 
C -> 192.0.0.0 - 223.255.255.255
D -> 224.0.0.0 - 239.255.255.255
E -> 240.0.0.0 - 255.255.255.255
```


| Class | First Bits | Starting IP Range | Ending IP Range     | Default Subnet Mask | No. of Hosts |
| ----- | ---------- | ----------------- | ------------------- | ------------------- | ------------ |
| **A** | 0xxxxxxx   | **1.0.0.0**       | **126.255.255.255** | 255.0.0.0           | 16,777,214   |
| **B** | 10xxxxxx   | **128.0.0.0**     | **191.255.255.255** | 255.255.0.0         | 65,534       |
| **C** | 110xxxxx   | **192.0.0.0**     | **223.255.255.255** | 255.255.255.0       | 254          |
| **D** | 1110xxxx   | **224.0.0.0**     | **239.255.255.255** | N/A (Multicast)     | N/A          |
| **E** | 1111xxxx   | **240.0.0.0**     | **255.255.255.255** | N/A (Reserved)      | N/A          |

### Key Points:

- **Class A**: Used for **large networks** (Governments, Large Orgs)
- **Class B**: Used for **medium-sized networks**
- **Class C**: Used for **small networks** (Most common for businesses)
- **Class D**: Used for **Multicasting** (No subnetting)
- **Class E**: Reserved for **Experimental** purposes



Net ID + Subnet ID + Host ID = IP Address (32-BIT)

In Modern Time Subnet ID Can be all zero to all 1, to prevent waste of Cluster of IP id
No. of subnet reduce by 2 i.e `2^(subnet bits)-2` and no. of wasted host id `(2^(SUBNET BITS)-2)* SUBNET SIZE`

- Subnet Address : Host ID = 0.......0 -> Special IP Address -> not assigned to any host
- Subnet Broadcast Address (32-bit) : Host ID = 1.....1

No. of subnets `2^(subnet bits)`
Sub-net size = `2^(host bits) - 2`


Network mask -> genrate network address from given ip address

Subnet Mask ->  generate subnet address from given ip address
- net id = all one bits
- subnet id = all one bits
- host id = all zero bits

subnet address = Ip adress x subnet mask

VLSM variable length subnet  mask

Variable length network prefixes, Allow variable size sub-neworks (subnet)

![[Pasted image 20250130151521.png]]


Router Forwarding Table

```
Nework address     Mask   Interface ID Next hop
    .....          ...     ......       ....
    .....          ...     ......       ....
    .....          ...     ......       .... 
```

Router use Longest Prefix match to find whom to send the packet -> router chooses more specifix (more one 1...) option over generic one (Les one 0....)

IPd - Destination IP address 
NA - Network address

IPd  && Mask 1 == NA1?? transfer to Router 1
IPd  && Mask 2 == NA2?? Transfer to router 2
IPd  && Mask 3 == NA3?? Transfer to Router 3


Classless Inter -Domain Routing (CIDR) - with this you can find where the ip adreess is (country, state, city, service provider etc) using IP address prefix only
-> IP address allocation method for better routing
-> Based on VLSM
-> Allows flexibility in creating 'supernets'


##### ARP
**DDL**
Address Resolution Protocol (ARP)  -> find MAC address of device from IP address
- MAP logical to physical address
- DDL Protocol

ARP Packet
 ARP Query - Broad Cast, FF:FF:FF:FF:FF:FF (48 bits)
ARP Reply - Unicast


##### NAT

NAT - Network Address Translation

IPv4 address assigned by ISP
total no. of networks worldwide = 2^32

Outgoing datagram - Source IP convert private to public
Incoming datagram - Destination IP convert public to private


-----
----
Example - If a TCP segment with sequence 200, and have 100 byte
so its mean its bytes sequence no's are

In DDL Sequence no. are assigned to Frames
In Transport Layer , seq no. are assigned to bytes not segments
```
byte 1,   2   3  .............. 98 99 100
seq no. 200 201 202 ...............297 298 299

So next segment Sequence no. will start from `300`
```


Culmulative Acknowledgement - Acknowledgement for 1 + upto which data is received (Main/Base header)
Selective Acknowledgment -  (Optional Header) If Receiver already get higher seq no. segment before required one, it will stored it in the buffer, and it will acknowledge the sender that these selected future bytes are received already, and lower bytes are missing


⭐ Important 3 question in GATE - Maximum segment Lifetime

Socket is a Data structure, that created corresponding to every Network processes
Whenever a Process become Network process than socket no. need to be created, and port no. is assigned
- Socket data structure have to two buffer - sending and Receiver

ISN - Initial sequence no. (need not be zero) - Random no.

ISN - Created randomly and consumed for Connection establishing bytes
ISN + 1 - First Message byte


MSL is equal to Wrap-around time

TCP connection - i.e Logical connection between two sockets


Roorke fav topic - connection termination, CRC


Connection Can be terminated by any one Client or Server i.e  TCP A or Tcp B


TCP sockets

TCP socket() will created first
process will system call and Request OS to create a Socket

listen() can be get out of only two - client or if process close abruptly