/*
    Q: Smallest window in a string containing all the characters of another string

    link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/
*/

class Solution
{
public:
    // brute force - find all combination string and then check O(n^3)


    // optimised code  using sliding window technique - O(n)
    string smallestWindow(string s, string p)
    {
        // Initialize vectors to store character frequencies
        vector<int> pmp(26, 0), smp(26, 0);

        int l = 0, r = 0, curLen = 0, ansLen = INT_MAX;
        string ans = "-1";

        // Update character frequencies for pattern 'p'
        for (char c : p)
        {
            pmp[c - 'a']++;
        }

        int plen = p.size();

        while (r < s.length())
        {
            // Update character frequency in smp
            smp[s[r] - 'a']++;

            // Check if current character is in pattern 'p' and its frequency matches
            if (smp[s[r] - 'a'] <= pmp[s[r] - 'a'])
            {
                curLen++;
            }

            // Slide window while all characters in 'p' have their required frequencies
            while (curLen == plen)
            {
                // Update minimum window length if necessary
                if (r - l + 1 < ansLen)
                {
                    ans = s.substr(l, r - l + 1);
                    ansLen = r - l + 1;
                }

                // Decrease frequency of the leftmost character
                smp[s[l] - 'a']--;

                // Check if the leftmost character frequency is now below required
                if (pmp[s[l] - 'a'] > 0 && smp[s[l] - 'a'] < pmp[s[l] - 'a'])
                {
                    curLen--;
                }

                // Move left pointer
                l++;
            }

            // Move right pointer
            r++;
        }

        return ans;
    }

};
