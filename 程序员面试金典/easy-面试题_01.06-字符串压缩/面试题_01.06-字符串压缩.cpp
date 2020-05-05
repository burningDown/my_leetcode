class Solution {
private:
    int subContinuousStr(string &S, int start)
    {
        const int l = S.size();
        start++;
        while(start < l)
        {
            if(S[start] != S[start-1])
                break;
            start++;
        }
        return start;
    }
    string press(string &S, int start, int end)
    {
        return string(1, S[start]) + to_string(end - start);
    }
public:
    string compressString(string S) {
        int start = 0, end = 0;
        const int l = S.size();
        string result;
        while(end < l)
        {
            end = subContinuousStr(S, start);
            result += press(S, start, end);
            start = end;
        }
        return S.size() <= result.size() ? S : result;
    }
};