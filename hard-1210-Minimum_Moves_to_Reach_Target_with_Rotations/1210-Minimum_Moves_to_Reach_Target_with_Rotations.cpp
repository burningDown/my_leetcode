class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int i, j, n, state, step, minSteps = -1;
        bool visited[105][105][2];
        queue<vector<int>> stateQueue;
        vector<int> it;

        memset(visited, 0, 105*105*2);
        n = grid.size();

        stateQueue.push({0,0,0,0});    // i, j, state, step
        while(!stateQueue.empty())
        {
            it = stateQueue.front();
            stateQueue.pop();
            i = it[0];
            j = it[1];
            state = it[2];
            step = it[3];
            
            if(visited[i][j][state])
                continue;
            visited[i][j][state] = true;
            if(i == n-1 && j == n-2 && state == 0)    // 到达终点
            {
            	minSteps = step;
            	break;
            }
            else if(state == 0)     // state为0表示蛇横着
            {
                if(i < n-1 && j < n-1 && grid[i+1][j] == 0 && grid[i+1][j+1] == 0)
                {
                    stateQueue.push({i+1, j, 0, step+1});//dfs(grid, 0, i+1, j, step+1);
                    stateQueue.push({i, j, 1, step+1});//dfs(grid, 1, i, j, step+1);
                }
                if(j < n-2 && grid[i][j+2] == 0)
                {
                    stateQueue.push({i, j+1, 0, step+1});//dfs(grid, 0, i, j+1, step+1);
                }
            }
            else    //state为1表示蛇竖着
            {
                if(j < n-1 && i < n-1 && grid[i][j+1] == 0 && grid[i+1][j+1] == 0)
                {
                    stateQueue.push({i, j+1, 1, step+1});//dfs(grid, 1, i, j+1, step+1);
                    stateQueue.push({i, j, 0, step+1});//dfs(grid, 0, i, j, step+1);
                }
                if(i < n-2 && grid[i+2][j] == 0)
                {
                    stateQueue.push({i+1, j, 1, step+1});//dfs(grid, 1, i+1, j, step+1);
                }
            }
        }

        return minSteps;
    }
};