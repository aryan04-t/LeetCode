// LeetCode (380. Insert Delete GetRandom O(1)): 
// https://leetcode.com/problems/insert-delete-getrandom-o1/ 


#include<vector> 
#include<unordered_map> 
#include<cstdlib> 
using namespace std; 


class RandomizedSet {

private: 

    vector<int> v; 
    unordered_map<int, int> mp; 

public: 

    RandomizedSet() {}

    bool isPresent(int val){

        if(mp.find(val) == mp.end()){
            return false; 
        }

        return true; 

    }
    
    bool insert(int val) {
        
        if(isPresent(val)){
            return false;
        }

        v.push_back(val);

        mp[val] = v.size() - 1;

        return true; 

    }
    
    bool remove(int val) {
        
        if(!isPresent(val)){
            return false;
        }

        // You can also use "auto" keyword in below both lines where I have declared an iterator, this time I just wanted to declare an iterator with its complete syntax, I haven't declared an iterator using its complete syntax from a long time, that's why I just wanted to do it, nothing else 

        unordered_map<int, int>::iterator it1 = mp.find(val); 
        v[it1->second] = v[v.size() - 1]; 

        unordered_map<int, int>::iterator it2 = mp.find(v[v.size() - 1]); 
        it2->second = it1->second; 

        v.pop_back(); 
        mp.erase(it1); 

        return true;

    }
    
    int getRandom() {

        return v[(rand() % v.size())];
        
    }
    
};


/*
    Your RandomizedSet object will be instantiated and called as such:
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
*/


/*

// T.C.: 
    isPresent() = O(1) 
    insert() = O(1) 
    remove() = O(1) 
    getRandom() = O(1) 

// S.C. used by each object of "RandomizedSet" class = O(n) + O(n) = O(2n) = O(n) 

// Here, n = total number of elements which are inserted inside one object of "RandomizedSet" class 

*/ 
