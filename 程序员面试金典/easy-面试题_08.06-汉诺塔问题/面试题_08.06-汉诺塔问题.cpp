class Solution {
private:
    void helper(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if(n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
        }
        else
        {
            helper(A, C, B, n-1);
            helper(A, B, C, 1);
            helper(B, A, C, n-1);
        }
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        helper(A, B, C, A.size());
    }
};