// LeetCode (2487. Remove Nodes From Linked List): 
// https://leetcode.com/problems/remove-nodes-from-linked-list/ 


#include<vector> 
#include<algorithm> 
#include<limits.h> 
using namespace std; 


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// - - - - - - - - - - 


/*

# This is a Epic Scenario to witness: 

- This is a even more optimized version of "My Optimal Recursive Approach", but this code of mine gives TLE error, while this approach has O(2n) time complexity, but before written recursive approach had O(4n) time complexity 
- And the reason is really interesting why this happened that this code gives TLE, and no, the platform is not having any techincal issue, this approach consumes more runtime than O(4n) approach, even though this is O(2n) approach theoretically 

* Well I intented to optimize my perivous written "Optimal Recursive Approach", and after seeing the time complexity of this code to be O(2n), I was sure that this code will have lesser runtime, but I was shocked to see that this code gave TLE error 
* Although the time complexity of this code is so called O(2n), because we take one aspect of this code to be for granted, and that aspect has caused this code to hit TLE error 

@ In the end of this code I have explained in comments that why this happened, and what is the aspect that I usually take for granted but that aspect for granted is the reason that this code is hitting TLE error. 

*/


/*
    Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
*/ 


class Solution {
public:

    void collectUsefulNodes(ListNode* head, int &maxi, vector<ListNode*> &usefulNodes, vector<ListNode*> &uselessNodes){

        if(head == nullptr) return; 

        collectUsefulNodes(head->next, maxi, usefulNodes, uselessNodes); 

        maxi = max(maxi, head->val); 

        if(head->val >= maxi) usefulNodes.push_back(head); 
        else uselessNodes.push_back(head); 
    }

    void freeUpMemory(vector<ListNode*> &uselessNodes){
        for(ListNode* node : uselessNodes){
            node->next = nullptr; 
            delete node; 
        }
    }
    
    ListNode* removeNodes(ListNode* head) {

        int maxi = INT_MIN; 
        vector<ListNode*> usefulNodes; 
        vector<ListNode*> uselessNodes; 
        
        collectUsefulNodes(head, maxi, usefulNodes, uselessNodes); 

        int m = usefulNodes.size(); 
        ListNode* newHead = nullptr; 
        ListNode* newTail = nullptr; 
        
        if(m > 0){
            newHead = usefulNodes[m-1]; 
            newTail = usefulNodes[m-1]; 
        } 

        for(int i=m-2; i >= 0; i--){
            newTail->next = usefulNodes[i]; 
            newTail = newTail->next; 
        }  

        freeUpMemory(uselessNodes); 

        return newHead; 
    }
};


// T.C. = O(n) + O(n) = O(2n) = O(n) 
// S.C. = O(n) 

// Here, n = the total number of nodes which are present inside the given "singly linked list" 


/*

# Why this "Even more Optimized Recursive Approach Code" gives TLE Error while the code from which this code has evolved from, the "My Optimal Recursive Approach Code", that code didn't gives TLE error: 

- I am loving this scenairo 
- Theoretically this code should take less runtine than the previous written code 
- But in this approach I was just trying to optimize my before written recursive approach runtime wise 
- And I felt that I optimized the previous approach pretty well, as the T.C. of last appraoch was O(4n) constant 4 got dropped, and time complexity of this approach is O(2n) the constant 2 obviously gets dropped, the time complexity of both approach turns out to be O(n) 
- But when the runtime is calculated, it is not calculated using asymptotic notations, we know that, the asymptotic notations tell the order of growth of our solution, but in reality the runtime is calculated in milliseconds or seconds, and that's why the constants which we're dropping to find the asymptotic notations like Big Oh, those constants also matter alot when it comes to calculating runtime acutally 
- Because obviously 4n time will be more than 2n when the time is calculated in milliseconds, and the time limit exceeded error comes when the time limit that's set by the platform gets crossed when our code is running 


@ Then Why O(4n) code is not giving TLE and O(2n) code is giving TLE: 

- I don't know the reason for sure, but I guess I have an idea why this is happening 
- I can be wrong, but this is my reasoning for why this phenomenon happened 

$ The O(2n) code is giving TLE beacuse of vector's push_back() function.

- We consider the time complexity of vector's push_back() function to be O(1) 
- But actually it is amortized O(1), it means the averaged out time complexity of vector's push_back() function is O(1) 
- Means, whenever a vector's capacity gets full, it reallocates itself with double capacity and it copies all the old elements from the old loaction to the new reallocated location and then it performs the push back function 
- Now due to this reallocation of vector, the push_back() function's time complexity was O(n) for this paritcular time, but now this vector has doubled its space and it won't need to reallocate again for a significant amount of time and that's why this reallocation of O(n) time complexity will be averaged out by the other O(1) future push_backs  
- But still when measuring runtime in milliseconds the time consumed by these reallocations is still added to the total runtime time 


@ That's why in my previous code, although the time complexity was O(4n) but the runtime didn't exceeded the time limit of question as there were no constant vector reallocations because the size of maxFromRight vector was fixed 
@ But in this approach, when I removed that vector to optimize the 4n runtime and make it 2n, I took 2 zero capacity vectors, and I don't have any other option also because I don't know what exact size they will be, and while backtracking when I am pushing back values in them, they get reallocated a lot of times because of reaching maximum capacity again and again, and these reallocations dominate the 2n time complexity and the actual runtime crosses the time limit that's set by the platform for this question 

@ I was amazed by the fact that how under the hood implemetation of STL containers impact the runtime of our code and many times we don't try to understand the under the hood implementation of these STL containers because we think that "it is not needed, just know how to use them", but I feel that work smartly, don't go in depth of all the concepts in early stage, but try to understand things in depth also whenever you get time, working smart is the most essential thing, but I preach working hard also, just know when to do what, when to opt for hard work and when to opt for smart work, I like to spare time to know things in depth so that I get a good grasp of fundamentals, and I was able to understand what just happened right now on my own without any help of ChatGPT or StackOverflow because I try to understand concepts in depth and that habit of mine helped me here understand this senario on my own 
@ Try to learn building logic, learn how to approach a problem, recognize patterns, and have strong knowledge of fundamentals 

# In conclusion, assuming vector's push_back() function's amortized O(1) time complexity to be not lethal at all for my code's time complexity, caused this code to hit TLE error 
# What a beautiful naive mistake this was, that I made today, but I got to learn to a lot things, I am happy :) 

*/