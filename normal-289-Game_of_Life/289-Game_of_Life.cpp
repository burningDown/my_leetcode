class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int h = board.size();
        if(h == 0)
            return;
        const int w = board[0].size();
        if(w == 0)
            return;
        
        int sum;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                sum = 0;
                for(int ii=i-1;ii<=i+1;ii++)
                {
                    for(int jj=j-1;jj<=j+1;jj++)
                    {
                        if(ii >=0 && ii < h && jj >= 0 && jj < w)
                        {
                            if(board[ii][jj] < 0)
                            {
                                if(board[ii][jj] == -2)
                                    sum++;
                            }
                            else
                                sum += board[ii][jj];
                        }
                    }
                }
                sum -= board[i][j];
                
                if(sum < 2 || sum > 3)
                {
                    if(board[i][j] == 1)
                        board[i][j] = -2;
                }
                else if(sum == 3)
                {
                    if(board[i][j] == 0)
                        board[i][j] = -1;
                }
            }
        }

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(board[i][j] == -1)
                    board[i][j] = 1;
                else if(board[i][j] == -2)
                    board[i][j] = 0;
            }
        }
    }
};