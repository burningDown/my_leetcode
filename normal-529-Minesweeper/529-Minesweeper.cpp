class Solution {
private:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        const int h = board.size();
        const int w = board[0].size();
        int count = 0;

        if(board[i][j] != 'E' && board[i][j] != 'M')
            return;

        if(board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return;
        }

        for(int ii = i-1;ii<=i+1;ii++)
        {
            if(ii < 0 || ii >= h)
                continue;
            for(int jj = j-1;jj<=j+1;jj++)
            {
                if(jj < 0 || jj >= w || (ii == i && jj == j))
                    continue;
                if(board[ii][jj] == 'M')
                    count++;
            }
        }

        if(count > 0)
        {
            board[i][j] = count + '0';
        }
        else
        {
            board[i][j] = 'B';
            for(int ii = i-1;ii<=i+1;ii++)
            {
                if(ii < 0 || ii >= h)
                    continue;
                for(int jj = j-1;jj<=j+1;jj++)
                {
                    if(jj < 0 || jj >= w || (ii == i && jj == j))
                        continue;
                    dfs(board, ii, jj);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click[0], click[1]);
        return board;
    }
};