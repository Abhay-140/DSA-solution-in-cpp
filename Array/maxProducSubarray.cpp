/*
    Q: Maximum Product Subarray

   link : https://leetcode.com/problems/maximum-product-subarray
*/

// brute force
int maxProduct(vector<int> &nums)
{
    int max = INT_MIN, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int temp = 1;

        for (int j = i; j < n; j++)
        {
            temp *= nums[j];
            if (max < temp)
                max = temp;
        }
    }
    return max;
}

// optimised code

int maxProduct(vector<int> &nums)
{
    int ans = nums[0], n = nums.size(), mi = nums[0], mx = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0)
        {
            swap(mi, mx);
        }

        mx = max(nums[i], mx * nums[i]);
        mi = min(nums[i], mi * nums[i]);
        ans = max(mx, ans);
    }
    return ans;
}

// optimised code 2

int maxProduct(vector<int> &nums)
{
    int ans = INT_MIN, temp = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        temp *= nums[i];
        ans = max(ans, temp);
        if (nums[i] == 0)
        {
            temp = 1;
        }
    }

    temp = 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        temp *= nums[i];
        ans = max(ans, temp);
        if (nums[i] == 0)
        {
            temp = 1;
        }
    }
    return ans;
}