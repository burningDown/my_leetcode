class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<long> stateStack;
        unordered_set<long> stateSet;
        int tx, ty;
        long state;
        
        if(z == 0)
            return true;
        if(z > x + y)
            return false;
        else if(x == 0)
        {
            if(z == y)
                return true;
            else
                return false;
        }
        else if(y == 0)
        {
            if(z == x)
                return true;
            else
                return false;
        }
        
        stateStack.push(0);
        stateSet.insert(0);
        while(!stateStack.empty())
        {
            state = stateStack.top();
            stateStack.pop();
            ty = state / (x+1);
            tx = state % (x+1);

            if(tx + ty == z)
                return true;
            
            if(tx == 0)
            {
                state = long(ty)*(x+1) + x;
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }
            }
            if(ty == 0)
            {
                state = long(y)*(x+1) + tx;
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }
            }
            if(tx > 0)
            {
                if(tx > y - ty)
                    state = long(y)*(x+1) + (tx-y+ty);
                else
                    state = long(ty + tx)*(x+1);
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }

                state = long(ty)*(x+1);
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }
            }
            if(ty > 0)
            {
                if(ty > x - tx)
                    state = long(ty-x+tx)*(x+1) + x;
                else
                    state = long(ty + tx);
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }

                state = long(tx);
                if(stateSet.count(state) == 0)
                {
                    stateSet.insert(state);
                    stateStack.push(state);
                }
            }
        }
        return false;
    }
};