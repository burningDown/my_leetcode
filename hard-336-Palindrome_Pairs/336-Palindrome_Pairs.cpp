class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int l = words.size();
        int li, lj;
        char ci, cj;
        bool flag;
        vector<vector<int>> res;

        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(i == j)
                    continue;
                
                li = words[i].size();
                lj = words[j].size();
                flag = false;
                for(int k=0;k<=(li+lj)/2;k++)
                {
                    ci = k < li ? words[i][k] : words[j][k-li];
                    cj = k < lj ? words[j][lj-k-1] : words[i][li-1-k+lj];
                    if(ci != cj)
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    res.push_back({i, j});
            }
        }

        return res;
    }
};