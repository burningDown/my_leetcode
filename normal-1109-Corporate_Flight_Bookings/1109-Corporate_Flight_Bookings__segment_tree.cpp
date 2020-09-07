struct SegmentNode
{
    int sum;
    int l;
    int r;
    SegmentNode(): sum(0), l(0), r(0) {}
};

class SegmentTree
{
private:
    vector<SegmentNode> treeBuffer;
public:
    SegmentTree(int n): treeBuffer(n) {}

    void build(int i, int l, int r)
    {
        treeBuffer[i].l = l;
        treeBuffer[i].r = r;
        if(l == r)
        {
            treeBuffer[i].sum = 0;
        }
        else
        {
            int mid = (l + r) >> 1;
            build(2 * i + 1, l, mid);
            build(2 * i + 2, mid + 1, r);
            treeBuffer[i].sum = treeBuffer[2 * i + 1].sum + treeBuffer[2 * i + 2].sum;
        }
    }

    void add(int value, int i, int l, int r)
    {
        if(treeBuffer[i].l >= l && treeBuffer[i].r <= r)
            treeBuffer[i].sum += value;
        else
        {
            if(treeBuffer[2 * i + 1].r >= l)
                add(value, 2 * i + 1, l, r);
            if(treeBuffer[2 * i + 2].l <= r)
                add(value, 2 * i + 2, l, r);
        }
    }

    int get(int i, int idx)
    {
        int res = treeBuffer[i].sum;
        if(treeBuffer[i].l != treeBuffer[i].r)
        {
            if(idx <= treeBuffer[2 * i + 1].r)
                res += get(2 * i + 1, idx);
            if(idx >= treeBuffer[2 * i + 2].l)
                res += get(2 * i + 2, idx);
        }
        return res;
    }
};

class Solution {
private:
    
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        SegmentTree segmentTree(4 * n);
        vector<int> res(n, 0);

        segmentTree.build(0, 0, n-1);

        for(auto &item : bookings)
            segmentTree.add(item[2], 0, item[0] - 1, item[1] - 1);
        
        for(int i=0;i<n;i++)
            res[i] = segmentTree.get(0, i);

        return res;
    }
};