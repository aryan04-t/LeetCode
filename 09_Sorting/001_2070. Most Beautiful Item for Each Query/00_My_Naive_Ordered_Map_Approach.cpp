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


// T.C. = O(2*m*log(l)) + O(n*log(l)) + O(l) + O(n) = O(max(m*log(l), n*log(l))) 
// S.C. = O(l) + O(n) = O(max(l,n)) 

// Here, m = total number of 2-sized vectors which are present inside the 2-D input vector items, 
// n = total number of elements which are present inside the input vector named queries, 
// l = total number of unqiue prices which are present inside the items and queries vetors 