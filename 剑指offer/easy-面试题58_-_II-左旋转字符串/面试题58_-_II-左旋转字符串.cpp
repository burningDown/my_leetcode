class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // string result(s, n, s.size()-n);
        // result.append(s, 0, n);
        // return result;
        return s.substr(n, s.size()-n) + s.substr(0, n);
    }
};