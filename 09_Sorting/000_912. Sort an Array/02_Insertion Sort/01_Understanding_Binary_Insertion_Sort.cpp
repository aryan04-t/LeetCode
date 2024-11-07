/*


# Bianry Insertion Sort: 


1. Well "Binary Insertion Sort" is just a modified version of "Insertion Sort". 

2. In "Insertion Sort" we performed linear search for finding the correct insertable position of our current element, and while performing this linear search we also shifted the elements along the way and like this we had the best complexity of insertion sort to be at least O(n) instead of O(n^2). 

3. But in "Binary Insertion Sort" you basically use binary search to find the index where the current element should be inserted in the left side sorted array, and then you perform shifting from the current element's index-1 till the position where the element has to be inserted, and then you insert the element. 

4. Due to using binary search in insertion sort we have reduced the number of comparisons needed to insert an element from O(N) to O(log N), but still this isn't an improvement from time complexity's perspective if we see it from the perspective for normal datatypes, because for shifting the elements you still have to perform the O(n) time complexity shifiting operations. 

5. But due to the use of binary search in insertion sort the best case time complexity of "Binary Insertion Sort" is O(n * log(n)) which is a downgrade from "Insertion Sort's" best case time complexity. 

6. But "Binary Insertion Sort" isn't that useless, it's still a valid algorithm that can be useful in certain situations, particularly when the overhead of comparisons is high as compared to the cost of shifting elements. 

7. Binary insertion sort is a prime example of trade-off, we talk about "time-space trade off" in Data Structures and Algorithms, here we traded the best case time complexity of "Insertion Sort" so that we can have a specialized sort for complex datatypes where the comparison is more costly operation than shifting them. 

8. That's why "Binary Insertion Sort" may offer better performance than "Insertion Sort" in scenarios where comparison operations are more costly than element shifting operations. 


*/ 
