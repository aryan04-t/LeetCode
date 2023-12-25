// LeetCode (155. Min Stack): 
// https://leetcode.com/problems/min-stack/ 


#include<vector>
#include<utility>
using namespace std;


class MinStack {

private:
    vector<pair<int, int>> v;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()){
            pair<int, int> p;
            p.first = val;
            p.second = val;
            v.push_back(p);
        }
        else{
            pair<int, int> p;
            p.first = val;
            p.second = min(val, v.back().second);
            v.push_back(p);
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() { 
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};


/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// T.C. = O(1) 
// S.C. = O(1) 

