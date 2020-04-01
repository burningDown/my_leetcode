class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> lessHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        maxHeap.push(num);
        lessHeap.push(maxHeap.top());
        maxHeap.pop();
        if(lessHeap.size() > maxHeap.size())
        {
            maxHeap.push(lessHeap.top());
            lessHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size() == lessHeap.size() ? (maxHeap.top() + lessHeap.top()) / 2.0 : maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */