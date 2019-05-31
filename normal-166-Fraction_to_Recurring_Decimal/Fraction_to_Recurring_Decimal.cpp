class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> m;
        long long r, begin=-1, end=-1;
        long long result[10000], re=0;
        string sresult="";
        unordered_map<int,int>::const_iterator got;
        bool flag = ((long long)(numerator)*denominator<0);
        long long nu = abs((long long)numerator);
        long long de = abs((long long)denominator);
        r = nu;
        for(int i=0;;i++)
        {
            
            result[re++] = r / de;
            r = r % de;
            if(r == 0)
                break;
            if((got = m.find(r)) != m.end())
            {
                begin = got->second;
                end = i;
                break;
            }
            else
            {
                m.insert(make_pair(r,i));
            }
            r *= 10;
        }
        if(flag)
            sresult += '-';
        char buff[15];
        sprintf(buff, "%lld", result[0]);
        sresult += buff;
        if(re>1)
            sresult += '.';
        for(int i=1;i<re;i++)
        {
            if(i == begin+1)
                sresult += '(';
            sresult += '0' + result[i];
            if(i == end)
                sresult += ')';
        }
        return sresult;
    }
};