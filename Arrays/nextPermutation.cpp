/*
    Q : next permutation

    link : https://leetcode.com/problems/next-permutation/description/
*/

// brute force
void swap(std::vector<int> &nums, int i, int l)
{
    int temp = nums[i];
    nums[i] = nums[l];
    nums[l] = temp;
}

void allPermutation(std::vector<int> &nums, int l, std::vector<std::vector<int>> &ans)
{
    if (l == nums.size() && find(ans, nums) == -1)
    {
        ans.push_back(nums);
        return;
    }

    for (int i = l; i < nums.size(); i++)
    {
        swap(nums, i, l);
        allPermutation(nums, l + 1, ans);
        swap(nums, i, l);
    }
}

int find(std::vector<std::vector<int>> &ans, std::vector<int> &nums)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == nums)
        {
            return i;
        }
    }
    return -1;
}

void nextPermutation(std::vector<int> &nums)
{
    std::vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    std::vector<std::vector<int>> ans;
    allPermutation(temp, 0, ans);
    sort(ans.begin(), ans.end()); // for getting ans in ascending order

    int idx = find(ans, nums);

    if (idx == ans.size() - 1)
    {
        sort(nums.begin(), nums.end()); // Return the first permutation (sorted order)
    }
    else
    {
        nums = ans[idx + 1];
    }
}

// optimised
void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void nextPermutation(vector<int> &nums)
{
    if (nums.size() == 1)
        return;

    int i = nums.size() - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }
    if (i == 0)
        sort(nums.begin(), nums.end());
    else
    {
        int j = nums.size() - 1;

        for (; j >= i; j--)
        {
            if (nums[i - 1] < nums[j])
                break;
        }
        swap(nums, i - 1, j);
        reverse(nums.begin() + i, nums.end());
    }
}
