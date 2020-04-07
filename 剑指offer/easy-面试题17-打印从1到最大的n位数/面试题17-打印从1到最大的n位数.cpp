class Solution {
private:
    int binaryPow(int a, int n)
    {
        int s = 1;
        while(n > 0)
        {
            if(n & 1)
                s *= a;
            a *= a;
            n >>= 1;
        }
        return s;
    }
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        int s = binaryPow(10, n);
        
        result.reserve(s+5);
        for(int i=1;i<s;i++)
            result.push_back(i);
        return result;
    }
};