/*
    Q: Rotate Image

    link: https://leetcode.com/problems/rotate-image/description/
*/

class Solution {
public:
    //  Brute Force - O(n^2) space O(n^2)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        int temp = n-1;

        for(int i = 0; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                ans[j][temp]=matrix[i][j];
            }
            temp--;
        }

        for(int i = 0; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }

    //  Optimzed Code - O(n^1) space O(1)
     void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        //transpore
        for(int i=0 ; i<m ; i++){
            for(int j=i ; j<m ; j++){
                if(i != j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        // reverse each row
        for(int i=0 ; i<m ; i++){
            int l=0,r=m-1;
            while(l < r){
                int temp = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = temp;
                l++;
                r--;
            }
        }
    }
};