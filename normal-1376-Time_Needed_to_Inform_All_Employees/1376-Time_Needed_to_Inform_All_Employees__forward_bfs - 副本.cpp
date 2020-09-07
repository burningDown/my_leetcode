class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1)
            return informTime[0];
        
        vector<list<int>> reversedMap(n);
        queue<pair<int, int>> stateQueue;
        pair<int, int> state;
        int maxTime = -1;

        for(int i=0;i<n;i++)
            if(manager[i] != -1)
                reversedMap[manager[i]].push_back(i);

        stateQueue.push({headID, informTime[headID]});
        while(!stateQueue.empty())
        {
            state = stateQueue.front();
            stateQueue.pop();
            
            for(auto it=reversedMap[state.first].begin();it!=reversedMap[state.first].end();it++)
            {
                maxTime = max(maxTime, informTime[*it] + state.second);
                stateQueue.push({*it, informTime[*it] + state.second});
            }
        }
        return maxTime;
    }
};