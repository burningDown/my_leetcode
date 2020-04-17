class Solution {
public:
    bool isUnique(string astr) {
        int bitMap = 0;
        for(char c : astr)
        {
            if( (1 << (c-'a')) & bitMap )
                return false;
            
            bitMap |= (1 << (c-'a'));
        }
        return true;
    }
};