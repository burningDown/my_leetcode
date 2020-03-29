class Solution {
private:
    int deckMap[10010];
    int gcd(int a, int b)
    {
        while(b^=a^=b^=a%=b);
        return a;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        const int l = deck.size();
        int X;
        for(int i : deck)
            X = ++deckMap[i];

        for(int i=0;i<10010;i++)
        {
            if(deckMap[i])
                X = gcd(X, deckMap[i]);
        }

        return X >= 2;
    }
};