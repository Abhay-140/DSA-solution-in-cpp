/*
    Q: Word Search

    link: https://leetcode.com/problems/word-search/description/
*/

class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));


        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                visited[i][j] = true;
                if(board[i][j] == word[0] && check(0,i,j,board,visited, word)){
                    return true;
                }
                visited[i][j] = false;
            }
        }

        return false;
    }

    bool check(int idx, int i, int j, vector<vector<char>>& board,  vector<vector<bool>>& visited, string word){
        
        if(idx == word.size()-1){
            return true;
        }

        if(j+1<board[0].size() && !visited[i][j+1] && board[i][j+1] == word[idx+1]){
            visited[i][j+1] = true;
            bool ans = check(idx+1, i, j+1, board, visited, word);
            if(ans) return true;
            visited[i][j+1] = false;
        }
        
        if(j-1>-1 && !visited[i][j-1] && board[i][j-1] == word[idx+1]){
            visited[i][j-1] = true;
            bool ans = check(idx+1, i, j-1, board, visited, word);
            if(ans) return true;
            visited[i][j-1] = false;
        }

        if(i+1<board.size() && !visited[i+1][j] && board[i+1][j] == word[idx+1]){
            visited[i+1][j] = true;
            bool ans = check(idx+1, i+1, j, board, visited, word);
            if(ans) return true;
            visited[i+1][j] = false;
        }

        if(i-1>-1 && !visited[i-1][j] && board[i-1][j] == word[idx+1]){
            visited[i-1][j] = true;
            bool ans = check(idx+1, i-1, j, board, visited, word);
            if(ans) return true;
            visited[i-1][j] = false;
        }

        return false;
    }
};