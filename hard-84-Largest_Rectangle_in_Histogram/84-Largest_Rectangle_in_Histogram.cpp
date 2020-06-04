class SegmentTree
{
private:
    vector<int> treeBuffer;
    vector<int> *pHeights;
    const int l;

    int recurQuery(int start, int end, int qstart, int qend, int root)
    {
        if(start > qend || end < qstart)
            return -1;
        
        if(start <= qstart && end >= qend)
            return treeBuffer[root];
        
        int mid = (qstart + qend) >> 1;

        int idx1 = recurQuery(start, end, qstart, mid, root * 2 + 1);
        int idx2 = recurQuery(start, end, mid + 1, qend, root * 2 + 2);
        
        if(idx1 < 0)
            return idx2;
        else if(idx2 < 0)
            return idx1;
        else
            return (*pHeights)[idx1] < (*pHeights)[idx2] ? idx1 : idx2;
    }
public:
    SegmentTree(vector<int> &heights):
        treeBuffer(heights.size() * 4),
        l(heights.size()),
        pHeights(&heights)
    {
        buildSegmentTree(heights, 0, heights.size() - 1, 0);
    }

    void buildSegmentTree(vector<int> &heights, int start, int end, int root)
    {
        if(start == end)
        {
            treeBuffer[root] = start;
            return;
        }

        int mid = (start + end) >> 1;
        buildSegmentTree(heights, start, mid, root * 2 + 1);
        buildSegmentTree(heights, mid + 1, end, root * 2 + 2);

        treeBuffer[root] = heights[treeBuffer[root * 2 + 1]] < heights[treeBuffer[root * 2 + 2]] ? treeBuffer[root * 2 + 1] : treeBuffer[root * 2 + 2];
    }

    int query(int start, int end)
    {
        return recurQuery(start, end, 0, l-1, 0);
    }
};

class Solution {
private:
    int subArea(vector<int> &heights, SegmentTree &segmentTree, int start, int end)
    {
        if(start > end)
            return 0;

        int minIdx = segmentTree.query(start, end);

        return max(heights[minIdx] * (end - start + 1), max(subArea(heights, segmentTree, start, minIdx - 1), subArea(heights, segmentTree, minIdx + 1, end)));
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        
        SegmentTree segmentTree(heights);
        return subArea(heights, segmentTree, 0, heights.size() - 1);
    }
};