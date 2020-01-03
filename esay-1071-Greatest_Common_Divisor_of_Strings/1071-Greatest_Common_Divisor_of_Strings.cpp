class Solution {
private:
    int gcd(int a, int b)
    {
        int min = a < b ? a : b;
        int max = a > b ? a : b;
        int temp;
        while((temp = max % min) != 0)
            if(temp < min)
            {
                max = min;
                min = temp;
            }
            else
                max = temp;
        return min;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        const int &l1 = str1.size(), &l2 = str2.size();
        const int &g = gcd(l1, l2);
        string gcdBuf(str1, 0, g);
        for(int i=0;i<l1;i++)
            if(gcdBuf[i%g] != str1[i])
                return string("");
        for(int i=0;i<l2;i++)
            if(gcdBuf[i%g] != str2[i])
                return string("");
        return gcdBuf;
    }
};