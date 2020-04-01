class MedianFinder {
private:
    vector<int> nums;
    void insert(int x)
    {
        nums.push_back(0);

        int i;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1] < x)
                break;
            nums[i] = nums[i-1];
        }
        nums[i] = x;
    }
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nums.reserve(50000);
    }
    
    void addNum(int num) {
        insert(num);
    }
    
    double findMedian() {
        return nums.size() % 2 == 0 ? (nums[nums.size()/2-1]+nums[nums.size()/2])/2.0 : nums[nums.size()/2];
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */