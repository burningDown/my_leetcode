class Solution {
public:
    bool rotateString(string A, string B) {
        const int &la = A.size();
        const int &lb = B.size();

        int i, j;

        if(la != lb)
            return false;
        else if(la == 0 || lb == 0)
            return true;

        for(i=0;i<la;i++)
        {
            for(j=0;j<la;j++)
            {
                if(A[(j+i)%la] != B[j])
                    break;
            }
            if(j == la)
                return true;
        }

        return false;
    }
};