# Code: 

```
std::ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
```


# Why are we using these above 2 lines of code?? 

- Well, the above two lines decrease the runtime of your program by changing some default C++ compiler settings 
- When you're writing a C++ code in a .cpp file, you can basically write C and C++ both the codes in this file, so just because of this nature of C++, you can also use I/O methods of both C and C++ in your C++ code 
- And just because you can use any of these I/O methods, that is why just to keep the output of your code always same, there are synchronization methods which are used in C++ which synchronize C and C++ I/O streams 

> When you use ``` ios_base::sync_with_stdio(false); ```, you're essentially breaking the synchronization mechanism between C and C++ I/O operations. 


# Example Code: 
```
#include <iostream>
#include <cstdio>

int main() {
    // Disable synchronization between C++ and C I/O
    std::ios_base::sync_with_stdio(false);

    // Using C++ stream
    std::cout << "This is a C++ stream." << std::endl;

    // Using C function
    printf("This is a C function.\n");

    return 0;
}
```

- In this example, after disabling synchronization, you're using both C++ streams (std::cout) and a C function (printf). Since synchronization is disabled, there's no guarantee on the order in which output will be flushed to the console. As a result, the output might not appear in the expected order. 



> Similarly, ```cin.tie(NULL);``` unties cin from cout. By default, cin is tied to cout, meaning that when cin is waiting for input, cout is flushed (output is displayed). By setting cin.tie(NULL);, you're essentially saying that you don't want cin to flush cout, which again can lead to a performance improvement, especially in scenarios where you're doing a lot of input operations but not necessarily outputting anything. 


# Note: 

- However, it's important to note that these optimizations are usually minor and may not make a noticeable difference in most programs. Additionally, it's generally safe to leave the default synchronization behaviour intact unless you have a specific reason to change it for performance reasons.