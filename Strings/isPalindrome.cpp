/*
    Q : valid palindrome

    link : https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution
{
public:
    // optimised (2n)
    bool isPalindrome(string s)
    {
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] >= 65 and s[i] <= 90)
            {
                s[idx] = s[i] + 32;
                idx++;
            }
            else if ((s[i] >= 97 and s[i] <= 122) or (s[i] - '0' <= 9 and s[i] - '0' >= 0))
            { // type cast a char into integer ("2"-'0')
                s[idx] = s[i];
                idx++;
            }
        }
        int i = 0;
        while (i < idx - 1)
        {
            if (s[i] != s[idx - 1])
            {
                return false;
            }
            i++;
            idx--;
        }
        return true;
    }

    // using two pointer (n)
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;

        while (i <= j)
        {

            if (s[i] >= 65 and s[i] <= 90)
            {
                s[i] = s[i] + 32;
            }
            else if (s[j] >= 65 and s[j] <= 90)
            {
                s[j] = s[j] + 32;
            }
            else if (!(s[i] >= 97 and s[i] <= 122) and !(s[i] - '0' <= 9 and s[i] - '0' >= 0))
            {
                i++;
            }
            else if (!(s[j] >= 97 and s[j] <= 122) and !(s[j] - '0' <= 9 and s[j] - '0' >= 0))
            {
                j--;
            }
            else if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};