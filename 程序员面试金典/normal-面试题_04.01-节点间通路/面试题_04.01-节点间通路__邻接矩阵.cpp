class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<bool>> aMap(n, vector<bool>(n, false));
        vector<bool> visited(n, false);
        stack<int> stateStack;
        int next;

        for(auto p : graph)
            aMap[p[0]][p[1]] = true;
        
        for(int i=0;i<n;i++)
        {
            if(aMap[start][i])
                stateStack.push(i);
        }
        while(!stateStack.empty())
        {
            next = stateStack.top();
            stateStack.pop();
            visited[next] = true;

            if(next == target)
                return true;
            
            for(int i=0;i<n;i++)
            {
                if(aMap[next][i] && !visited[i])
                    stateStack.push(i);
            }
        }
        return false;
    }
};