class Solution {
private:
    void trackback(vector<vector<string>> &res, vector<string> &aRes, vector<bool> &rows, vector<bool> &cols, vector<bool> &lDLines, vector<bool> &rDLines, int i, int j, int n)
    {
        if(rows[i] || cols[j] || lDLines[i+j] || rDLines[i-j+n])
        {
            return;
        }

        rows[i] = cols[j] = lDLines[i+j] = rDLines[i-j+n] = true;
        string aRow(n, '.');
        aRow[j] = 'Q';
        aRes.push_back(aRow);
        
        if(i < n-1)
        {
            for(int k=0;k<n;k++)
                trackback(res, aRes, rows, cols, lDLines, rDLines, i+1, k, n);
        }
        else
        {
            res.push_back(aRes);
        }

        rows[i] = cols[j] = lDLines[i+j] = rDLines[i-j+n] = false;
        aRes.pop_back();
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> aRes;
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        vector<bool> lDLines(2 * n, false);
        vector<bool> rDLines(2 * n, false);

        for(int k=0;k<n;k++)
            trackback(res, aRes, rows, cols, lDLines, rDLines, 0, k, n);
        
        return res;
    }
};