/*
    Q: longest palindromic substring

    link: https://leetcode.com/problems/longest-palindromic-substring/description/
*/

class Solution
{
public:
    // brute force- find all substring and then check whether it is a longest palindromic or not O(n^3)

    

    // optimised code - O(n^2)
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            // to check longest palindromic length
            int len = max(check(s, i, i), check(s, i, i + 1));
            // update the previous ans
            if (end - start < len)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int check(string s, int l, int r)
    {
        while (-1 < l and r < s.length() and s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
};