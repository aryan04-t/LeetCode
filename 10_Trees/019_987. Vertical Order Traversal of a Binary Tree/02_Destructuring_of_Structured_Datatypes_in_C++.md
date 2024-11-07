# Revisit to "auto" keyword and "range based for loops": 

- "auto" keyword and "range based for loops" were introduced in C++ 11. 
- Whenever you use auto keyword, you're basically allowing the compiler to automatically determine the type of a variable based on its initializer. 
- And range-based for loops provide a simpler syntax for iterating over elements in a range or a container, such as arrays, vectors, or other iterable data structures. 


# Using "auto keyword" and "Structured Binding Functionality" of C++ for Destructuring STL Containers like "pair" and "tuple": 

- In C++ 17 "Structured Binding" functionality was introduced, and this functionality lets you do unpacking of structured datatypes like "pair" and "tuple". 
- Structured binding can only be used with the "auto" keyword. 
- Unpacking of structured datatypes is also known as "Destructuring of Structured Datatypes". 
- So, using this functionality structured binding, you can basically destructure pair and tuple into individual variables. 


``` 
// Code Example of "Destructuring a Pair" 

#include <iostream>
#include <utility>
using namespace std;

int main() {
    
    pair<int, double> myPair = {42, 3.14};
    
    // Structured binding to unpack the elements of the pair
    auto [x, y] = myPair;
    
    // You can also destructure the pair into reference variables or constant variables, just like you want 
    auto &[a, b] = myPair;
    const auto &[d, e] = myPair;

    // Now you can use x and y directly
    cout << "First element: " << x << endl;
    cout << "Second element: " << y << endl;
    
    return 0;
}
```


> Destructuring pairs and tuples like this can make your much code more readable, and using "range based for loop", "auto keyword", and "destructuring of pairs" together you can also iterate over complex containers in an easy manner and your code will look much more readable. 

> You can check out the next code file which is present in this directory, there you can see the example of what I mean when I say that "you can iterate over complex containers easily and you can make your code much more readable". 