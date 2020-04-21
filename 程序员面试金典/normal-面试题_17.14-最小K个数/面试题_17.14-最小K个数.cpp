class Solution {
private:
    void quickFind(vector<int> &arr, int start, int end, int k)
    {   
        if(k == 0)
            return;
        int pIdx = rand() % (end - start + 1) + start;
        int partition = arr[pIdx];
        int i = start, j = end;
        arr[pIdx] = arr[i];
        while(i < j)
        {
            while(i < j)
            {
                if(arr[j] <= partition)
                {
                    arr[i] = arr[j];
                    i++;
                    break;
                }
                j--;
            }
            while(i < j)
            {
                if(arr[i] > partition)
                {
                    arr[j] = arr[i];
                    j--;
                    break;
                }
                i++;
            }
        }
        arr[i] = partition;
        if(i - start < k-1)
        {
            quickFind(arr, i+1, end, k+start-i-1);
        }
        else if(i - start > k-1)
        {
            quickFind(arr, start, i-1, k);
        }
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand(time(0));
        quickFind(arr, 0, arr.size()-1, k);
        return vector<int>(arr.begin(), arr.begin()+k);
    }
};