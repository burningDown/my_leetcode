bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first;
}

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const int h = forest.size();
        const int w = forest[0].size();

        // vector<vector<int>> d(h * w, vector<int>(h * w, INT_MAX));
        int d[3000][3000];
        vector<pair<int, int>> treeList;
        int res = 0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(forest[i][j] != 0)
                {
                    treeList.push_back({forest[i][j], i * w + j});
                }
            }
        }

        sort(treeList.begin(), treeList.end(), cmp);

        for(int i=0;i<h * w;i++)
        {
            for(int j=0;j<h * w;j++)
            {
                if(forest[i/w][i%w] != 0 && forest[j/w][j%w] != 0)
                {
                    if(i == j)
                        d[i][j] = 0;
                    else
                    {
                        int ii = i / w;
                        int ij = i % w;
                        int ji = j / w;
                        int jj = j % w;

                        if(abs(ii - ji) + abs(ij - jj) == 1)
                            d[i][j] = d[j][i] = 1;
                        else d[i][j] = d[j][i] = INT_MAX;
                    }
                }
            }
        }

        for(int k=0;k<h*w;k++)
        {
            if(forest[k/w][k%w] == 0)
                continue;
            for(int i=0;i<h*w;i++)
            {
                if(forest[i/w][i%w] == 0)
                    continue;
                for(int j=0;j<h*w;j++)
                {
                    if(forest[j/w][j%w] == 0)
                        continue;
                    if(d[i][k] != INT_MAX && d[k][j] != INT_MAX)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        const int tl = treeList.size();

        if(d[0][treeList[0].second] == INT_MAX)
            return -1;
        res += d[0][treeList[0].second];
        for(int i=1;i<tl;i++)
        {
            if(d[treeList[i-1].second][treeList[i].second] == INT_MAX)
                return -1;
            res += d[treeList[i-1].second][treeList[i].second];
        }
        return res;
    }
};