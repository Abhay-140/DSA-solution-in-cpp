/*
    Q : Trapping Rain Water

    link : https://leetcode.com/problems/trapping-rain-water/description/
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //brute force
    int trap(vector<int> &height)
    {
        vector<int> arr;
        int count = 0, n = height.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (count < height[i])
                count = height[i];
        }

        while (count)
        {
            for (int i = 0; i < n; i++)
            {
                if (height[i] > 0)
                {
                    arr.push_back(height[i] - 1);
                }
                else
                {
                    arr.push_back(height[i]);
                }
            }

            for (int i = 0; i < n - 1; i++)
            {
                if (height[i] > 0)
                {
                    int temp = 0, j = i + 1;
                    while (j < n - 1 && height[j] == 0)
                    {

                        temp++;
                        j++;
                    }
                    if (j == n - 1 && height[j] == 0)
                        temp = 0;

                    ans += temp;
                    i = j - 1;
                }
            }
            height = arr;
            arr.clear();
            count--;
        }

        return ans;
    }


    //optimised code
      int trapOptimised(vector<int>& height) {
        int n=height.size();
        int left[n],right[n],temp=INT_MIN;

        for(int i=0 ; i<n ; i++){
            if(temp < height[i]){
                temp=height[i];
                left[i]=height[i];
            }
            else{
                left[i]=temp;
            }
        }

        temp=INT_MIN;
        for(int i=n-1 ; i>=0 ; i--){
            if(temp < height[i]){
                temp=height[i];
                right[i]=height[i];
            }
            else{
                right[i]=temp;
            }
        }

        int ans=0;
        for(int i=0 ; i<n ; i++){
            ans += min(left[i],right[i]) - height[i];
        }

        return ans;

    }

};
int main()
{
    Solution sol;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trapOptimised(v);
    return 1;
}