bool cmp(vector<int> &i1, vector<int> &i2)
{
    return i1[0] < i2[0] || i1[0] == i2[0] && i1[1] < i2[1];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return {};
        vector<vector<int>> result;
        vector<int> merged;
        const int l = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        merged = intervals[0];
        for(int i=1;i<l;i++)
        {
            if(intervals[i][0] > merged[1])
            {
                result.push_back(merged);
                merged = intervals[i];
            }
            else if(intervals[i][1] > merged[1])
            {
                merged[1] = intervals[i][1];
            }
        }
        result.push_back(merged);
        return result;
    }
};