// LeetCode (804. Unique Morse Code Words): 
// https://leetcode.com/problems/unique-morse-code-words 


#include<unordered_map> 
#include<unordered_set> 
#include<string> 
using namespace std; 


class Solution {
public:

    int uniqueMorseRepresentations(vector<string>& words) {

        unordered_map<char, string> morseMap({
            {'a', ".-"}, 
            {'b', "-..."}, 
            {'c', "-.-."}, 
            {'d', "-.."}, 
            {'e', "."}, 
            {'f', "..-."},
            {'g', "--."}, 
            {'h', "...."}, 
            {'i', ".."},
            {'j', ".---"}, 
            {'k', "-.-"}, 
            {'l', ".-.."}, 
            {'m', "--"},
            {'n', "-."},
            {'o', "---"}, 
            {'p', ".--."}, 
            {'q', "--.-"}, 
            {'r', ".-."}, 
            {'s', "..."}, 
            {'t', "-"},
            {'u', "..-"}, 
            {'v', "...-"}, 
            {'w', ".--"},
            {'x', "-..-"}, 
            {'y', "-.--"}, 
            {'z', "--.."}
        });

        unordered_set<string> unqiueTransformations;

        for (const string &s : words) {
            string transformation = ""; 
            for (const char &ch : s) {
                transformation += morseMap[ch]; 
            }
            unqiueTransformations.insert(transformation); 
        }

        return unqiueTransformations.size(); 
    }
};


// T.C. = O(n*m) 
// S.C. = O(26) + O(n*m) = O(n*m) 

// Here, n = the length of 1-D input vector named "words", and m = the average length of all the strings present inside the input vector "words" 