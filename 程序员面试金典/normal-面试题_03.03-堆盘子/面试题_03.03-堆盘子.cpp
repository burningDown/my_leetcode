class StackOfPlates {
private:
    vector<stack<int>> stackArray;
    int cap;
public:
    StackOfPlates(int cap) {
        this->cap = cap;
    }
    
    void push(int val) {
        if(cap == 0)
            return;
        if(stackArray.size() == 0 || stackArray.back().size() >= cap)
            stackArray.push_back({});
        stackArray.back().push(val);
    }
    
    int pop() {
        int res = -1;
        if(stackArray.size() > 0 && stackArray.back().size() > 0)
        {
            res = stackArray.back().top();
            stackArray.back().pop();
            if(stackArray.back().size() == 0)
                stackArray.pop_back();
        }
        return res;
    }
    
    int popAt(int index) {
        int res = -1;
        if(index < stackArray.size())
        {
            res = stackArray[index].top();
            stackArray[index].pop();
            if(stackArray[index].size() == 0)
                stackArray.erase(stackArray.begin() + index);
        }
        return res;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */