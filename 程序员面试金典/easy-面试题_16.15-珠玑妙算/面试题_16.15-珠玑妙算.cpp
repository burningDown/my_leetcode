class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> result(2, 0);
        int sMap[26] = { 0 };
        for(int i=0;i<4;i++)
            sMap[solution[i] - 'A']++;
        
        for(int i=0;i<4;i++)
        {
            if(solution[i] == guess[i])
            {
                sMap[solution[i] - 'A']--;
                result[0]++;
            }
        }
        if(result[0] < 4)
        {
            for(int i=0;i<4;i++)
            {
                if(solution[i] != guess[i] && sMap[guess[i] - 'A'] > 0)
                {
                    sMap[guess[i] - 'A']--;
                    result[1]++;
                }
            }
        }
        return result;
    }
};