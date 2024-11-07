// LeetCode (295. Find Median from Data Stream): 
// https://leetcode.com/problems/find-median-from-data-stream/ 


#include<vector>
#include<algorithm> 
using namespace std; 


/*
    Your MedianFinder object will be instantiated and called as such:
    MedianFinder* obj = new MedianFinder();
    obj->addNum(num);
    double param_2 = obj->findMedian();
*/


class MedianFinder {

private: 
    vector<int> v; 

public:

    MedianFinder(){
        
    }
    
    void addNum(int num){

        v.push_back(num); 
        sort(v.begin(), v.end()); 
    
    }
    
    double findMedian(){
        
        int n = v.size(); 
        
        if(n & 1){
            return double(v[n/2]); 
        }
        else{ 
            return double(v[(n/2)-1] + v[n/2])/2.0;
        }
    }
};


/*

// T.C. = 
    - addNum() = O(n * log(n)) 
    - findMedian() = O(1) 

// S.C. = 
    - addNum() = O(log(n)) 
    - findMedian() = O(1) 

*/