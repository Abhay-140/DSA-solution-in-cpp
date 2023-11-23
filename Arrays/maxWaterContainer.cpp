/*
    Q: Container with most water

    link: https://leetcode.com/problems/container-with-most-water/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force

    int maxArea(vector<int> &height)
    {
        int ans = INT_MIN;

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = 0; j < height.size(); j++)
            {
                if (i != j)
                {
                    int mn = min(height[i], height[j]);
                    if (mn * (j - i) > ans)
                        ans = mn * (j - i);
                }
            }
        }
        return ans;
    }

    // optimised code

    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, max = INT_MIN;

        while (l != r)
        {
            if (max < min(height[l], height[r]) * (r - l))
            {
                max = min(height[l], height[r]) * (r - l);
            }

            if (height[l] <= height[r])
                l++;
            else
                r--;
        }

        return max;
    }
};