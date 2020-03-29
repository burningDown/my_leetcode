class MaxQueue {
private:
    queue<int> baseQueue;
    deque<int> maxQueue;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return maxQueue.size() == 0 ? -1 : maxQueue.front();
    }
    
    void push_back(int value) {
        baseQueue.push(value);
        while(maxQueue.size() > 0 && maxQueue.back() < value)
            maxQueue.pop_back();
        maxQueue.push_back(value);
    }
    
    int pop_front() {
        if(baseQueue.size() == 0)
            return -1;
        
        int res = baseQueue.front();
        baseQueue.pop();
        if(maxQueue.front() == res)
            maxQueue.pop_front();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */