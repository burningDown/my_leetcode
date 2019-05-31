using namespace std;
class Solution {
public:
    bool queryString(string S, int N) {
        for(int i = N-pow(2, int(log(N)/log(2)));i<=N;i++)
        {
            string buff;
            int shi = i;
            while(shi)
            {
                buff += '0' + (shi&1);
                shi = shi >> 1;
            }
            reverse(buff.begin(), buff.end());
            if(S.find(buff) == string::npos)
                return false;
        }
        return true;
    }
};