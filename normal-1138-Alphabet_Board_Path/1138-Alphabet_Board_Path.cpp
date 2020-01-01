class Solution {
private:
    char pathBuf[1000];
    int p;
public:
    Solution(): p(0), pathBuf({0}){}
    string alphabetBoardPath(string target) {
        int currentI = 0, currentJ = 0;
        int nextI = 0, nextJ = 0;
        int _i, _j;
        for(char x:target)
        {
            x -= 'a';
            nextI = x/5;
            nextJ = x%5;

            if(x==25 && currentJ>0)
                nextI-=1;
            if(currentJ==0 && currentI==5 && nextJ>0)
            {
                pathBuf[p++] = 'U';
                currentI-=1;
            }
            if(nextI-currentI>0)
                for(_i=0;_i<nextI-currentI;_i++)
                    pathBuf[p++] = 'D';
            else if(nextI-currentI<0)
                for(_j=0;_j<currentI-nextI;_j++)
                    pathBuf[p++] = 'U';
            
            if(nextJ-currentJ>0)
                for(_j=0;_j<nextJ-currentJ;_j++)
                    pathBuf[p++] = 'R';
            else if(nextJ-currentJ<0)
                for(_j=0;_j<currentJ-nextJ;_j++)
                    pathBuf[p++] = 'L';
            
            if(x==25 && currentJ>0)
                pathBuf[p++] = 'D';

            pathBuf[p++] = '!';
            currentI = x/5;
            currentJ = x%5;
        }
        return string(pathBuf);
    }
};