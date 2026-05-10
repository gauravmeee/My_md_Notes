# Pointers and References Problems

### **Pointers & Memory (C / C++)**

#### Swap Using Pointers

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

#### Dynamic Array Allocation

```c
void handleArray() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    free(arr);
}
```