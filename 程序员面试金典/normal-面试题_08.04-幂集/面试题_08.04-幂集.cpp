class Solution {
private:
    void trackback(vector<vector<int>> &result, vector<int> &buffer, vector<int> &nums, int l, int i)
    {
        if(buffer.size() == l)
        {
            result.push_back(buffer);
            return;
        }

        const int ln = nums.size();

        if(i >= ln)
            return;

        for(int j=i;j<ln;j++)
        {
            buffer.push_back(nums[j]);
            trackback(result, buffer, nums, l, j+1);
            buffer.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int l = nums.size();

        vector<vector<int>> result;
        vector<int> buffer;

        for(int i=0;i<=l;i++)
        {
            trackback(result, buffer, nums, i, 0);
        }

        return result;
    }
};