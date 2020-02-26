class Solution {
private:
    list<int> validIdx;
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        const int &lenNum = num.size();
        const int &l = words.size();
        list<int>::iterator it;
        for(int i=0;i<l;i++)
        {
            if(words[i].size() == lenNum)
            {
                validIdx.push_back(i);
            }
        }

        for(int i=0;i<lenNum;i++)
        {
            it = validIdx.begin();
            while(it != validIdx.end())
            {
                const char &c = words[*it][i];
                switch(num[i])
                {
                case '2':
                    if(c != 'a' && c != 'b' && c != 'c')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '3':
                    if(c != 'd' && c != 'e' && c != 'f')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '4':
                    if(c != 'g' && c != 'h' && c != 'i')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '5':
                    if(c != 'j' && c != 'k' && c != 'l')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '6':
                    if(c != 'm' && c != 'n' && c != 'o')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '7':
                    if(c != 'p' && c != 'q' && c != 'r' && c != 's')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '8':
                    if(c != 't' && c != 'u' && c != 'v')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                case '9':
                    if(c != 'w' && c != 'x' && c != 'y' && c != 'z')
                    {
                        it = validIdx.erase(it);
                        continue;
                    }
                    break;
                }
                it++;
            }
        }

        vector<string> result(validIdx.size());
        int r=0;

        for(it = validIdx.begin();it!=validIdx.end();it++)
        {
            result[r++] = words[*it];
        }
        return result;
    }
};