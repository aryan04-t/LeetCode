// LeetCode (703. Kth Largest Element in a Stream): 
// https://leetcode.com/problems/kth-largest-element-in-a-stream/ 


#include<queue>
using namespace std; 


class KthLargest {

private: 
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        int i=0; 
        while(i < nums.size()){
            if(i < k){
                this->pq.push(nums[i]); 
            }
            else if(this->pq.top() < nums[i]){
                this->pq.pop();
                this->pq.push(nums[i]); 
            }
            i++; 
        }
    }
    
    int add(int val) {
        if(pq.size() != this->k){
            this->pq.push(val); 
        }
        else{
            if(this->pq.top() < val){
                this->pq.pop(); 
                this->pq.push(val); 
            }
        }
        return this->pq.top();
    }
};

/*
    Your KthLargest object will be instantiated and called as such:
    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(val);
*/


/*
    T.C. => add() = O(log(k)) -> Here, k = the value of input variable named "k"  
            constructor() = O(n*log(k)) -> Here, n = the total number of elements whcih are present in given "nums" vector 

    S.C. => add() = O(1) 
            constructor() = O(k) -> Space complexity caused due to min-heap which has k largest elements of stream 
*/