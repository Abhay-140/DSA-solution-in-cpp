?\/*
    Q: search in rotated sorted arrray

    link : https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

    // brute force

    int
    search(vector<int> &nums, int target)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// optimised code
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[l] <= nums[mid])
        { // <=, >= is to be remembered
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[r] >= target && target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

