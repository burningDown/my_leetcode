class Solution {
private:
    bool edit(string &first, int f, string &second, int s, bool edited)
    {
        const int lf = first.size();
        const int ls = second.size();

        while(f < lf && s < ls)
        {
            if(first[f] == second[s])
            {
                f++;
                s++;
            }
            else if(!edited)
            {
                return edit(first, f+1, second, s, true) || edit(first, f, second, s+1, true) || edit(first, f+1, second, s+1, true);
            }
            else
                return false;
        }
        return edited ? f >= lf && s >= ls : edit(first, f+1, second, s, true) || edit(first, f, second, s+1, true) || edit(first, f+1, second, s+1, true);
    }
public:
    bool oneEditAway(string first, string second) {
        return edit(first, 0, second, 0, false);
    }
};