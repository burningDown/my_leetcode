class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> prefixMap;
        const int l = A.size();
        int sum = 0;
        int remainer;
        int res = 0;

        prefixMap[0] = 1;
        for(int i=0;i<l;i++)
        {
            sum += A[i];
            remainer = sum % K;
            if(remainer < 0)
                remainer += K;
             
            if(prefixMap.find(remainer) != prefixMap.end())
                res += prefixMap[remainer];
            
            prefixMap[remainer]++;
        }

        return res;
    }
};