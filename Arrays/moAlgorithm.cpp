/*
    Q : Interesting Queries (Mo's Algorithm)

	"MO’s algorithm is to pre-process all queries so that result of one query can be used in next query"

    link : https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
*/

class Solution {
public:
    //brute force - O(nm)
		vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries, int k){
	    vector<int> ans;
	    for(int i=0 ; i<Queries.size() ; i++){
	        
	        int l=Queries[i][0],r=Queries[i][1];
	        unordered_map<int,int> mp;
	        
	        while(l <= r){
	            if(mp.find(nums[l-1]) == mp.end()){//new element add
	                mp[nums[l-1]]=1;
	            }else{      //previous element increment
	                mp[nums[l-1]] += 1;
	            }
	            l++;
	        }
	        int temp=0;
	        for (auto& it : mp) {
                if (it.second >= k) {
                    temp++; // Increment temp for elements with frequency k
                }
            }
	        ans.push_back(temp);//add the ans on vector
	    }
	    
	    return ans;
	}

	//using Mo's algorithm


};
