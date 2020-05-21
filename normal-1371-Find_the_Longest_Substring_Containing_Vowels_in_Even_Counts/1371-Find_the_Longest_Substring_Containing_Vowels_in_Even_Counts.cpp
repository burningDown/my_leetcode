class Solution {
public:
    int findTheLongestSubstring(string s) {
        int evenOrOddMap[32];
        int evenOrOddCount = 0;
        int res = 0;
        const int l = s.size();

        memset(evenOrOddMap, 1, 32 * sizeof(int));
        
        for(int i=0;i<l;i++)
        {
            switch(s[i])
            {
                case 'a':
                    evenOrOddCount ^= 1 << 4;
                    break;
                case 'e':
                    evenOrOddCount ^= 1 << 3;
                    break;
                case 'i':
                    evenOrOddCount ^= 1 << 2;
                    break;
                case 'o':
                    evenOrOddCount ^= 1 << 1;
                    break;
                case 'u':
                    evenOrOddCount ^= 1;
                    break;
            }
            if(evenOrOddCount == 0)
                res = max(res, i + 1);
            else
            {
                evenOrOddMap[evenOrOddCount] = min(evenOrOddMap[evenOrOddCount], i);
                res = max(res, i - evenOrOddMap[evenOrOddCount]);
            }
        }

        return res;
    }
};