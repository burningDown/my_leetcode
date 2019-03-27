#include<queue>
using namespace std;
class MyStack {
private:
    queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int i, y;
        int l = que.size() - 1;
        for(i=0;i<l;i++) {
            que.push(que.front());
            que.pop();
        }
        y = que.front();
        que.pop();
        return y;
    }
    
    /** Get the top element. */
    int top() {
        int y = this->pop();
        que.push(y);
        return y;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 
//****************************************************test************************************
#include <iostream> 
int main()
{
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);
	cout << myStack.top() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.empty() <<endl;
	return 0;
}
