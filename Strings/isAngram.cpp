/*
    Q: valid angram

    "An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
     typically using all the original letters exactly once."

    link : https://leetcode.com/problems/valid-anagram/description/
*/



class Solution {
public:
    // brute force - find all combination of s and match with t


    // optimised code O(s+t+26)
    bool isAnagram(string s, string t) {
        vector<int> sArr(26,0),tArr(26,0);

        for(auto c:s){
            sArr[c-'a'] += 1;
        }

        for(auto c:t){
            tArr[c-'a'] += 1;
        }

        for(int i=0 ; i<26 ; i++){
            if(sArr[i] != tArr[i]){
                return false;
            }
        }
        return true;
    }
};