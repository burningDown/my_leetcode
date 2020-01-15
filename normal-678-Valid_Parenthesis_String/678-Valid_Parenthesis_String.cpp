class Solution {
private:
    pair<int,int> mStack[101*101+10];
    bool visited[105][105];
    int ms;
public:
    Solution(): ms(0){
        memset(visited, 0, 105*105);
    }
    bool checkValidString(string s) {
        int n = s.size();
        mStack[ms++] = pair<int, int>(0, 0);
        while(ms>0)
        {
            const auto p = mStack[--ms];
            
            if(p.first==0 && p.second==n)
                return true;
            else if(p.second<n)
            {
                const auto &c = s[p.second];
                switch(c)
                {
                case '(':
                    if(!visited[p.first+1][p.second+1])
                    {
                        visited[p.first+1][p.second+1] = true;
                        mStack[ms++] = pair<int, int>(p.first+1, p.second+1);
                    }
                    break;
                case ')':
                    if(p.first-1>=0 && !visited[p.first-1][p.second+1])
                    {
                        visited[p.first-1][p.second+1] = true;
                        mStack[ms++] = pair<int, int>(p.first-1, p.second+1);
                    }
                    break;
                case '*':
                    if(!visited[p.first+1][p.second+1])
                    {
                        visited[p.first+1][p.second+1] = true;
                        mStack[ms++] = pair<int, int>(p.first+1, p.second+1);
                    }
                    if(!visited[p.first][p.second+1])
                    {
                        visited[p.first][p.second+1] = true;
                        mStack[ms++] = pair<int, int>(p.first, p.second+1);
                    }
                    if(p.first-1>=0 && !visited[p.first-1][p.second+1])
                    {
                        visited[p.first-1][p.second+1] = true;
                        mStack[ms++] = pair<int, int>(p.first-1, p.second+1);
                    }
                    break;
                }
            }
        }
        return false;
    }
};