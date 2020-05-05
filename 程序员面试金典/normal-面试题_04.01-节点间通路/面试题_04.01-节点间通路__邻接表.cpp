class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(n == 0)
            return false;
        
        vector<list<int>> aList(n);
        vector<bool> visited(n, false);
        stack<int> stateStack;
        int next;

        for(auto p : graph)
            aList[p[0]].push_back(p[1]);
        
        for(auto it=aList[start].begin();it!=aList[start].end();++it)
        {
            stateStack.push(*it);
        }
        while(!stateStack.empty())
        {
            next = stateStack.top();
            stateStack.pop();

            visited[next] = true;

            if(next == target)
                return true;
            
            for(auto it=aList[next].begin();it!=aList[next].end();++it)
            {
                if(!visited[*it])
                    stateStack.push(*it);
            }
        }
        return false;
    }
};