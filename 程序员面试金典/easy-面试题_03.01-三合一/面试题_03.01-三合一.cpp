class TripleInOne {
private:
    int storage[100000];
    int p[3];
    int size;
public:
    TripleInOne(int stackSize)
    {
        size = stackSize;
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
    }
    
    void push(int stackNum, int value) {
        if(p[stackNum] / 3 < size)
        {
            storage[p[stackNum]] = value;
            p[stackNum] += 3;
        }
    }
    
    int pop(int stackNum) {
        return p[stackNum] >= 3 ? (p[stackNum] -= 3, storage[p[stackNum]]) : -1;
    }
    
    int peek(int stackNum) {
        return p[stackNum] >= 3 ? storage[p[stackNum]-3] : -1;
    }
    
    bool isEmpty(int stackNum) {
        return p[stackNum] < 3;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */