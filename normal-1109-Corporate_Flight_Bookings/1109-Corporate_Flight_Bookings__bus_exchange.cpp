class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> integralMap(n+1, 0);
        vector<int> res(n, 0);
        for(auto &item : bookings)
        {
            integralMap[item[0]-1] += item[2];
            integralMap[item[1]] -= item[2];
        }

        res[0] = integralMap[0];

        for(int i=1;i<n;i++)
            res[i] = res[i-1] + integralMap[i];
        
        return res;
    }
};