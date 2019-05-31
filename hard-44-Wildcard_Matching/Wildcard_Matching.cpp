class Solution {
public:
    bool isMatch(string s, string p) {
        int x=s.size(), y=p.size();
        bool dpmap[2000][2000]={false};
        s += '#';
        dpmap[0][0] = 1;
        for(int j=0;j<y;j++)
            for(int i=0;i<=x;i++)
            {
                if(dpmap[i][j])
                {
                    switch(p[j]/31)
                    {
                        case 1: //*
                            if(s[i]!='#')
                                dpmap[i+1][j] = true;
                            dpmap[i][j+1] = true;
                            break;
                        case 2: //?
                            if(s[i]!='#')
                                dpmap[i+1][j+1] = true;
                            break;
                        case 3: //x
                            if(s[i]==p[j])
                                dpmap[i+1][j+1] = true;
                            break;
                    }
                }
            }
        if(dpmap[x][y])
            return true;
        else
            return false;
    }
};