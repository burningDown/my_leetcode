class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int l = strs.size();
        if(l == 0)
            return "";
        if(l == 1)
            return strs[0];
        
        bool flag = true;
        int i, j;
        for(i=0;flag;i++)
        {
            for(j=1;j<l;j++)
            {
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        return strs[0].substr(0, i-1);
    }
};