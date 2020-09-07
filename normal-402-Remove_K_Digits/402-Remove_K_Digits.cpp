class Solution {
public:
    string removeKdigits(string num, int k) {
        int l = num.size();

        int zeroIdx;
        for(zeroIdx=0;zeroIdx<l;zeroIdx++)
        {
            if(num[zeroIdx] > '0')
                break;
        }
        if(zeroIdx == l)
            return "0";
        
        num.erase(0, zeroIdx);

        l = num.size();

        if(k == 0)
            return num;
        
        if(l == k)
            return "0";
        
        for(int i=0;i<l;i++)
        {
            if(i < l-1 && num[i] > num[i+1] || i == l-1)
            {
                num.erase(i, 1);
                return removeKdigits(num, k-1);
            }
        }
        return num;
    }
};