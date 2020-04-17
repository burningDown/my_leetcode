class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();
        vector<vector<int>> result(h, vector<int>(w, -1));
        queue<vector<int>> stateQueue;

        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(matrix[i][j] == 1)
                {
                    if(i>0 && matrix[i-1][j] == 0 || i<h-1 && matrix[i+1][j] == 0 || j>0 && matrix[i][j-1] == 0 || j<w-1 && matrix[i][j+1] == 0)
                        stateQueue.push({i, j, 1});
                }
                else
                {
                    result[i][j] = 0;
                }
            }
        }

        while(!stateQueue.empty())
        {
            vector<int> state = stateQueue.front();
            stateQueue.pop();

            if(result[state[0]][state[1]] >= 0)
                continue;

            result[state[0]][state[1]] = state[2];

            if(state[0]>0 && matrix[state[0]-1][state[1]] == 1 && result[state[0]-1][state[1]] == -1)
                stateQueue.push({state[0]-1, state[1], state[2]+1});

            if(state[0]<h-1 && matrix[state[0]+1][state[1]] == 1 && result[state[0]+1][state[1]] == -1)
                stateQueue.push({state[0]+1, state[1], state[2]+1});
            
            if(state[1]>0 && matrix[state[0]][state[1]-1] == 1 && result[state[0]][state[1]-1] == -1)
                stateQueue.push({state[0], state[1]-1, state[2]+1});
                
            if(state[1]<w-1 && matrix[state[0]][state[1]+1] == 1 && result[state[0]][state[1]+1] == -1)
                stateQueue.push({state[0], state[1]+1, state[2]+1});
        }
        return result;
    }
};