class Solution {
private:
    int backtrack(vector<string> &dictionary, string &sentence, vector<int> &dp, int start)
    {
        if(start >= sentence.size())
            return 0;
        if(dp[start] >= 0)
            return dp[start];

        int minNum = INT_MAX;
        const int l = dictionary.size();
        for(string &s : dictionary)
        {
            if(s == sentence.substr(start, s.size()))
            {
                int x = backtrack(dictionary, sentence, dp, start + s.size());
                if(x < minNum)
                    minNum = x;
            }
        }
        int x = backtrack(dictionary, sentence, dp, start + 1) + 1;
        if(x < minNum)
            minNum = x;
        dp[start] = minNum;
        return minNum;
    }
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.size(), -1);
        return backtrack(dictionary, sentence, dp, 0);
    }
};