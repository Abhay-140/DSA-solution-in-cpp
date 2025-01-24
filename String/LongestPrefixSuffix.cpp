/*
    Q: Longest Prefix Suffix

    link: https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
*/

class Solution
{

public:
    // brute force - check all posible prefix and suffix and match O(n^2)
    int lps(string s)
    {

        int ans = 0, n = s.length();

        for (int i = 0; i < n - 1; i++)
        {

            if (s.substr(0, i + 1) == s.substr(n - i - 1))
            {
                ans = i + 1;
            }
        }

        return ans;
    }



    // optimised code with "KMP algorithm"  O(|s|)
    int lps(string s)
    {
        // Initialize an array to store the Longest Prefix Suffix values
        vector<int> lps(s.length(), 0);

        // Initialize two pointers l and r
        int l = 0, r = 1;

        // Iterate through the input string
        while (r < s.length())
        {
            // If characters at indices l and r match
            if (s[l] == s[r])
            {
                // Update lps[r] to l + 1
                lps[r] = l + 1;
                // Move both pointers to the next characters
                l++;
                r++;
            }
            else
            {
                // If characters don't match
                if (l == 0)
                {
                    // If l is already at the beginning, move r to the next character
                    r++;
                }
                else
                {
                    // If l is not at the beginning, backtrack to the previously matched prefix
                    l = lps[l - 1];
                }
            }
        }

        // Return the last element of the lps array
        return lps.back();
    }
};