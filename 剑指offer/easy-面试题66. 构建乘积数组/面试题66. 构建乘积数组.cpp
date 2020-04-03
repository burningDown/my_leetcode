class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        const int l = a.size();
        if(l == 0)
            return vector<int>();
        vector<int> dp1(l);
        vector<int> dp2(l);
        vector<int> result;
        result.reserve(l + 10);
        dp1[0] = 1;
        dp2[l-1] = 1;
        for(int i=1;i<l;i++)
        {
            dp1[i] = a[i-1] * dp1[i-1];
            dp2[l-i-1] = a[l-i] * dp2[l-i];
        }
        for(int i=0;i<l;i++)
            result.push_back(dp1[i] * dp2[i]);
        return result;
    }
};