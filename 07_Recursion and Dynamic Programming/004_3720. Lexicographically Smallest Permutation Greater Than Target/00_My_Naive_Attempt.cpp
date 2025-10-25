// LeetCode (3720. Lexicographically Smallest Permutation Greater Than Target): 
// https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target 


// This code only passes 458 / 761 testcases 

// The iterative approach over target string to build the answer string isn't the right way to build the desired logic, but other intuitions regarding building a correct solution are correct in this code, that's why I wanted to record this attempt of mine as well in this repo 


#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        unordered_map<char, int> charFreqMp;
        for (char ch : s) {
            charFreqMp[ch]++;
        }
        
        string ans = "";
        bool foundBiggerChar = false;
        
        for (char ch : target) {
            if (!foundBiggerChar) {
                unordered_map<char, int>::iterator it = charFreqMp.find(ch);
                
                if (it != charFreqMp.end() && charFreqMp[ch] != 0) {
                    ans += ch;
                    charFreqMp[ch]--;
                }
                else {
                    for (int i = int((ch - 'a') + 1); i < 26; i++) {
                        char newCh = char('a' + i);
                        
                        unordered_map<char, int>::iterator it2 = charFreqMp.find(newCh);
                        if (it2 != charFreqMp.end() && charFreqMp[newCh] != 0) {
                            ans += newCh;
                            charFreqMp[newCh]--;
    
                            foundBiggerChar = true;
                            break;
                        }
                    }
                    if (!foundBiggerChar) {
                        ans = "";
                        break;
                    }
                }
            }
            else {
                string temp = "";
                for (const pair<char, int> &p : charFreqMp) {
                    int freq = p.second;
                    while (freq--) temp += p.first;
                }
                sort(temp.begin(), temp.end());
                ans += temp;
                break;
            }
        }

        return (ans == target) ? "" : ans;
    }
};