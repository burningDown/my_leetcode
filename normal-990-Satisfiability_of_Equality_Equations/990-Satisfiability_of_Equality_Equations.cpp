class DSU
{
private:
    char variableMap[26];
public:
    DSU()
    {
        memset(variableMap, -1, 26 * sizeof(char));
    }

    char findAndCompress(char c)
    {
        char res = c;
        while(variableMap[res-'a'] >= 0)
            res = variableMap[res-'a'];
        if(variableMap[c-'a'] >= 0)
            variableMap[c-'a'] = res;
        return res;
    }

    void mergeAndCompress(char a, char b)
    {
        char rootOfA = findAndCompress(a);
        char rootOfB = findAndCompress(b);

        if(rootOfA != rootOfB)
        {
            variableMap[rootOfA-'a'] = rootOfB;
            variableMap[a-'a'] = rootOfB;
        }
    }

    bool checkAndCompress(char a, char b)
    {
        char rootOfA = findAndCompress(a);
        char rootOfB = findAndCompress(b);

        return rootOfA == -1 && rootOfB == -1 || rootOfA != rootOfB;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu;

        for(string &s : equations)
            if(s[1] == '=')
                dsu.mergeAndCompress(s[0], s[3]);
        
        for(string &s : equations)
            if(s[1] == '!')
                if(!dsu.checkAndCompress(s[0], s[3]))
                    return false;
        
        return true;
    }
};