class Solution {
public:
    bool isMatch(string s, string p) {
        int convp[100], dpmap[100][100]={0};
        int x=s.size(), y=0;
        int lp=p.size();
        s += '#';
        for(int i=0;i<lp;i++)
        {
            if(i+1<lp&&p[i+1]=='*')
                continue;
            if(p[i]=='*')
                convp[y++] = p[i-1]-32;
            else
                convp[y++] = p[i];
        }
        dpmap[0][0] = 1;
        for(int j=0;j<y;j++)
            for(int i=0;i<=x;i++)
            {
                if(dpmap[i][j] == 1)
                {
                    switch(convp[j]/31)
                    {
                        case 0: //.*
                            if(s[i]!='#')
                                dpmap[i+1][j] = 1;
                            dpmap[i][j+1] = 1;
                            break;
                        case 1: //.
                            if(s[i]!='#')
                                dpmap[i+1][j+1] = 1;
                            break;
                        case 2: //x*
                            if(s[i]==convp[j]+32)
                            {
                                dpmap[i+1][j] = 1;
                                dpmap[i][j+1] = 1;
                            }
                            else
                                dpmap[i][j+1] = 1;
                            break;
                        case 3: //x
                            if(s[i]==convp[j])
                                dpmap[i+1][j+1] = 1;
                            break;
                    }
                }
            }
        if(dpmap[x][y]==1)
            return true;
        else
            return false;
    }
};