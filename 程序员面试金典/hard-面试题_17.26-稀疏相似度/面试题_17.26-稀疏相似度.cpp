class Solution {
private:
    string encodeExpression(int id1, int id2, double similarity)
    {
        static char buffer[100];
        if(int(similarity * 100000) % 10 >= 5)
            sprintf(buffer, "%d,%d: %.4f", id1, id2, similarity + 0.00001);
        else
            sprintf(buffer, "%d,%d: %.4f", id1, id2, similarity);
        return string(buffer);
    }
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        unordered_map<int, list<int>> elementToIdMap;
        unordered_map<int, unordered_map<int, int>> idToUnionMap;

        const int l = docs.size();

        int smaller, larger;

        vector<string> result;

        for(int i=0;i<l;i++)
        {
            for(int &ele : docs[i])
            {
                elementToIdMap[ele].push_back(i);

                for(auto it=elementToIdMap[ele].begin();it!=elementToIdMap[ele].end();++it)
                {
                    if(*it == i)
                        continue;
                    
                    smaller = *it < i ? *it : i;
                    larger = *it > i ? *it : i;

                    idToUnionMap[smaller][larger]++;
                }
            }
        }

        for(auto smallerIt=idToUnionMap.begin();smallerIt!=idToUnionMap.end();++smallerIt)
        {
            for(auto largerIt=smallerIt->second.begin();largerIt!=smallerIt->second.end();++largerIt)
            {
                result.push_back(encodeExpression(smallerIt->first, largerIt->first, double(largerIt->second) / double(docs[smallerIt->first].size() + docs[largerIt->first].size() - largerIt->second)));
            }
        }

        return result;
    }
};