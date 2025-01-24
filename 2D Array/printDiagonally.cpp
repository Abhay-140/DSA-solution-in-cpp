/*
    Q: Print Diagonally

    link: https://www.geeksforgeeks.org/problems/print-diagonally4331/1
*/

class Solution{
    public:
    // Brute code O(N*N)
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		vector<int> ans;
		// phase 1
		for(int col=0 ; col<N ; col++){
		    int temp=col;
		   for(int row=0 ; row<=col ; row++){
		       
		       ans.push_back(A[row][temp]);
		       
		       temp--;
		   }
		}
		// phase 2
		for(int row=1; row<N ; row++){
		    int temp=row;
		    for(int col=N-1 ; row<=col ; col--){
		        
		        ans.push_back(A[temp][col]);
		        
		        temp++;
		    }
		}
		
		return ans;
	}

    // Optimized code O(N*N)
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		vector<int> ans;
        int rows = A.size(), cols = A.size();
        
        for (int k=0; k<rows+cols-1; k++){
            for (int i=min(k, cols-1); i>=0 && k-i<rows; i--){
                ans.push_back(A[k-i][i]);
            }
        }
		
		return ans;
	}
}