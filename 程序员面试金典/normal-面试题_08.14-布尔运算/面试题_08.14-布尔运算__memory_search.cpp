class Solution {
private:
    int dp[50][50][2];
    int countSubEval(string &s, int result, int start, int end)
    {
        if(start == end)
        {
            return int(s[start] - '0' == result);
        }
        
        if(dp[start][end][result] >= 0)
            return dp[start][end][result];

        int count = 0;

        for(int i=start+1;i<end;i+=2)
        {
            switch(s[i])
            {
            case '&':
                if(result == 1)
                {
                    int l1 = countSubEval(s, 1, start, i-1);
                    int r1 = countSubEval(s, 1, i+1, end);
                    count += l1 * r1;
                }
                else
                {
                    int l1 = countSubEval(s, 1, start, i-1);
                    int l0 = countSubEval(s, 0, start, i-1);
                    int r1 = countSubEval(s, 1, i+1, end);
                    int r0 = countSubEval(s, 0, i+1, end);
                    count += l1 * r0 + l0 * r1 + l0 * r0;
                }
                break;
            case '|':
                if(result == 1)
                {
                    int l1 = countSubEval(s, 1, start, i-1);
                    int l0 = countSubEval(s, 0, start, i-1);
                    int r1 = countSubEval(s, 1, i+1, end);
                    int r0 = countSubEval(s, 0, i+1, end);
                    count += l1 * r1 + l0 * r1 + l1 * r0;
                }
                else
                {
                    int l0 = countSubEval(s, 0, start, i-1);
                    int r0 = countSubEval(s, 0, i+1, end);
                    count += l0 * r0;
                }
                break;
            case '^':
                if(result == 1)
                {
                    int l1 = countSubEval(s, 1, start, i-1);
                    int l0 = countSubEval(s, 0, start, i-1);
                    int r1 = countSubEval(s, 1, i+1, end);
                    int r0 = countSubEval(s, 0, i+1, end);
                    count += l1 * r0 + l0 * r1;
                }
                else
                {
                    int l1 = countSubEval(s, 1, start, i-1);
                    int l0 = countSubEval(s, 0, start, i-1);
                    int r1 = countSubEval(s, 1, i+1, end);
                    int r0 = countSubEval(s, 0, i+1, end);
                    count += l0 * r0 + l1 * r1;
                }
                break;
            }
        }
        dp[start][end][result] = count;
        return count;
    }
public:
    int countEval(string s, int result) {
        const int l = s.size();

        memset(dp, -1, 50*50*2*sizeof(int));

        return countSubEval(s, result, 0, l-1);
    }
};