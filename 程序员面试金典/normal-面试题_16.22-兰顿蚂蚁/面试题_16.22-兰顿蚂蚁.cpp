inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a > b ? a : b;
}

class Solution {
public:
    vector<string> printKMoves(int K) {
        const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        const char dirName[4] = {'U', 'R', 'D', 'L'};
        int d = 1;
        int cp[2] = {0, 0};
        int mini, minj, maxi, maxj;
        unordered_map<int, unordered_map<int, char>> mapMap;

        mini = minj = maxi = maxj = 0;
        for(int i=0;i<K;i++)
        {
            if(mapMap[cp[0]][cp[1]] == 0 || mapMap[cp[0]][cp[1]] == '_')
            {
                mapMap[cp[0]][cp[1]] = 'X';
                d = (d + 1) % 4;
                cp[0] += dir[d][0];
                cp[1] += dir[d][1];

                mini = min(mini, cp[0]);
                minj = min(minj, cp[1]);
                maxi = max(maxi, cp[0]);
                maxj = max(maxj, cp[1]);
            }
            else
            {
                mapMap[cp[0]][cp[1]] = '_';
                d = (d + 3) % 4;
                cp[0] += dir[d][0];
                cp[1] += dir[d][1];

                mini = min(mini, cp[0]);
                minj = min(minj, cp[1]);
                maxi = max(maxi, cp[0]);
                maxj = max(maxj, cp[1]);
            }
        }

        vector<string> result(maxi - mini + 1, string(maxj - minj + 1, '_'));
        for(auto it1=mapMap.begin();it1!=mapMap.end();++it1)
        {
            for(auto it2=it1->second.begin();it2!=it1->second.end();++it2)
            {
                if(it2->second == 'X')
                {
                    result[it1->first - mini][it2->first - minj] = 'X';
                }
            }
        }
        result[cp[0]-mini][cp[1]-minj] = dirName[d];

        return result;
    }
};