// LeetCode (49. Group Anagrams): 
// https://leetcode.com/problems/group-anagrams/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
#include<algorithm> 
using namespace std;


class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, int> mp; 
        vector<vector<string>> ans; 

        int n = strs.size(); 

        for(int i=0; i < n; i++){
            
            string temp = strs[i]; 
            sort(temp.begin(), temp.end());

            if(mp.find(temp) == mp.end()){
                mp[temp] = ans.size(); 
                ans.push_back({strs[i]}); 
            }
            else{
                int index = mp[temp]; 
                ans[index].push_back(strs[i]); 
            }
        }

        return ans; 
    }
}; 


// T.C. = O(n * k * log(k)) 
// S.C. = O(log(k)) + O(l*k) + O(n*k) = O(n*k) 

// Here, n = the total number of strings which are present inside the input vector named "strs", and k = the average length of all the strings which are present inside the input vector named "strs", and l = the total number of unique anagram signatures which are created (here, this signature is created by sorting the strings) 