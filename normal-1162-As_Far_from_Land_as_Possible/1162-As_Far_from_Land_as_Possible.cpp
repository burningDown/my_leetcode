class Solution {
private:
    //pair<int, int> pQueue[12000];
    queue<pair<int,int>> pQueue;
    int distMap[105][105];
public:
    int maxDistance(vector<vector<int>>& grid) {
        int i, j, maxStep = -1;
        const int &l = grid.size();

        for(i=0;i<l;i++)
        {
            for(j=0;j<l;j++)
            {
                if(grid[i][j] == 1)
                {
                    distMap[i][j] = 0;
                    pQueue.push(pair<int,int>(i, j));
                }
                else
                    distMap[i][j] = -1;
            }
        }

        while(!pQueue.empty())
        {
            const pair<int, int> &p = pQueue.front();
            if(p.first-1>=0)
            {
                if(distMap[p.first-1][p.second]<0)
                {
                    distMap[p.first-1][p.second] = distMap[p.first][p.second] + 1;
                    pQueue.push(pair<int,int>(p.first-1, p.second));

                    if(distMap[p.first-1][p.second] > maxStep)
                        maxStep = distMap[p.first-1][p.second];
                }
            }
            if(p.first+1<l)
            {
                if(distMap[p.first+1][p.second]<0)
                {
                    distMap[p.first+1][p.second] = distMap[p.first][p.second] + 1;
                    pQueue.push(pair<int,int>(p.first+1, p.second));

                    if(distMap[p.first+1][p.second] > maxStep)
                        maxStep = distMap[p.first+1][p.second];
                }
            }
            if(p.second-1>=0)
            {
                if(distMap[p.first][p.second-1]<0)
                {
                    distMap[p.first][p.second-1] = distMap[p.first][p.second] + 1;
                    pQueue.push(pair<int,int>(p.first, p.second-1));

                    if(distMap[p.first][p.second-1] > maxStep)
                        maxStep = distMap[p.first][p.second-1];
                }
            }
            if(p.second+1<l)
            {
                if(distMap[p.first][p.second+1]<0)
                {
                    distMap[p.first][p.second+1] = distMap[p.first][p.second] + 1;
                    pQueue.push(pair<int,int>(p.first, p.second+1));

                    if(distMap[p.first][p.second+1] > maxStep)
                        maxStep = distMap[p.first][p.second+1];
                }
            }
            pQueue.pop();
        }
        return maxStep;
    }
};