inline int min(int a, int b)
{
    return a < b ? a : b;
}

class Solution {
private:
    int minDist(vector<int> &v1, vector<int> &v2)
    {
        int p1 = 0, p2 = 0;
        int res;
        const int l1 = v1.size();
        const int l2 = v2.size();

        res = abs(v2[0] - v1[0]);
        while(p1 < l1 && p2 < l2)
        {
            res = min(res, abs(v2[p2] - v1[p1]));
            if(v1[p1] <= v2[p2])
                p1++;
            else
                p2++;
        }
        return res;
    }
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> strMap;
        const int l = words.size();

        for(int i=0;i<l;i++)
        {
            strMap[words[i]].push_back(i);
        }

        return minDist(strMap[word1], strMap[word2]);
    }
};