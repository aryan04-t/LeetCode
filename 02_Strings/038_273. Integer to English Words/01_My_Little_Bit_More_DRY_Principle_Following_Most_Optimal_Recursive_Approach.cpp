// LeetCode (273. Integer to English Words): 
// https://leetcode.com/problems/integer-to-english-words/ 


#include<vector> 
#include<string> 
#include<unordered_map> 
using namespace std; 


class Solution {
public:

    void assignTensAndOnes(int tens, int ones, unordered_map<int, string> &wordsMap, string &words){
        if(tens == 0){
            if(ones >= 1){
                words += (wordsMap[ones] + ' '); 
            }
        }
        else if(tens == 1){
            words += (wordsMap[10 + ones] + ' '); 
        }
        else if(tens >= 2){
            words += (wordsMap[tens * 10] + ' '); 
            if(ones >= 1){
                words += (wordsMap[ones] + ' '); 
            }
        }
    }

    void helperFunc(const int &num, long long divideUsing, int suffixCount, unordered_map<int, string> &wordsMap, const vector<string> &suffixVector, string &words){

        int newNum = num / divideUsing; 
        if(newNum == 0) return; 

        int currPart = newNum % 1000; 

        helperFunc(num, divideUsing * 1000, suffixCount+1, wordsMap, suffixVector, words); 

        string currPartStr = to_string(currPart); 
        int i = 0; 
        
        if(currPartStr.length() == 3){

            int hundreds = int(currPartStr[i++] - '0'); 
            words += (wordsMap[hundreds] + ' '); 
            words += (suffixVector[0] + ' '); 

            int tens = int(currPartStr[i++] - '0'); 
            int ones = int(currPartStr[i] -'0'); 

            assignTensAndOnes(tens, ones, wordsMap, words); 
        }
        else if(currPartStr.length() == 2){
            
            int tens = int(currPartStr[i++] - '0'); 
            int ones = int(currPartStr[i] - '0'); 

            assignTensAndOnes(tens, ones, wordsMap, words); 
        }
        else if(currPartStr.length() == 1){
            int ones = int(currPartStr[i] - '0'); 
            if(ones >= 1){
                words += (wordsMap[ones] + ' '); 
            }
        }

        if(suffixCount > 0 && currPart > 0){
            words += (suffixVector[suffixCount] + ' '); 
        }
    }

    string numberToWords(int num) {

        if(num == 0) return "Zero"; 

        int divideUsing = 1; 
        int suffixCount = 0; 
        string words = "";

        unordered_map<int, string> wordsMap({
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
            {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, 
            {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, 
            {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, 
            {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"} 
        }); 

        vector<string> suffixVector({"Hundred", "Thousand", "Million", "Billion"});  

        helperFunc(num, divideUsing, suffixCount, wordsMap, suffixVector, words); 
    
        return words.substr(0, words.length()-1); 
    }
};


// T.C. = O(log(n) base 10) 
// S.C. = O(log(n) base 10) 

// Here, n = the value of input variable num 