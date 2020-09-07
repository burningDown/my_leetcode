class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        
        int n = pow(10, int(log10(x)));
        for(int i=1;i<n;i*=10)
            if( x / i % 10 != x / (n / i) % 10 )
                return false;
        return true;
    }
};