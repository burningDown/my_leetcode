bool cmp(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
{
    return p1.first < p2.first;
}

class Solution {
private:
    int path(vector<vector<int>> &forest, int i1, int j1, int i2, int j2)
    {
        if(forest[i1][j1] == 0 || forest[i2][j2] == 0)
            return -1;
        if(i1 == i2 && j1 == j2)
            return 0;  

        queue<pair<int, int>> stateQueue;
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        int res = -1;

        const int h = forest.size();
        const int w = forest[0].size();
        
        stateQueue.push({i1, j1});
        visited[i1][j1] = 1;
        stateQueue.push({i2, j2});
        visited[i2][j2] = -1;

        bool flag = true;

        while(flag && !stateQueue.empty())
        {
            auto state = stateQueue.front();
            stateQueue.pop();

            for(int i=max(0, state.first-1);flag && i<min(h, state.first+2);i++)
            {
                for(int j=max(0, state.second-1);flag && j<min(w, state.second+2);j++)
                {
                    if(abs(i - state.first) + abs(j - state.second) != 1)
                        continue;
                    
                    if(visited[i][j] == 0)
                    {
                        if(forest[i][j] > 0)
                        {
                            stateQueue.push({i, j});
                            visited[i][j] = visited[state.first][state.second] + (visited[state.first][state.second] > 0 ? 1 : -1);
                        }
                    }
                    else if((visited[i][j] ^ visited[state.first][state.second]) < 0)
                    {
                        res = abs(visited[i][j]) + abs(visited[state.first][state.second]) - 1;
                        flag = false;
                        break;
                    }
                }
            }
        }
        return res;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const int h = forest.size();
        const int w = forest[0].size();
        vector<pair<int, pair<int, int>>> forestDict;
        int res = 0;
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(forest[i][j] > 1)
                    forestDict.push_back({forest[i][j], {i, j}});
            }
        }

        sort(forestDict.begin(), forestDict.end(), cmp);

        const int dl = forestDict.size();

        int p;
        if((p = path(forest, 0, 0, forestDict[0].second.first, forestDict[0].second.second)) < 0)
            return -1;
        res += p;

        for(int i=1;i<dl;i++)
        {
            if((p = path(forest, forestDict[i-1].second.first, forestDict[i-1].second.second, forestDict[i].second.first, forestDict[i].second.second)) < 0)
                return -1;
            res += p;
        }
        return res;
    }
};