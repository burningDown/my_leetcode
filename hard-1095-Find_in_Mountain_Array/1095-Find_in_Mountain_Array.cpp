/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int binarySearchTop(MountainArray &mountainArr)
    {
        int l = mountainArr.length();
        int i = 0, j = l-1;
        int mid;
        int midV, midLeftV, midRightV;
        while(i < j)
        {
            mid = (i + j) / 2;
            midV = mountainArr.get(mid);
            midLeftV = mountainArr.get(mid - 1);

            if(midV > midLeftV)
            { 
                midRightV = mountainArr.get(mid + 1);
                if(midV > midRightV)
                    return mid;
                else
                    i = mid + 1;
            }
            else
                j = mid;
        }
        return i;
    }

    int binarySearch(MountainArray &mountainArr, int i, int j, int target, bool upward)
    {
        int mid;
        int midV;

        if(mountainArr.get(i) == target)
            return i;
        if(mountainArr.get(j) == target)
            return j;
        
        while(i < j)
        {
            mid = (i + j) / 2;
            midV = mountainArr.get(mid);

            if(midV == target)
                return mid;
            else if(midV < target)
            {
                if(upward)
                    i = mid + 1;
                else
                    j = mid;
            }
            else
            {
                if(upward)
                    j = mid;
                else
                    i = mid + 1;
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int topIdx = binarySearchTop(mountainArr);
        int idx;

        if((idx = binarySearch(mountainArr, 0, topIdx, target, true)) != -1)
            return idx;
        return binarySearch(mountainArr, topIdx, mountainArr.length() - 1, target, false);
    }
};