class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        char relationMap[26] = {0};
        const int l = A.size();
        const int l2 = S.size();
        string result(l2, 0);
        char c1, c2, node1, node2, tempNode;
        for(int i=0;i<l;i++)
        {
            c1 = A[i];
            c2 = B[i];
            if(c1 == c2)
                continue;
            
            for(node1 = c1;relationMap[node1 - 'a'] != 0 && relationMap[node1 - 'a'] != node1;node1 = relationMap[node1 - 'a'])
                ;
            for(node2 = c2;relationMap[node2 - 'a'] != 0 && relationMap[node2 - 'a'] != node2;node2 = relationMap[node2 - 'a'])
                ;
            if(node1 < node2)
            {
                relationMap[node2 - 'a'] = node1;
                relationMap[c2 - 'a'] = node1;
                relationMap[c1 - 'a'] = node1;
            }
            else if(node1 > node2)
            {
                relationMap[node1 - 'a'] = node2;
                relationMap[c2 - 'a'] = node2;
                relationMap[c1 - 'a'] = node2;
            }
        }

        for(int i=0;i<l2;i++)
        {
            c1 = S[i];
            for(node1 = c1;relationMap[node1 - 'a'] != 0 && relationMap[node1 - 'a'] != node1;node1 = relationMap[node1 - 'a'])
                ;
            result[i] = node1;
        }
        return result;
    }
};