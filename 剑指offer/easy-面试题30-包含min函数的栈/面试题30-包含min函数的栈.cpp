class MinStack {
private:
    int mStack[20010];
    int minStack[20010];
    int s;
    int m;
public:
    /** initialize your data structure here. */
    MinStack():
        s(0),
        m(0)
    {

    }
    
    void push(int x) {
        mStack[s++] = x;
        if(m == 0 || mStack[minStack[m-1]] > x)
            minStack[m++] = s-1;
    }
    
    void pop() {
        if(s-1 == minStack[m-1])
            m--;
        s--;
    }
    
    int top() {
        return mStack[s-1];
    }
    
    int min() {
        return mStack[minStack[m-1]];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */