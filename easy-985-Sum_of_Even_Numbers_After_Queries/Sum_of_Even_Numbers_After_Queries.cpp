class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int la = A.size(), lq = queries.size();
        vector<int> answer(lq);
        int sum = 0;
        for(int i=0;i<la;i++)
            !(A[i]%2)&&(sum += A[i]);
        for(int i=0;i<lq;i++)
        {
            (!(A[queries[i][1]]%2))?((!(queries[i][0]%2))?(sum+=queries[i][0]):(sum-=A[queries[i][1]])):((queries[i][0]%2)&&(sum+=A[queries[i][1]]+queries[i][0]));
            answer[i] = sum;
            A[queries[i][1]] += queries[i][0];
        }
        return answer;
    }
};