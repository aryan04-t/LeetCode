// LeetCode (3318. Find X-Sum of All K-Long Subarrays I):
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i

#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        int windows = n - k + 1;

        vector<int> ans;

        for (int i=0; i < windows; i++) {
            
            unordered_map<int, int> numFreqMap;
            for (int j=i; j < i+k; j++) {
                int num = nums[j];
                numFreqMap[num]++;
            }
            
            vector<pair<int, int>> freqNumVec;
            for (const pair<int, int> &p : numFreqMap) {
                int num = p.first;
                int freq = p.second;
                freqNumVec.push_back({ freq, num });
            }
            
            sort(freqNumVec.begin(), freqNumVec.end(), greater<pair<int, int>>());

            int sum = 0;
            for (int k=0; k < x; k++) {
                int m = freqNumVec.size();
                if (k < m) {
                    pair<int, int> p = freqNumVec[k];
                    int freq = p.first;
                    int num = p.second;
                    sum += (freq * num);
                }
            }

            ans.push_back(sum);
        }

        return ans;
    }
};