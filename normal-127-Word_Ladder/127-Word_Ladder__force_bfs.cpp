class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);

        const int l = wordList.size();
        const int wl = beginWord.size();
        vector<vector<int>> graph(l, vector<int>());
        vector<bool> visited(l, false);
        int endWordIdx = -1;
        int diff;
        
        for(int i=0;i<l;i++)
        {
            if(endWordIdx < 0 && wordList[i] == endWord)
                endWordIdx = i;
            for(int j=0;j<l;j++)
            {
                diff = 0;
                for(int k=0;k<wl;k++)
                {
                    if(wordList[i][k] != wordList[j][k])
                        diff++;
                }
                if(diff == 1)
                    graph[i].push_back(j);
            }
        }

        if(endWordIdx < 0)
            return 0;

        queue<pair<int, int>> stateQueue;

        stateQueue.push({l-1, 1});
        while(!stateQueue.empty())
        {
            pair<int, int> state = stateQueue.front();
            stateQueue.pop();
            int idx = state.first;
            int length = state.second;
            visited[idx] = true;

            if(idx == endWordIdx)
                return length;
            
            for(int i=0;i<graph[idx].size();i++)
            {
                if(!visited[graph[idx][i]])
                    stateQueue.push({graph[idx][i], length+1});
            }
        }
        return 0;
    }
};