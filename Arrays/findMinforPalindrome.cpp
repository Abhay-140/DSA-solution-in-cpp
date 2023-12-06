/*
    Q: Find minimum number of merge operations to make an array palindrome

    link : https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

*/

class Solution
{
public:
    // optimised code
    int findMinOps(int arr[], int n)
    {
        int ans=0,l=0,r=n-1; // Initialize result and pointer

        while(l <=r){
            if (arr[l] == arr[r]){
                l++; 
                r--;
            }else if(arr[l] > arr[r]){
                r--;
                arr[r] += arr[r+1];
                ans++;

            }else{
                l++;
                arr[l] += arr[l-1];
                ans++;
            }
        }
        return ans;
    }
};
