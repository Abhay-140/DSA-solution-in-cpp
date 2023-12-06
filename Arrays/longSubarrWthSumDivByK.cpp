/*
    Q : longest subarray with sum divisible by K

    link : https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1/
*/


class Solution{
public:	
    // brute force (n^2)
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int cnt=0,max=0;
	    for(int i=0 ; i<n ; i++){
	        int temp=0;
	        for(int j=i ; j<n ; j++){
	            temp += arr[j];
	            if(temp % k == 0 and max < j-i+1){
	                max=j-i+1;
	            }
	        }
	    }
	    return max;
	}

    //optimised code
    int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> mp={ {0,-1} };
	    int temp=0,mx=0;
	    
	    for(int i=0 ; i<n ; i++){
	        temp += arr[i];
	        int rem=temp%k; //making remainder
            
            if(rem<0){
                rem += k; 
            }	        
            
            if(mp.find(rem) == mp.end()){//if rem didn't find
                mp[rem]=i;//adding key value pair in mp
            }else{
                mx=max(mx,i-mp[rem]);//dividing i2-i1
            }
	    }
	    
	    return mx;
	    
	}
	
};