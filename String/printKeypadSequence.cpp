/*
    Q:Convert a sentence into its equivalent mobile numeric keypad sequence

    link : https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
*/

class Solution
{
    //using vector of string O(S)
public:
    string printSequence(string S)
    {
        vector<string> numbers = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555",
                                  "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
        string ans = "";
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == 32) // for space ansi code is '32'
                ans += "0";
            else
                ans += numbers[S[i] - 'A'];
        }
        return ans;
    }

    //optimised code use swich case space complexity O(0)

    
};