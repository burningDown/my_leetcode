/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        int mid;
        int g;
        while(i < j)
        {
            mid = i / 2 + j / 2;
            g = guess(mid);
            if(g == 0)
                return mid;
            else if(g == 1)
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return i;
    }
};