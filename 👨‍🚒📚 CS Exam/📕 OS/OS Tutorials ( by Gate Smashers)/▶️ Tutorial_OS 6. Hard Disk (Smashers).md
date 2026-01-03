# L-6: Hard Disk
## [L-6.1: Hard Disk Architecture in Operating System in Hindi](https://youtu.be/sveZw_GG_cs)

**Hard Disk Architecture**
![](https://www.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/images/Chapter10/10_01_DiskMechanism.jpg)

- **Rotation** -> Uni direction -> Clockwise or Anticlockwise
- **Platter** -> Surface -> Track -> Sectors -> Data
- **Total Disk Size** = No. of Platters x No. of Surface in Each Platter x No. of Tracks in Each Surface x No. of Sector in Each Track x Data Per Sector


For Calculations Remember Powers of 2
```
2^1=2, 2^2=4, 2^3=8, 2^4=16, 2^5=32, 2^6=64, 2^7=128, 2^8=256, 2^9=512, 2^10=1024, 2^11=2048, 2^12=4096, 2^13=8192, 2^14=16384, 2^15=32768

1 K = 2^10 ~ 10^3
1 M = 2^20 ~ 10^6
1 G = 3^30 ~ 10^9
1 T = 2^40 ~ 10^12
```

**Ques:** Find No. of bits Required and Memory Size of the Disk With.  8 Platters, 256 Tracks on each surface, 512 Sector on Each Track and 512KB on each Sector

**Ans:** Memory Size = `P * 2 Surface By default * T * S * D`
= 8 x 2 x 256 x 512 x 512KB = 2^3 x 2^1 x 2^8 x 2^9 + 2^9(2^10) = 2^40 = 1 TB

No. of Bits = log(2^40) = 40

---
## [L-6.2: Disk Access Time with Example | Seek Time, Rotational Time and Transfer Time](https://youtu.be/udZi6uiR8bM)

**Disk Access Time**
- **Seek Time ->** Time taken by Read/write head to reach desired track.
- **Rotation time** -> Time taken for one full Rotation (360.)
- **Rotational Latency** -> Time taken to reach desired sector. (Half of Rotation Time) ~ Average of All rotations
- **Transfer Time** -> Data to be Transfer / Transfer Rate
- **Transfer Rate (Data Rate)** -> No. of Heads(or Surface) x Capacity of one Track x No. of Rotations per second

---
## [L-6.3: Disk Scheduling Algorithm | Operating System](https://youtu.be/9uoa_p8q47Y)

Goal -> To minimize the seek time (no. of tracks Movement)
- The whole track is read in one go, so the scheduling depends on the seek time (time to reach a track).
- It is done by **Actuator Arm** back(outside) and Forth (inside) movement.

**Disk Scheduling Algorithms**: 
- FCFS (First come first Serve)
- SSTF (Shortest Seek time first) -> Nearest Cylinder Next
- SCAN -> Elevator Algorithm
- LOOK
- CSCAN (Circular Scan)
- CLOOK (Circular Look)


### Common Ques for All Algorithms

**Ques** A disk Contains 200 tracks. Request queue contains track no. (82, 170, 43, 140, 24, 16, 190) respectively. Current Position of R/W head = 50
-> Calculate total no. of tracks movement by head using All Algorithms
-> If R/W head takes 1ns to move from one track to another then total time taken ___ ?

---
## [L-6.4: FCFS in Disk scheduling with Example | Operating System](https://youtu.be/yP89YlEGCqA)

**FCFS**
Advantage -> No Starvation
Disadvantage -> Performance (No optimisation)


**Ans:** Seek Time = abs(82-50) + abs(170-82) + abs(43-170) + abs(140-43) + abs(24-140) +  abs(16-24) + (190-16) = 642
=> (82-50) + (170-82) + (170-43) + (140-43) + (140-24) +  (24-16) + (190-16) = 642

```
		     50->82
		        └82-------->170┐
		  ┌ 43<-------------170┘
		  └ 43---------->140┐
		 24<-------------140┘
	┌16<-24┘	 
    └16------------------>190

Back-n-Forth
170-50 + 170-43 + 140-43 + 140-16 + 190-16 = 642
Total Time taken = 642ns
```

---
## [L-6.5: SSTF in Disk scheduling with Example | Operating System](https://youtu.be/P_dA8VGJjA8)

**SSTF**
- Advantage -> Least Seek time (Average cases), Less Response time
- Disadvantage -> Starvation, More Overhead to find nearest

```
		     43<-50
		 24<-43
	 16<-24
	 16--------------->82
	                   82--->140
	                         140-->170
	                               170->190
	                
(50-16)+(190-16) = 208
Total Time Taken = 208 ns
```

## [L-6.6: SCAN Algorithm in Disk scheduling with Example | Operating System](https://youtu.be/xouo556RGiE)

**SCAN:**
- Advantage -> It work as an 'Elevator' Algorithm it means, in Initial Direction Track Move Upto the Last Track (0 or n-1) to full fill the need of some new request at runtime

- Disadvantage -> If Dynamically a New Request come after, Direction change from edge toward different edge, than it need to wait for long time to come back

```
Direction Given: Starting Direction toward larger value

		         50--->82
		               82--->140
		                     140-->170
		                           170->190
		                                190->199
	         43<-----------------------------199
		 24<-43
	 16<-24	                

(199-50)+(199-16) = 332
Total time taken = 332ns
```

---
## [L-6.7: LOOK Algorithm in Disk scheduling with Example | Operating System](https://youtu.be/9QpCJnHhXRc)

**LOOK**
Same as SCAN with Track not goes upto the edge tracks without need.

```
Direction Given: Starting Direction toward larger value

		         50--->82
		               82--->140
		                     140-->170
		                           170->190
	         43<------------------------190
		 24<-43
	 16<-24	                

(190-50)+(190-16) = 314
Total time taken = 314 ns
```

---
## [L-6.8: C-SCAN Algorithm in Disk scheduling with Example | Operating System](https://youtu.be/vLqZ6ZMBkX8)

C-SCAN -> Circular Scan

50->82->140->170->190->(199) Rightmost ->Left Most (0) -> 16 -> 24 -> 43

(199-50) + (199-0) + (43-0) = 391

---
## [L-6.9: C-LOOK Algorithm in Disk scheduling with Example | Operating System](https://youtu.be/gwCgG5ORXW8)

50->82->140->170->190-> Left ->16 -> 24 -> 43

(199-50) + (190-16) + (43-16) = 341


---

## [L-6.10: Important Questions on Operating System | Must Watch | NTA NET June 2021](https://www.youtube.com/watch?v=AF3FoARvtcc&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p&index=81&pp=iAQB)