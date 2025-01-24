/*
    Q: Transform String

    link: https://www.geeksforgeeks.org/problems/transform-string5648/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
*/

class Solution {

    public:

    //  Brute force O(N)
    public:
    int transform (string A, string B)
    {
        int ans = 0, i = A.length(), j = B.length();
        
        if(i != j){ return -1; }
        
        unordered_map<char,int> mp;
        
        for(int k=0 ; k<i ; k++){
            mp[A[k]]++;
        }
        
        for(int k=0 ; k<j ; k++){
            mp[B[k]]--;
        }
        
        for(auto it : mp){
            if(it.second != 0){
                return -1;
            }
        }
        
        while(i-1 > -1){
            
            if(A[i-1] != B[j-1]){
                ans++;
                i--;
            }
            else {
                i--;
                j--;
            }
        }
        
        return ans;
    }

    //  Optimized code O(<N)
    int transform (string A, string B)
    {
        int ans = 0, i = A.length(), j = B.length();
        
        if(i != j){ return -1; }
        
        int count[256];
        memset(count, 0, sizeof(count)); // fill with zero from count pointer
        // count characters in A
        for (int k = 0; k < i; k++)
            count[A[k]]++;
        // subtract count for every character in B
        for (int k = 0; k < j; k++)
            count[B[k]]--;
        // Check if all counts become 0
        for (int k = 0; k < 256; k++)
            if (count[k])
                return -1;
        
        while(i-1 > -1){
            
            if(A[i-1] != B[j-1]){
                ans++;
                i--;
            }
            else {
                i--;
                j--;
            }
        }
        
        return ans;
    }
}