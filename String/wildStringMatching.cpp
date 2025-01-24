/*
    Q: Wild string matching

    link: https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1
*/

class Solution
{
public:

    // Recursion method - O(3^n)
    bool wsm(int i, int j, string &wild, string &pattern)
    {
        // Base cases
        if (i < 0 && j < 0) // If both wild and pattern are exhausted
            return true;
        if (i < 0 && j >= 0) // If pattern is not exhausted but wild is exhausted
            return false;
        if (i >= 0 && j < 0)
        { // If wild is not exhausted but pattern is exhausted
            // Check if remaining characters in wild are all '*'
            for (; i >= 0; i--)
            {
                if (wild[i] != '*')
                    return false;
            }
            return true;
        }

        // Main recursive logic
        if (wild[i] == pattern[j] || wild[i] == '?') // If characters match or wild character is '?'
            return wsm(i - 1, j - 1, wild, pattern); // Move to the previous characters in wild and pattern

        if (wild[i] == '*')                                                      // If wild character is '*'
            return wsm(i, j - 1, wild, pattern) || wsm(i - 1, j, wild, pattern); // Match zero or more characters

        // If none of the above conditions are met, return false
    }

    // Function to check if wildcard string matches pattern
    bool match(string wild, string pattern)
    {
        return wsm(wild.length() - 1, pattern.length() - 1, wild, pattern); // Start recursion from the end of wild and pattern
    }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // Memoisation method (top bottom approach) - SC -> O(m*n)
    int f(int i, int j, string &wild, string &pattern, vector<vector<int>> &dp)
    {
        // Base cases
        if (i < 0 && j < 0) // If both wild and pattern are exhausted
            return 1;
        else if (i < 0 && j >= 0) // If pattern is not exhausted but wild is exhausted
            return 0;
        else if (i >= 0 && j < 0)
        { // If wild is not exhausted but pattern is exhausted
            // Check if remaining characters in wild are all '*'
            for (int k = 0; k <= i; k++)
            {
                if (wild[k] != '*')
                    return 0;
            }
            return 1;
        }

        // If result is already computed, return it from dp table
        if (dp[i][j] != -1)
            return dp[i][j];

        // Main recursive logic
        if (wild[i] == pattern[j] || wild[i] == '?')              // If characters match or wild character is '?'
            return dp[i][j] = f(i - 1, j - 1, wild, pattern, dp); // Move to the previous characters in wild and pattern

        else if (wild[i] == '*')                                                                // If wild character is '*'
            return dp[i][j] = f(i - 1, j, wild, pattern, dp) || f(i, j - 1, wild, pattern, dp); // Match zero or more characters

        // If none of the above conditions are met, return false
        return dp[i][j] == 0;
    }

    
    bool match(string wild, string pattern)
    {
        vector<vector<int>> dp(wild.size(), vector<int>(pattern.size(), -1)); // Initialize dp table with -1

        return f(wild.size() - 1, pattern.size() - 1, wild, pattern, dp); // Start recursion from the end of wild and pattern
    }

};