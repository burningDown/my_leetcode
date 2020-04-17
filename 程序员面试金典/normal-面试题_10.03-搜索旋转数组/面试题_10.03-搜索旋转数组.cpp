class Solution {
private:
    int binarySearch(vector<int> &arr, int l, int r, int target)
    {
        int mid;
        if(arr[l] == target)
            return l;
        
        while(l < r)
        {
            mid = (l + r) / 2;
            if(arr[mid] == target)
            {
                int i;
                for(i=mid;i>=0;i--)
                {
                    if(arr[i] != target)
                        break;
                }
                return i+1;
            }
            else if(arr[mid] > arr[l] || mid == l)
            {
                if(target == arr[l])
                {
                    int i;
                    for(i=l;i>=0;i--)
                    {
                        if(arr[i] != target)
                            break;
                    }
                    return i+1;
                }
                else if(target < arr[mid] && target > arr[l])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if(arr[mid] < arr[l])
            {
                if(target == arr[l])
                {
                    int i;
                    for(i=l;i>=0;i--)
                    {
                        if(arr[i] != target)
                            break;
                    }
                    return i+1;
                }
                else if(target > arr[mid] && target < arr[l])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                int temp = l;
                l = mid;
                for(int i=temp;i<mid;i++)
                {
                    if(arr[i] != arr[mid])
                    {
                        l = i;
                        break;
                    }
                }
                temp = r;
                r = mid;
                for(int i=temp;i>mid;i--)
                {
                    if(arr[i] != arr[mid])
                    {
                        r = i;
                        break;
                    }
                }
            }
        }

        if(arr[l] == target)
            return l;
        else
            return -1;
    }
public:
    int search(vector<int>& arr, int target) {
        return binarySearch(arr, 0, arr.size()-1, target);
    }
};