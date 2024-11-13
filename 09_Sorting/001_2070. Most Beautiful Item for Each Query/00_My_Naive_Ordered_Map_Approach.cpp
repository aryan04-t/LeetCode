// LeetCode (2070. Most Beautiful Item for Each Query): 
// https://leetcode.com/problems/most-beautiful-item-for-each-query 


#include<map>
#include<vector> 
using namespace std;  

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        map<int, int> mp;

        for (const vector<int> &v : items) {
            if (v[1] > mp[v[0]]) mp[v[0]] = v[1]; 
        }

        int i = 0;
        for (int q : queries) {
            if (mp.find(q) == mp.end()) mp[q] = 0;
        }

        map<int, int>::iterator it1 = mp.begin(); 
        map<int, int>::iterator it2 = mp.begin(); 

        it2++;
        
        while (it2 != mp.end()) {
            if (it1->second > it2->second) {
                it2->second = it1->second; 
            }
            it1++;
            it2++;
        }

        int n = queries.size(); 
        vector<int> ans(n, 0); 

        i = 0;
        for (int q : queries) {
            ans[i++] = mp[q]; 
        }

        return ans;
    }
};