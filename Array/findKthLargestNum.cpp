/*
    Q : Kth Largest element in an array

    link : https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// brute force
int findKthLargest(vector<int> &nums, int k)
{

    sort(nums.begin(), nums.end());
    int ans;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (k == 1)
            ans = nums[i];

        k--;
    }
    return ans;
}

int findKthLargest(vector<int> &nums, int k)
{
    int ans;
    for (int i = 0; i < k; i++)
    {
        int max = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[max] < nums[j])
            {
                max = j;
            }
        }
        ans = nums[max];
        nums.erase(nums.begin() + max);
    }
    return ans;
}

// optimised code
int findKthLargest(vector<int> &nums, int k)
{

    priority_queue<int> que; // bydefault max heap in c++
    for (int i = 0; i < nums.size(); i++)
    { // inserting vector element in max heap
        que.push(nums[i]);
    }
    while (k - 1)
    { // finding kth lar element
        que.pop();
        k--;
    }
    return que.top();
}
