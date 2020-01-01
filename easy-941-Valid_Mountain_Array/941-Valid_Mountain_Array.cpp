class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool upper = true;
        int pre = -1;

        if(A.size()<3 || A[1]<=A[0])
            return false;
        for(int x : A)
        {
            if(upper && x<pre)
                upper = false;
            else if(x==pre || (!upper && x>pre))
                return false;
            pre = x;
        }
        if(upper)
            return false;
        return true;
    }
};