# All About Triangle: 


## Validate, 3 Given Sides Form a Triangle or Not: 


- Sum of any 2 sides of a triangle is always greater than the 3rd side in all pairs (a + b > c && b + c > a && c + a > b) => then only it could be a triangle 

- But if a < b < c -> means if a, b and c are sorted in increasing order, then if a + b > c -> this condition is enough to know that a, b and c will form a valid triangle because (a + c > b && b + c > a) will always be true due to the sorted nature of sides of triangle a, b and c (a < b < c) 


_ _ _ _ _ _ _ _ 



## Area of Triangle 


## How to Find Sides of Triangle When Coordinates are Given: 

- If coordinates are given, find the sides' length  

= Given coordinates (x1, y1), (x2, y2), (x3, y3)  
= A = sqrt((x2 - x1)^2 + (y2 - y1)^2)  
= B = sqrt((x3 - x2)^2 + (y3 - y2)^2)  
= C = sqrt((x1 - x3)^2 + (y1 - y3)^2)  


## How to Find Area of Triangle When Sides are Given, But Height is not Known: 

### Heron's Formula (Use when side lengths are known): 

- Semi Parameter (S) = (a + b + c) / 2  
- Triangle's Area = sqrt(s*(s-a)*(s-b)*(s-c))  


### Shoelace Formula (Use when only vertice coordinates are known): 

- Triangle's Area = 1/2 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))  