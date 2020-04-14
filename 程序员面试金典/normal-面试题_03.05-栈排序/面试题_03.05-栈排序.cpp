class SortedStack {
private:
    stack<int> mainStack;
    stack<int> assistantStack;
public:
    SortedStack() {
        
    }
    
    void push(int val) {
        while(!mainStack.empty() && mainStack.top() < val)
        {
            assistantStack.push(mainStack.top());
            mainStack.pop();
        }
        mainStack.push(val);
        while(!assistantStack.empty())
        {
            mainStack.push(assistantStack.top());
            assistantStack.pop();
        }
    }
    
    void pop() {
        if(!mainStack.empty())
            mainStack.pop();
    }
    
    int peek() {
        return mainStack.empty() ? -1 : mainStack.top();
    }
    
    bool isEmpty() {
        return mainStack.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */