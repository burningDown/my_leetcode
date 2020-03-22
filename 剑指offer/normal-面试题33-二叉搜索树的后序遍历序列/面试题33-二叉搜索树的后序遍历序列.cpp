class Solution {
private:
    bool dac(vector<int>& postorder, int start, int end)
    {
        if(start >= end)
            return true;
        
        int flag, div;
        for(flag = start;postorder[flag] < postorder[end];flag++)
            ;
        div = flag - 1;
        for(;postorder[flag] > postorder[end];flag++)
            ;

        if(flag < end)
            return false;

        return dac(postorder, start, div) && dac(postorder, div+1, end-1);
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return dac(postorder, 0, postorder.size()-1);
    }
};