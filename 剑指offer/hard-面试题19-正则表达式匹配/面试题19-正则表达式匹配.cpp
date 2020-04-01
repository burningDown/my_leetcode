class Solution {
public:
    bool isMatch(string s, string p) {
        s.push_back('0');
        p.push_back('0');
        stack<vector<int>> stateStack;
        vector<vector<bool>> visited(s.size(), vector<bool>(p.size(), false));
        
        stateStack.push({0, 0});
        while(!stateStack.empty())
        {
            vector<int> state = stateStack.top();
            stateStack.pop();
            
            if(state[0] >= s.size() && state[1] >= p.size())
                return true;
            else if(state[0] >= s.size() || state[1] >= p.size())
                continue;

            if(visited[state[0]][state[1]])
                continue;
            else
                visited[state[0]][state[1]] = true;
            if(state[1] < p.size()-1 && p[state[1]+1] == '*')
            {
                if(s[state[0]] == p[state[1]] || p[state[1]] == '.')
                {
                    stateStack.push({state[0], state[1]+2});
                    stateStack.push({state[0]+1, state[1]});
                    stateStack.push({state[0]+1, state[1]+2});
                }
                else
                    stateStack.push({state[0], state[1]+2});

            }
            else
            {
                if(s[state[0]] == p[state[1]] || p[state[1]] == '.')
                    stateStack.push({state[0]+1, state[1]+1});
            }
        }
        return false;
    }
};