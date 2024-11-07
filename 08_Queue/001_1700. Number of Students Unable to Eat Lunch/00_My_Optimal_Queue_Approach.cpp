// LeetCode (1700. Number of Students Unable to Eat Lunch): 
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/ 


#include<vector> 
#include<queue> 
using namespace std; 


class Solution {
public:

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = sandwiches.size(); 

        queue<int> q; 
        for(int val : students) q.push(val); 

        int oldQSize = 0; 
        int qSize = 0; 

        int j = 0; 
        while(!q.empty()){

            oldQSize = qSize;
            qSize = q.size();

            if(oldQSize == qSize) break;

            for(int i=0; i < qSize; i++){
                if(q.front() == sandwiches[j]){
                    q.pop(); 
                    j++;
                }
                else{
                    q.push(q.front());
                    q.pop();
                }
            }
        }

        return q.size();

    }
};


// T.C. = O(n) 
// S.C. = O(n) 

// Here, n = the total number of students which are present inside the input vector named "students" = the total number of sandwiches which are present inside the input vector named "sandwiches" 