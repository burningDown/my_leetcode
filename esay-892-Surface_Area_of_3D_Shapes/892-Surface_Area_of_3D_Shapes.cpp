class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int l=grid.size();
        int sum=0;
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(j-1>=0)
                {
                    const int &sub = grid[i][j] - grid[i][j-1];
                    if(sub > 0)
                        sum += sub;
                }
                else
                    sum += grid[i][j];
                    
                if(j+1<l)
                {
                    const int &sub = grid[i][j] - grid[i][j+1];
                    if(sub > 0)
                        sum += sub;
                }
                else
                    sum += grid[i][j];
                    
                if(i-1>=0)
                {
                    const int &sub = grid[i][j] - grid[i-1][j];
                    if(sub > 0)
                        sum += sub;
                }
                else
                    sum += grid[i][j];
                    
                if(i+1<l)
                {
                    const int &sub = grid[i][j] - grid[i+1][j];
                    if(sub > 0)
                        sum += sub;
                }
                else
                    sum += grid[i][j];
                
                if(grid[i][j] > 0)
                    sum += 2;
                
            }
        }
        return sum;
    }
};