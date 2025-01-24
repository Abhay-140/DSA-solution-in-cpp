/*
    Q: count total palindromic subsequences of string

    link:https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
*/


class Solution{
public:

    // brute force - O(n^3)
    bool checkPalindrome(string s){
        int l=0,r=s.length()-1;
        
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
    
    void subsequence(string s,string ans,long long int& cnt,int idx){
        
        if(idx == s.length()){
            if(checkPalindrome(ans) && ans.length() != 0){
                cnt++;
            }
            return;
        }
        //exclude
        subsequence(s,ans,cnt,idx+1);
        
        //include
        subsequence(s,ans+s[idx],cnt,idx+1);
    }
    
    long long int  countPS(string str)
    {
       long long int cnt=0;
       subsequence(str,"",cnt,0);
       return cnt;
    }

    // optimised code - O(n^2) 
    long long int  countPS(string s)
    {
       int n = s.length();
       vector<vector<long long int>> dp(n , vector<long long int>(n , 0));
       const int mod = 1e9+7;
       for(int g = 0; g < n; g++){ // g=gap
           for(int i = 0 , j = g ; j < n ; i++, j++){
               if(g == 0){ 
                   //if gap is 0 means single char is always palindrome
                   dp[i][j] = 1;
               }
              else if(g == 1){ //g=1 means 2 char if same than 3 or 2
                   if(s[i] == s[j]){
                       dp[i][j] = 3;
                   }
                   else{
                       dp[i][j] = 2;
                   }
               }
               else{
                   if(s[i] == s[j]){
                       dp[i][j] = 1+dp[i+1][j]+dp[i][j-1];
                       dp[i][j] %= mod;
                   }
                   else{
                       dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                       dp[i][j] %= mod;
                   }
               }
           }
       }
       return (dp[0][n-1]+mod)%mod; // ensure that value is in the range and handle for -ve values
    }
};