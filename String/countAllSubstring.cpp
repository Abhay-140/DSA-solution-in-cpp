/*
    Q: Palindromic substrings

    link: https://leetcode.com/problems/palindromic-substrings/submissions/1125737971/
*/

class Solution
{
public:
    // brute force - O(n^3)
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = i; j < s.length(); ++j)
            {
                if (checkPalindrome(s.substr(i, j - i + 1)))
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool checkPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    // optimised code - O(n^2)
    int countSubstrings(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cnt = cnt + total(s, i, i) + total(s, i, i + 1);
        }
        return cnt;
    }

    int total(string s, int l, int r)
    {
        int cnt = 0;
        while (-1 < l and r < s.length() and s[l] == s[r])
        {
            cnt++;
            l--;
            r++;
        }

        return cnt;
    }
};