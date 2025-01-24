/*
   Q: Reverse the Array


   link : https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

*/

//optimized code

class Solution
{
    public:
    
    string reverseWords(string S) 
{ 
    int end = S.size() - 1;
    int start = end;
    string ans = "";

    for (int i = end; i >= 0; i--) {
        
        if (i == 0 ) {
            start = i;
            while (start <= end) {
                ans = ans + S[start];
                start++;
            }
            
         }
        
        else if (S[i] == '.') {
            start = i+1;
            while (start <= end) {
                ans = ans + S[start];
                start++;
            }
           
            ans = ans + '.';
            
            end = i - 1;
        }
    }

    return ans;
} 


};

