class Solution {
public:
    string replaceSpaces(string S, int length) {
        int count = 0;
        for(int i=0;i<length;i++)
        {
            if(S[i] == ' ')
                count++;
        }
        S.erase(length + 2 * count, S.size() - length - 2 * count);
        for(int i=length-1;i>=0;i--)
        {
            if(count == 0)
                break;
            if(S[i] != ' ')
            {
                S[i + 2 *count] = S[i];
            }
            else
            {
                S[i + 2 *count] = '0';
                S[i + 2 *count-1] = '2';
                S[i + 2 *count-2] = '%';
                count--;
            }
        }
        return S;
    }
};