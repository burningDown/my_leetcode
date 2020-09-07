bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] - v1[0] > v2[1] - v2[0];
}

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for(auto &item : bookings)
        {
            for(int i=item[0];i<=item[1];i++)
                res[i-1] += item[2];
        }
        return res;
    }
};