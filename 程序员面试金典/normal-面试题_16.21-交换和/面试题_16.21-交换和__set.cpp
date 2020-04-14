class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        const int l1 = array1.size();
        const int l2 = array2.size();
        int s1 = 0, s2 = 0, diff;
        unordered_set<int> numSet;
        vector<int> result;

        for(int i : array1)
            s1 += i;
        for(int i : array2)
            s2 += i;

        if(s1 > s2)
        {
            diff = s1 - s2;
            if(diff % 2 == 1)
                return result;
            for(int i : array1)
                numSet.insert(i - diff/2);
            for(int i : array2)
            {
                if(numSet.count(i) == 1)
                {
                    result.push_back(i+diff/2);
                    result.push_back(i);
                    return result;
                }
            }
        }
        else
        {
            diff = s2 - s1;
            if(diff % 2 == 1)
                return result;
            for(int i : array2)
                numSet.insert(i - diff/2);
            for(int i : array1)
            {
                if(numSet.count(i) == 1)
                {
                    result.push_back(i);
                    result.push_back(i + diff/2);
                    return result;
                }
            }
        }
        return result;
    }
};