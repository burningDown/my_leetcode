class CQueue {
private:
    stack<int> mainStack;
    stack<int> asistantStack;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        mainStack.push(value);
    }
    
    int deleteHead() {
        if(asistantStack.size() == 0)
        {
            if(mainStack.size() == 0)
                return -1;
            else
            {
                for(int i=mainStack.size();i>0;i--)
                {
                    asistantStack.push(mainStack.top());
                    mainStack.pop();
                }
            }
        }
        int x = asistantStack.top();
        asistantStack.pop();
        return x;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */