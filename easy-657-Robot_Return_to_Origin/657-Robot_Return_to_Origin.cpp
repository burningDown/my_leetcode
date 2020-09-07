class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char &s : moves)
        {
            switch(s)
            {
                case 'R':
                    x++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
};