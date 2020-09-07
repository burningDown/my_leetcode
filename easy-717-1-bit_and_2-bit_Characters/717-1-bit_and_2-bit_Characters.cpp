class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int l = bits.size();
        bool flag = true;
        
        for(int i=l-2;i>=0;i--)
        {
            if(bits[i] == 0)
                return flag;
            flag = !flag;
        }
        return flag;
    }
};