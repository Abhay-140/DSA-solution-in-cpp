/*
    Q : lonrgest common prefix

    link : https://leetcode.com/problems/longest-common-prefix/description/

*/

class Solution
{
public:
    // brute force O(nm)
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = *min_element(strs.begin(), strs.end());
        if (strs.size() == 0)
            return "";
        // string l=max_element(strs.begin(),strs.end()); // for get max length element

        for (int i = 0; i < strs.size() - 1; i++)
        {
            string temp = "";
            for (int j = 0; j < strs[i].size() && j < strs[i + 1].size(); j++)
            {
                if (strs[i][j] == strs[i + 1][j])
                {
                    temp += strs[i][j];
                }
                else
                {
                    break;
                }
            }
            if (ans.size() > temp.size())
            {
                ans = temp;
            }
        }

        return ans;
    }

    // optimised code - O(2n) for searching min and max element
    string longestCommonPrefix(vector<string> &strs)
    {
        // taking the min element and max element adress
        string mn = *min_element(strs.begin(), strs.end()),
               mx = *max_element(strs.begin(), strs.end()),
               ans = "";
        int i = 0;

        while (i < mn.length())
        {
            // char matched then add in ans
            if (mn[i] == mx[i])
            {
                ans += mn[i];
            }
            // not matched then break
            else
            {
                break;
            }
            i++;
        }
        return ans;
    }

    // using trie data structure O(nm)
};