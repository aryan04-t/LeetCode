// LeetCode (3692. Majority Frequency Characters) 
// https://leetcode.com/problems/majority-frequency-characters 


#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:

    string majorityFrequencyGroup(string s) {
        
        unordered_map<char, int> charFreqMp;
        for (char ch : s) charFreqMp[ch]++;

        unordered_map<int, string> freqGroups;

        int maxFreqGroupSize = -1;
        int maxFreqGroupFreq = -1;

        for (const pair<char, int> &p : charFreqMp) {
            
            char ch = p.first;
            int freq = p.second;
            freqGroups[freq].push_back(ch);

            const string &str = freqGroups[freq];
            int currGroupSize = int(str.length());

            if (
                (currGroupSize > maxFreqGroupSize) ||
                (currGroupSize == maxFreqGroupSize && freq > maxFreqGroupFreq)
            ) {
                maxFreqGroupSize = currGroupSize;
                maxFreqGroupFreq = freq;
            }
        }

        string ans = freqGroups[maxFreqGroupFreq];

        return ans;
    }
};


// T.C. = O(n) + O(26) = O(n) 
// S.C. = O(26) + O(26) = O(1) 

// Here, n = the length of input string named "s" 