/*
    Q: Group angrams

    link : https://leetcode.com/problems/group-anagrams/
*/



class Solution {
public:
    

    //optimised code - O(2n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> strlist;
        vector< vector<string>> ans;

        //insert all elemnt in map
        for(auto a:strs){
            string temp=a;
            sort( a.begin(),a.end() );
            strlist[a].push_back(temp);
        }

        //insert all matched angrams in ans
        auto it=strlist.begin();
        for(; it != strlist.end() ; it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};