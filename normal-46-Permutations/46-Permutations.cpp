class Solution {
private:
    void trackback(vector<vector<int>> &result, vector<int> &nums, vector<int> &buffer, vector<bool> &visited)
    {
        if(buffer.size() == nums.size())
        {
            result.push_back(buffer);
            return;
        }

        const int l = nums.size();

        for(int i=0;i<l;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                buffer.push_back(nums[i]);
                trackback(result, nums, buffer, visited);
                buffer.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> buffer;
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> result;

        trackback(result, nums, buffer, visited);
        return result;
    }
};