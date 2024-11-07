# How does a STL container pair works with less and greater than operators in C++: 

- In C++, when you compare pairs using the less than (<) or greater than (>) operators, the comparison is done lexicographically. This means that if you have two pairs (a, b) and (c, d), the comparison is performed first on a, and if a is equal, then on b.

- Here's how it works:

>> If a is less than c, then (a, b) is considered less than (c, d).  
> If a is equal to c, then b is compared with d. If b is less than d, then (a, b) is considered less than (c, d). If b is greater than d, then (a, b) is considered greater than (c, d).  
> If a is greater than c, then (a, b) is considered greater than (c, d).  

```
This behavior allows you to use pairs in sorting algorithms or data structures like std::set and std::map where elements are ordered.
```