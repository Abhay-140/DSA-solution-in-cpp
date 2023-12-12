/*
    Q: Longest repeating charcter replacement

    link : https://leetcode.com/problems/longest-repeating-character-replacement/
*/


class Solution {
public:

    //brute force - find out all the substrings and replace k th element with max frequency character  O(n^3)


    //optimised code - O(n)
    int characterReplacement(string s, int k) {
        int maxLen=0,maxFreq=0,l=0,r=0;
        unordered_map<char,int> freq;

        for(  ; r<s.length() ; r++ ){
            freq[s[r]]++;
            maxFreq=max(maxFreq,freq[s[r]]);

            // if length - maxfreq =< k is not then shrink the subarray
            if(r+1-l - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            maxLen=max(maxLen,r+1-l);
        }

        return maxLen;
    }
};
