class Solution {
private:
    bool visited[50000+10];
public:
    Solution(): visited({0}) {}
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)
            return true;
            
        if(start - arr[start] >= 0 && !visited[start - arr[start]])
        {
            visited[start - arr[start]] = true;
            if(canReach(arr, start - arr[start]))
                return true;
        }
        if(start + arr[start] < arr.size() && !visited[start + arr[start]])
        {
            visited[start + arr[start]] = true;
            if(canReach(arr, start + arr[start]))
                return true;
        }
        return false;
    }
};