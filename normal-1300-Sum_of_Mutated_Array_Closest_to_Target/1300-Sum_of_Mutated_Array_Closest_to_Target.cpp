class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        const int l = arr.size();
        const int anchor = abs(target - l * (target / l)) < abs(target - l * (target / l + 1)) ? target / l : target / l + 1;
        int sk = 0, integral = 0;
        
        sort(arr.begin(), arr.end());
        if(anchor <= arr[0])
            return anchor;
        else if(anchor >= arr[l-1])
            return arr[l-1];
        else
        {
            int i;
            for(i=0;i<l;i++)
            {
                if(integral + arr[i] * (l - i) >= target)
                    break;
                else
                    integral += arr[i];
            }

            return abs((target - integral) - (l-i) * ((target - integral) / (l-i))) <= abs((target - integral) - (l-i) * ((target - integral) / (l-i) + 1)) ? (target - integral) / (l-i) : (target - integral) / (l-i) + 1;
        }
    }
};