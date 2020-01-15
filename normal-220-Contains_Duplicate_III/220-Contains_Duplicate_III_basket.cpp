class Solution {
private:
    unordered_map<int, int> basket;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        const int &n = nums.size();
        int i, j;
        if(k<=0 || t<0)
            return false;
        if(t != 0)
        {
            for(i=0;i<k;i++)
            {
                const long &m = nums[i];
                const long &v = m >=0 ? m/t : (m-1)/t;
                if(basket.count(v))
                {
                    return true;
                }
                else if (basket.count(v-1))
                {
                    const auto &b = basket[v-1];
                    if(m - b <= t)
                        return true;
                }
                else if(basket.count(v+1))
                {
                    const auto &b = basket[v+1];
                    if(b - m <= t)
                        return true;
                }
                basket[v] = m;
            }
            for(i=k;i<n;i++)
            {
                const long &m = nums[i];
                const long &v = m >=0 ? m/t : (m-1)/t;
                const long &boundv = nums[i-k]>=0 ? nums[i-k]/t : (nums[i-k]-1)/t;
                if(basket.count(v))
                {
                    return true;
                }
                else if (basket.count(v-1))
                {
                    const long &b = basket[v-1];
                    if(m - b <= t)
                        return true;
                }
                else if(basket.count(v+1))
                {
                    const long &b = basket[v+1];
                    if(b - m <= t)
                        return true;
                }
                basket.erase(boundv);
                basket[v] = m;
            }
        }
        else
        {
            for(i=0;i<k;i++)
            {
                const long &m = nums[i];
                if(basket.count(m))
                {
                    return true;
                }
                basket[m] = m;
            }
            for(i=k;i<n;i++)
            {
                const long &m = nums[i];
                const long &boundv = nums[i-k];
                if(basket.count(m))
                {
                    return true;
                }
                basket.erase(boundv);
                basket[m] = m;
            }
        }
        return false;
    }
};