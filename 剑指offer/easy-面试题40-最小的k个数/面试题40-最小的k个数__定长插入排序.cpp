class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result(k, INT_MAX);
        const int l = arr.size();
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(arr[i] < result[j])
                {
                    for(int x=k-1;x>j;x--)
                        result[x] = result[x-1];
                    result[j] = arr[i];
                    break;
                }
            }
        }
        return result;
    }
};