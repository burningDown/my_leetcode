class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carray = 0;
        const int la = a.size();
        const int lb = b.size();

        for(int i=0;i<la && i<lb;i++)
        {
            res.push_back(((a[la - i - 1] - '0') ^ (b[lb - i - 1] - '0') ^ carray) + '0');
            carray = (a[la - i - 1] - '0') & (b[lb - i - 1] - '0') | (a[la - i - 1] - '0') & carray | carray & (b[lb - i - 1] - '0');
        }

        for(int i=lb - la - 1;i>=0;i--)
        {
            res.push_back(((b[i] - '0') ^ carray) + '0');
            carray = (b[i] - '0') & carray;
        }
        for(int i=la - lb - 1;i>=0;i--)
        {
            res.push_back(((a[i] - '0') ^ carray) + '0');
            carray = (a[i] - '0') & carray;
        }
        if(carray)
            res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};