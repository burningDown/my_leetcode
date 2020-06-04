class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int l1 = nums1.size();
		const int l2 = nums2.size();

		int i1 = 0, j1 = l1 - 1, i2 = 0, j2 = l2 - 1, mid1, mid2, minRegion;

		mid1 = (i1 + j1) / 2;
		mid2 = (i2 + j2) / 2;
		while (i1 < j1 - 1)
		{
			if (nums1[mid1] == nums2[mid2])
			{
				break;
			}
			else if (nums1[mid1] < nums2[mid2])
			{
				minRegion = min(j1 - mid1, mid2 - i2);
				i1 = mid1;
				j1 = mid1 + minRegion;
				mid1 += minRegion / 2;

				i2 = mid2 - minRegion;
				j2 = mid2;
				mid2 -= minRegion / 2;
			}
			else
			{
				minRegion = min(mid1 - i1, j2 - mid2);
				i1 = mid1 - minRegion;
				j1 = mid1;
				mid1 -= minRegion / 2;

				i2 = mid2;
				j2 = mid2 + minRegion;
				mid2 += minRegion / 2;
			}
		}
        return (l1 + l2) % 2 == 1 ? (nums1[mid1] > nums2[mid2] ? nums1[mid1] : nums2[mid2]) : (nums1[mid1] + nums2[mid2]) / 2.0;
    }
};