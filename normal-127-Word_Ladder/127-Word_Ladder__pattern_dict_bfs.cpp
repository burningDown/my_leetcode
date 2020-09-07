class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int>> wordMap;
        const int l = wordList.size();
        const int wl = beginWord.size();
        int endWordIdx = -1;
        string pattern;
        vector<bool> visited(l, false);

        for(int i=0;i<l;i++)
        {
            if(endWordIdx < 0 && endWord == wordList[i])
                endWordIdx = i;
            
            pattern = wordList[i];
            for(int j=0;j<wl;j++)
            {
                char c = pattern[j];
                pattern[j] = '*';
                wordMap[pattern].push_back(i);
                pattern[j] = c;
            }
        }

        queue<pair<int, int>> stateQueue;
        pattern = beginWord;
        for(int i=0;i<wl;i++)
        {
            char c = pattern[i];
            pattern[i] = '*';
            if(wordMap.find(pattern) != wordMap.end())
            {
                for(auto it=wordMap[pattern].begin();it!=wordMap[pattern].end();it++)
                {
                    stateQueue.push({*it, 2});
                }
            }
            pattern[i] = c;
        }
        while(!stateQueue.empty())
        {
            auto state = stateQueue.front();
            stateQueue.pop();
            int idx = state.first;
            int length = state.second;

            visited[idx] = true;

            if(idx == endWordIdx)
                return length;
            
            pattern = wordList[idx];
            for(int i=0;i<wl;i++)
            {
                char c = pattern[i];
                pattern[i] = '*';
                if(wordMap.find(pattern) != wordMap.end())
                {
                    for(auto it=wordMap[pattern].begin();it!=wordMap[pattern].end();it++)
                    {
                        if(!visited[*it])
                            stateQueue.push({*it, length+1});
                    }
                }
                pattern[i] = c;
            }
        }
        return 0;
    }
};