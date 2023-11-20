/*
    Q: Maximum sum of Subarray (using kadane algorithm)

   link : https://leetcode.com/problems/maximum-subarray/description/
*/



// optimsed code
int maxSubArray(vector<int>& nums) {// (using kadane algorithm)
        int sum=0,maxsum=INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];

            if(sum>maxsum){
                maxsum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxsum;
    }

int maxSubArray(vector<int>& nums) {
        int sum=0,maxsum=INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
          sum = max(nums[i], sum + nums[i]);
        // Update maxSum if currentSum is greater
        maxsum = max(maxsum, sum);
        }
        return maxsum;
    }

