class Solution {
private:
    int pStack[105];
    int s;
    int belonging[105];
public:
    Solution(): pStack({0}), s(0), belonging({0}){}
    bool isBipartite(vector<vector<int>>& graph) {
        int l = graph.size();
        int idx;
        for(int i=0;i<l;i++)
        {
            if(belonging[i] == 0)
            {
                belonging[i] = 1;
                pStack[s++] = i;
            }
            while(s>0)
            {
                idx = pStack[--s];
                for(int j : graph[idx])
                {
                    if(belonging[j] == 0)
                    {
                        belonging[j] = belonging[idx]==1?2:1;
                        pStack[s++] = j;
                    }
                    else if(belonging[j] == belonging[idx])
                        return false;
                }
            }
        }
        return true;
    }
};