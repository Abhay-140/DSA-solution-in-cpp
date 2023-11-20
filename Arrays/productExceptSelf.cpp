/*
    Q: product of array except itself

    link : https://leetcode.com/problems/product-of-array-except-self/
*/
#include <bits/stdc++.h>
using namespace std;

// brute force
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> vec;
    int ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                ans = ans * nums[j];
            }
        }
        vec.push_back(ans);
    }
    return vec;
}

// optimised code with O(3n) space complexity
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int right[nums.size()], left[nums.size()];
    int a = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        a *= nums[i];
        left[i] = a;
    }

    a = 1;
    for (int i = nums.size() - 1; i > -1; i--)
    {
        a *= nums[i];
        right[i] = a;
    }

    ans.push_back(right[1]);
    for (int i = 1; i < nums.size() - 1; i++)
    {
        ans.push_back(left[i - 1] * right[i + 1]);
    }
    ans.push_back(left[nums.size() - 2]);

    return ans;
}

// optimised code with O(n) space complexity
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    int a = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        a *= nums[i];
        ans.push_back(a);
    }

    a = 1;
    for (int i = nums.size() - 1; i > -1; i--)
    {
        if (i == 0)
            ans[i] = a;
        else
        {
            ans[i] = ans[i - 1] * a;
            a *= nums[i];
        }
    }

    return ans;
}

// most optimised
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans(nums.size(), 1);
    int temp = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = temp;
        temp *= nums[i];
    }

    temp = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[i] *= temp;
        temp *= nums[i];
    }

    return ans;
}

void printArray(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    cout << "Product of all array elements except self is : ";
    printArray(productExceptSelf(v));
    return 1;
}