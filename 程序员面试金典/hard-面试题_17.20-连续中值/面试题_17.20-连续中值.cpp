class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> lessQueue;
    priority_queue<int> greaterQueue;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(lessQueue.size() == 0 || lessQueue.top() <= num)
        {
            lessQueue.push(num);
            if(lessQueue.size() > greaterQueue.size() + 1)
            {
                greaterQueue.push(lessQueue.top());
                lessQueue.pop();
            }
        }
        else
        {
            greaterQueue.push(num);
            if(lessQueue.size() < greaterQueue.size())
            {
                lessQueue.push(greaterQueue.top());
                greaterQueue.pop();
            }
        }
    }
    
    double findMedian() {
        if(lessQueue.size() == greaterQueue.size())
            return (lessQueue.top() + greaterQueue.top()) / 2.0;
        else
            return double(lessQueue.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */