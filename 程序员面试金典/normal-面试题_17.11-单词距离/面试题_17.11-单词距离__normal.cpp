inline int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        const int l = words.size();
        int p1 = 0, p2 = 0;
        int res = l;

        while(p1 < l && p2 < l)
        {
            while(p1 < l)
            {
                if(word1 == words[p1])
                    break;
                p1++;
            }

            if(p1 >= l)
                break;
            
            while(p2 < l)
            {
                if(word2 == words[p2])
                    break;
                p2++;
            }

            if(p2 >= l)
                break;

            if(p1 <= p2)
            {
                res = min(res, p2 - p1);
                p1++;
            }
            else
            {
                res = min(res, p1 - p2);
                p2++;            
            }
        }
        return res;
    }
};