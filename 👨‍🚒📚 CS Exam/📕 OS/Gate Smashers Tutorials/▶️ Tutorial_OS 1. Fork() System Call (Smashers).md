
# [L-1.8: Fork System call with Example | Fork() system call questions](https://youtu.be/ixq5cpdEO2Q)

**Fork()** - Create a Child Process that will be clone of the Parent Process
- It is required if parent process is busy somewhere
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
- If we don't want to use Fork() we could use Thread
- Thread -> If a parent is busy, we can make a thread, that create a third hand of the process.
- It is shared