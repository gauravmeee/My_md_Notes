---
description: From Gate Gate Smasher's Tutorial ▶️
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

# L-1: Introduction

## [L-1.1: Introduction to Operating System and its Functions with English Subtitles](https://www.youtube.com/watch?v=WJ-UaAaumNA\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=2\&pp=iAQB)

***

## [L-1.2: Batch Operating System | Types of Operating System](https://www.youtube.com/watch?v=povNcHSasgs\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=3\&pp=iAQB)

***

## [L-1.3: Multiprogramming and Multitasking Operating System in Hindi with real life examples](https://www.youtube.com/watch?v=3MqyDWDpZoI\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=4\&pp=iAQB)

***

## [L-1.4: Types of OS(Real Time OS, Distributed, Clustered & Embedded OS)](https://www.youtube.com/watch?v=YQZbIT9FcUk\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=5\&pp=iAQB)

***

## [L-1.5: Process States in Operating System| Schedulers(Long term, Short term, Medium term)](https://www.youtube.com/watch?v=2dJdHMpCLIg\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=6\&pp=iAQB)

***

## [L-1.6: Imp Linux Commands(Operating System) | Must Watch for College/University & Competitive exams](https://www.youtube.com/watch?v=-Mq8Mm_NGxI\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=7\&pp=iAQB0gcJCU0KAYcqIYzv)

***

## [L-1.7: System Calls in Operating system and its types in Hindi](https://www.youtube.com/watch?v=tWPa-rZiGM8\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=8\&pp=iAQB)

***

## [L-1.8: Fork System call with Example | Fork() system call questions](https://youtu.be/ixq5cpdEO2Q) ⭐⭐

**Fork()** - Create a Child Process that will be clone of the Parent Process

* It is required if parent process is busy somewhere

```
               /  0 (Child)
Fork() return  -  +1 (+ve) (Parent)
               \ -1 (-ve) (if Child process is not created)
```

```cpp
main(){
	fork();
	printf("hello");
}
```

```
parent process -> main()

	 P
	 |
   fork()
	/  \
  C1    P
   |    |
 hello  hello
```

```cpp
main(){
	fork();
	fork();
	printf("hi");
}
```

```
		 P
		 |
	   fork()   1
		/  \
	  C1    P
	   |    |
	fork() fork()   2
   /   \     /   \
  C2    C1  C3   P
  |      |   |   |
  hi     hi  hi  hi


c1 c2 c3 will run concurrent...
```

**Note:**

* If we don't want to use Fork() we could use Thread
* Thread -> If a parent is busy, we can make a thread, that create a third hand of the process.
* It is shared

***

## [L-1.9: Questions on Fork System Call With Explanation | Operating System](https://www.youtube.com/watch?v=uMMvYLB4cys\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=10\&pp=iAQB) ⭐

***

## [L-1.10: User mode and Kernel mode in operating system in hindi](https://www.youtube.com/watch?v=8duV1LLHHJU\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=11\&pp=iAQB) ⭐

***

## [L-1.11: Process Vs Threads in Operating System](https://www.youtube.com/watch?v=ITc09gOrqZk\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=12\&pp=iAQB) ⭐

***

## [L-1.12: User Level Vs Kernel Level Thread in Operating System | All Imp Points](https://www.youtube.com/watch?v=-NONm-Jq34Y\&list=PLxCzCOWd7aiGz9donHRrE9I3Mwn6XdP8p\&index=13\&pp=iAQB) ⭐

***
