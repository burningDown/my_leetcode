class Solution {
private:
    bool backtrack(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int i, int j, int idx)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] || board[i][j] != word[idx])
            return false;

        if(idx == word.size() - 1)
            return true;
        
        visited[i][j] = true;

        bool flag = backtrack(board, word, visited, i+1, j, idx+1) || backtrack(board, word, visited, i-1, j, idx+1) ||
            backtrack(board, word, visited, i, j+1, idx+1) || backtrack(board, word, visited, i, j-1, idx+1);

        visited[i][j] = false;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(backtrack(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};