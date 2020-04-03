class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> assistStack;
        const int lenPushed = pushed.size();
        const int lenPopped = popped.size();
        int i = 0, j = 0;
        while(i < lenPushed && j < lenPopped)
        {
            if(assistStack.empty() || assistStack.top() != popped[j])
            {
                assistStack.push(pushed[i++]);
            }
            else if(assistStack.top() == popped[j])
            {
                assistStack.pop();
                j++;
            }
        }
        while(!assistStack.empty())
        {
            if(assistStack.top() == popped[j])
            {
                assistStack.pop();
                j++;
            }
            else
                return false;
        }
        return true;
    }
};