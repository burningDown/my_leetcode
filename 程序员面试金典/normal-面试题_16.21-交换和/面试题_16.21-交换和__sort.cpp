class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int s1 = 0, s2 = 0, diff, p1, p2;
        const int l1 = array1.size();
        const int l2 = array2.size();
        vector<int> result;
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        for(int i : array1)
            s1 += i;
        for(int i : array2)
            s2 += i;
        
        if(s1 > s2)
        {
            diff = s1 - s2;
            if(diff % 2 == 1)
                return result;
            p1 = p2 = 0;
            while(p1 < l1 && p2 < l2)
            {
                if(array1[p1] - array2[p2] == diff/2)
                {
                    result.push_back(array1[p1]);
                    result.push_back(array2[p2]);
                    return result;
                }
                else if(array1[p1] - array2[p2] < diff/2)
                    p1++;
                else
                    p2++;
            }
        }
        else if(s2 > s1)
        {
            diff = s2 - s1;
            if(diff % 2 == 1)
                return result;
            p1 = p2 = 0;
            while(p1 < l1 && p2 < l2)
            {
                if(array2[p2] - array1[p1] == diff/2)
                {
                    result.push_back(array1[p1]);
                    result.push_back(array2[p2]);
                    return result;
                }
                else if(array2[p2] - array1[p1] < diff/2)
                    p2++;
                else
                    p1++;
            }
        }
        return result;
    }
};