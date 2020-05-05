class MyQueue {
private:
    stack<int> mainStack;
    stack<int> assistantStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mainStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = peek();
        assistantStack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(assistantStack.size() == 0)
        {
            while(!mainStack.empty())
            {
                assistantStack.push(mainStack.top());
                mainStack.pop();
            }
        }
        return assistantStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mainStack.empty() && assistantStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */