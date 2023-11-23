/*
    Q: find the minimum element in sorted rotated array

    link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/

// brute force - linear search

// optimised code

int findMin(vector<int> &nums)
{

    int low = 0, high = nums.size() - 1;

    // If the array is not rotated
    if (nums[low] <= nums[high])
    {
        return nums[low];
    }

    // Binary search
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // Check if mid is the minimum element
        if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
        {
            return nums[mid];
        }
        // If the left half is sorted, the minimum element
        // must be in the right half
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }

        // If the right half is sorted, the minimum element
        // must be in the left half
        else
        {
            high = mid - 1;
        }
    }

    // If no minimum element is found, return -1
    return -1;
}