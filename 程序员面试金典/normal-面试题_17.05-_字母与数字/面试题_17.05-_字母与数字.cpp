class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> countMap;
        const int l = array.size();
        int begin = -1, end = -1;
        int countA = 0, count1 = 0;

        countMap[0] = 0;

        for(int i=0;i<l;i++)
        {
            if(array[i][0] >= '0' && array[i][0] <= '9')
                count1++;
            else
                countA++;
            
            if(countMap.count(count1 - countA) > 0)
            {
                if(i - countMap[count1 - countA] > end - begin)
                {
                    end = i;
                    begin = countMap[count1 - countA];
                }
            }
            else
                countMap[count1 - countA] = i + 1;
        }

        if(begin < 0)
            return {};
        else
            return vector<string>(array.begin() + begin, array.begin() + end + 1);
    }
};