/*
    Q: 3sum

    link: https://leetcode.com/problems/3sum/description
*/



class Solution {
public:

// brute force

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans; // using set for not containing duplicate vector
        sort(nums.begin(),nums.end());

        
        for(int i=0;i<nums.size()-2 ; i++)
            for(int j=i+1 ; j<nums.size()-1 ; j++)
                for(int k=j+1 ; k<nums.size() ; k++)
                    if(nums[i] + nums[j] + nums[k] == 0)
                        ans.insert({nums[i],nums[j],nums[k]});

        vector<vector<int>> vec(ans.begin(),ans.end());
        return vec;
    }

// optimised code 

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // sort the array
        
        set<vector<int>> set; // for containing unique vector
        int i=0;
        while(i < nums.size()-2){
            int l=i+1,r=nums.size()-1;

            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    set.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }
                else{
                    r--;
                }
            }

            while(i < nums.size()-1 and nums[i] == nums[i+1]) // update the i (nothing to do   because we using set)
                i++;
            i++;
        }

        vector<vector<int>> ans(set.begin(),set.end()); // set to vector
        return ans;
    }


};