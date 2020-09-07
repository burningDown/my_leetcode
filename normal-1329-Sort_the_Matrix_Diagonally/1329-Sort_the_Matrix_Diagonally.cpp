class Getter
{
private:
    vector<vector<int>> &mat;
    int rowOrCol;
public:
    Getter(vector<vector<int>> &mat0): mat(mat0), rowOrCol(0) {}
    void setRowOrCol(int roc)
    {
        rowOrCol = roc;
    }
    int size()
    {
        if(rowOrCol < 0)
            return min(mat[0].size(), mat.size() + rowOrCol);
        else
            return min(mat[0].size() - rowOrCol, mat.size());
    }
    int get(int idx)
    {
        if(rowOrCol < 0)
            return mat[idx-rowOrCol][idx];
        else
            return mat[idx][idx+rowOrCol];
    }
    void set(int idx, int value)
    {
        if(rowOrCol < 0)
            mat[idx-rowOrCol][idx] = value;
        else
            mat[idx][idx+rowOrCol] = value;
    }
};

class Solution {
private:
    void heapSort(Getter &getter)
    {
        const int l = getter.size();
        for(int i=(l-1)/2;i>=0;i--)
        {
            adjust(getter, i, l);
        }

        for(int i=1;i<l;i++)
        {
            int temp = getter.get(0);
            getter.set(0, getter.get(l-i));
            getter.set(l-i, temp);
            adjust(getter, 0, l-i);
        }
    }
    void adjust(Getter &getter, int i, int l)
    {
        if(i >= l)
            return;
        
        int maxIdx = i;
        if(2 * i + 1 < l && getter.get(2 * i + 1) > getter.get(maxIdx))
            maxIdx = 2 * i + 1;
        if(2 * i + 2 < l && getter.get(2 * i + 2) > getter.get(maxIdx))
            maxIdx = 2 * i + 2;
        if(maxIdx != i)
        {
            int temp = getter.get(i);
            getter.set(i, getter.get(maxIdx));
            getter.set(maxIdx, temp);
            adjust(getter, maxIdx, l);
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int h = mat.size();
        const int w = mat[0].size();

        Getter getter(mat);

        for(int i=-h+1;i<w;i++)
        {
            getter.setRowOrCol(i);
            heapSort(getter);
        }
        return mat;
    }
};