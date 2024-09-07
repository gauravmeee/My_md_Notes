
# Common Errors

**1. int& sum=0;**
> error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'

References in C++ must be bound to a valid object or variable, not a temporary value like an integer literal (0).

**2. UndefinedBehaviorSanitizer: undefined-behavior**

> runtime error: signed integer overflow: 1073741824 + 1073741824 cannot be represented in type 'int' (solution.cpp)

This happens when you're trying to store a value in an int type that exceeds its maximum allowable value (for a 32-bit int, this maximum is typically 2,147,483,647).

solution: change `int` to `long long`
