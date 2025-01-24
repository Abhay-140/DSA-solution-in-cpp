/*
    Q :Remove all duplicates from a given string

    link: https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

class Solution
{
public:

    //optimised code O(n)
    string removeDuplicates(string str)
    {

        string ans = "";
        unordered_map<char, bool> mp;

        // true if the element is present atleast one time
        for (int i = 0; i < str.length(); i++)
        {
            mp[str[i]] = true;
        }

        // check all elements
        for (int i = 0; i < str.length(); i++)
        {
            if (mp[str[i]] == true)
            {
                ans += str[i];
                mp[str[i]] = false;
            }
        }
        return ans;
    }
};