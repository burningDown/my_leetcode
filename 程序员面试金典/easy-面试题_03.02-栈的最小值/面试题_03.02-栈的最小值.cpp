class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        mainStack.push(x);
        if(minStack.empty() || minStack.top() >= x)
            minStack.push(x);
    }
    
    void pop() {
        if(!mainStack.empty())
        {
            if(minStack.top() == mainStack.top())
                minStack.pop();
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */