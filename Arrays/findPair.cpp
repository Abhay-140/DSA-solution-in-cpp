/*
    Q:Find if there is a pair with a given sum in the rotated sorted Array

    link: https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/?ref=lbp

*/

// optimised code

#include <iostream>
class Solution
{
public:
    bool findPair(int arr[], int n, int x)
    {
        int pivot = 0; // find pivot point
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                pivot = i;
                break;
            }
        }

        int l = pivot + 1, r = pivot;
        // searching pair
        while (l - pivot - 1 < r + pivot + 1)
        {
            if (arr[l] + arr[r] == x)
                return true;
            else if (arr[l] + arr[r] < x)
                l = (l + 1) % n;
            else
                r = (r - 1 + n) % n;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    int arr[] = {10,-10};
    std::cout << std::boolalpha << sol.findPair(arr, 2, 0);
    return 0;
}