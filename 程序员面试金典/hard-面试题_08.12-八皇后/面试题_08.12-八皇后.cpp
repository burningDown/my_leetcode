class Solution {
private:
    void backtrack(vector<vector<string>> &result, vector<string> &chessBoard, int line)
    {
        const int l = chessBoard.size();
        int i, j;

        for(int i=0;i<l;i++)
        {
            chessBoard[line-1][i] = 'Q';
            for(j=line;j<l;j++)
            {
                if(chessBoard[j][i] == 'Q' || i+j-line+1 < l && chessBoard[j][i+j-line+1] == 'Q' || i-j+line-1 >= 0 && chessBoard[j][i-j+line-1] == 'Q')
                {
                    break;
                }
            }
            if(j >= l)
            {
                if(line == 1)
                {
                    result.push_back(chessBoard);
                }
                else
                {
                    backtrack(result, chessBoard, line-1);
                }
            }
            chessBoard[line-1][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> chessBoard(n, string(n, '.'));
        backtrack(result, chessBoard, n);
        return result;
    }
};