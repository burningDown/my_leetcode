class Solution {
public:
    vector<int> partitionLabels(string S) {
        int letterCounting[26] = { 0 };
        bool visited[26] = { 0 };
        vector<int> result;
        const int l = S.size();
        int count = 0, flag = -1;
        char c;
        
        for(char c:S)
            letterCounting[c-'a']++;

        for(int i=0;i<l;i++)
        {
            c = S[i];
            if(!visited[c-'a'])
            {
                visited[c-'a'] = true;
                count++;
            }
            letterCounting[c-'a']--;
            if(letterCounting[c-'a'] == 0)
            {
                count--;
                if(count == 0)
                {
                    result.push_back(i-flag);
                    flag = i;
                }
            }
        }
        return result;
    }
};