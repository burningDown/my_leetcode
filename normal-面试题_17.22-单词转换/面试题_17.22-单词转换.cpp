class Solution {
private:
    vector<string> wordListPlus;
    list<int> resultIdx;
    vector<vector<int>> path;
    vector<bool> visited;
    int l;
    int endIdx;

    bool dfs(int idx)
    {
        if(idx == endIdx)
        {
            resultIdx.push_front(idx);
            return true;
        }
        
        for(int next=0;next<l;next++)
        {
            if(path[idx][next] == 1 && !visited[next])
            {
                visited[next] = true;
                if(dfs(next))
                {
                    resultIdx.push_front(idx);
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int count;

        vector<string> result;
        
        int i;
        for(i=0;i<wordList.size();i++)
        {
            if(wordList[i] == endWord)
            {
                endIdx = i;
                break;
            }
        }
        if(i == wordList.size())
            return result;

        wordListPlus = wordList;
        wordListPlus.push_back(beginWord);
        l = wordListPlus.size();
        path.resize(l, vector(l, INT_MAX));
        visited.resize(l, false);

        for(int i=0;i<l;i++)
        {
            path[i][i] = 0;
            for(int j=0;j<i;j++)
            {
                if(wordListPlus[i].size() == wordListPlus[j].size())
                {
                    count = 0;
                    for(int k=0;k<wordListPlus[i].size();k++)
                    {
                        if(wordListPlus[i][k] != wordListPlus[j][k])
                            count++;
                    }
                    path[i][j] = path[j][i] = count;
                }
            }
        }

        if(dfs(l-1))
        {
            for(list<int>::iterator it = resultIdx.begin(); it != resultIdx.end(); it++)
            {
                result.push_back(wordListPlus[*it]);
            }
        }

        return result;
    }
};