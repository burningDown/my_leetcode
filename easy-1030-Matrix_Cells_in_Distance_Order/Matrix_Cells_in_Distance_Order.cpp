class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> list(R*C, vector<int>(2));
        int v = 0;
        int r,c;
        int l = (R > C ? R : C) * 2;
        list[v][0] = r0;
        list[v][1] = c0;
        v++;
        for(int d=1;d <= l;d++)
        {
            for(r=r0-d,c=c0;r<=r0;r++,c++)
            {
                if(r>=0&&r<R&&c>=0&&c<C)
                {
                    list[v][0] = r;
                    list[v][1] = c;
                    v++;
                }
                if(r!=r0&&c!=c0&&2*r0 - r>=0&&2*r0 - r<R&&c>=0&&c<C)
                {
                    list[v][0] = 2*r0 - r;
                    list[v][1] = c;
                    v++;
                }
                if(2*r0 - r>=0&&2*r0 - r<R&&2*c0 - c>=0&&2*c0 - c<C)
                {
                    list[v][0] = 2*r0 - r;
                    list[v][1] = 2*c0 - c;
                    v++;
                }
                if(r!=r0&&c!=c0&&r>=0&&r<R&&2*c0 - c>=0&&2*c0 - c<C)
                {
                    list[v][0] = r;
                    list[v][1] = 2*c0 - c;
                    v++;
                }
            }
        }
        return list;
    }
};