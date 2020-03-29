class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ri, rj;
        int count = 0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j] == 'R')
                {
                    ri = i;
                    rj = j;
                    goto END_LOOP;
                }
            }
        }
        END_LOOP:
        for(int i=ri-1;i>=0;i--)
        {
            if(board[i][rj] == 'p')
            {
                count++;
                break;
            }
            else if(board[i][rj] == 'B')
                break;
        }
        for(int i=ri+1;i<8;i++)
        {
            if(board[i][rj] == 'p')
            {
                count++;
                break;
            }
            else if(board[i][rj] == 'B')
                break;
        }
        
        for(int j=rj-1;j>=0;j--)
        {
            if(board[ri][j] == 'p')
            {
                count++;
                break;
            }
            else if(board[ri][j] == 'B')
                break;
        }
        for(int j=rj+1;j<8;j++)
        {
            if(board[ri][j] == 'p')
            {
                count++;
                break;
            }
            else if(board[ri][j] == 'B')
                break;
        }
        return count;
    }
};