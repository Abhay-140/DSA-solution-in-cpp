/*
    Q: longest substring without repeating characters

    link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution
{
public:

    // brute force - find all the substring and check character is repeating or not. O(n^2)

    //using vector optimised code O(n)
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        vector<char> vec;

        for (int i = 0; i < s.length(); i++)
        {
            // if element is not in vector
            if (find(vec.begin(), vec.end(), s[i]) == vec.end())
            {
                vec.push_back(s[i]);
            }
            else
            { // if element is in vector

                while (vec[0] != s[i])
                { // untill we get the last element
                    vec.erase(vec.begin());
                }
                vec.erase(vec.begin());
                vec.push_back(s[i]);
            }
            int size = vec.size();
            ans = max(size, ans);
        }

        return ans;
    }
};