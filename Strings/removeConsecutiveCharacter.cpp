/*
    Q : remove consecutive character

    link : https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1
*/

class Solution
{
public:
    // optimised code O(s)
    string removeConsecutiveCharacter(string s)
    {
        string ans = "";
        ans += s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i - 1] != s[i])
            {
                ans += s[i];
            }
        }
        return ans;
    }
};