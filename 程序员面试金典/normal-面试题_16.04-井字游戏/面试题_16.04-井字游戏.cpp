class Solution {
public:
    string tictactoe(vector<string>& board) {
        int dp[2][110][110][4] = { 0 };    // 0:X, 1:O; 0:down, 1:right_down, 2:right, 3:left_down
        const int l = board.size();
        bool isPending = false;
        for(int i=l-1;i>=0;i--)
        {
            for(int j=l-1;j>=0;j--)
            {
                if(board[i][j] == 'X')
                {
                    dp[0][i][j][0] = dp[0][i+1][j][0] + 1;
                    dp[0][i][j][1] = dp[0][i+1][j+1][1] + 1;
                    dp[0][i][j][2] = dp[0][i][j+1][2] + 1;
                    if(j > 0)
                        dp[0][i][j][3] = dp[0][i+1][j-1][3] + 1;
                    else
                        dp[0][i][j][3] = 1;

                    if(dp[0][i][j][0] >= l || dp[0][i][j][1] >= l || dp[0][i][j][2] >= l || dp[0][i][j][3] >= l)
                        return "X";
                }
                else if(board[i][j] == 'O')
                {
                    dp[1][i][j][0] = dp[1][i+1][j][0] + 1;
                    dp[1][i][j][1] = dp[1][i+1][j+1][1] + 1;
                    dp[1][i][j][2] = dp[1][i][j+1][2] + 1;
                    if(j > 0)
                        dp[1][i][j][3] = dp[1][i+1][j-1][3] + 1;
                    else
                        dp[1][i][j][3] = 1;

                    if(dp[1][i][j][0] >= l || dp[1][i][j][1] >= l || dp[1][i][j][2] >= l || dp[1][i][j][3] >= l)
                        return "O";
                }
                else
                    isPending = true;
            }
        }
        return isPending ? "Pending" : "Draw";
    }
};