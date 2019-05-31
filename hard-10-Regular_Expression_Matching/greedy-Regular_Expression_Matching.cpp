class Solution {
private:
    string s;
    string p;
    int ls;
    int lp;
    bool func(int i, int j)
    {
        while(i<ls&&j<lp)
        {
            if(j+1<lp&&p[j+1] == '*')
                j++;
            else if(p[j] == '.')
            {
                i++;
                j++;
            }
            else if(p[j] == '*')
            {
                if(s[i] == p[j-1]||p[j-1] == '.')
                {
                    return func(i+1, j)||func(i+1, j+1)||func(i, j+1);
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if(s[i] == p[j])
                {
                    i++;
                    j++;
                }
                else
                    return false;
            }
        }
        return (i>=ls&&j>=lp)||(j==lp-2&&p[j+1]=='*') ? true : false;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        this->ls = s.size();
        this->lp = p.size();
        
        return func(0, 0);
    }
};
