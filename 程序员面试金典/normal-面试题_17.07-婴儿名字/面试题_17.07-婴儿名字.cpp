struct DSUNode
{
    string name;
    DSUNode *next;
    DSUNode(string name0): name(name0), next(NULL){}
};

class Solution {
private:
    vector<string> splitSynonyms(const string &s)
    {
        const int l = s.size();
        int sp = -1;

        for(int i=1;i<l;i++)
        {
            if(s[i] == ',')
            {
                sp = i;
                break;
            }
        }

        return {s.substr(1, sp-1), s.substr(sp+1, l-sp-2)};
    }

    pair<string, int> splitFreq(const string &s)
    {
        const int l = s.size();
        int sp = -1;

        for(int i=1;i<l;i++)
        {
            if(s[i] == '(')
            {
                sp = i;
                break;
            }
        }

        return {s.substr(0, sp), atoi(s.substr(sp+1, l-sp-2).c_str())};
    }
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string, DSUNode*> nameMap;
        unordered_map<string, int> nameFreqMap;
        vector<string> splited;
        DSUNode *node0, *node1, *temp;
        vector<string> result;

        for(string &s : synonyms)
        {
            splited = splitSynonyms(s);

            if(nameMap.count(splited[0]) == 0)
                nameMap[splited[0]] = new DSUNode(splited[0]);
            if(nameMap.count(splited[1]) == 0)
                nameMap[splited[1]] = new DSUNode(splited[1]);

            for(node0 = nameMap[splited[0]];node0->next != NULL;node0 = node0->next)
                ;
            for(node1 = nameMap[splited[1]];node1->next != NULL;node1 = node1->next)
                ;
            if(node0->name < node1->name)
            {
                node1->next = node0;
                for(node1 = nameMap[splited[1]];node1->next != NULL;)
                {
                    temp = node1->next;
                    node1->next = node0;
                    node1 = temp;
                }
            }
            else if(node0->name > node1->name)
            {
                node0->next = node1;
                for(node0 = nameMap[splited[0]];node0->next != NULL;)
                {
                    temp = node0->next;
                    node0->next = node1;
                    node0 = temp;
                }
            }
        }

        for(string &s : names)
        {
            auto p = splitFreq(s);
            if(nameMap.count(p.first) == 0)
                nameMap[p.first] = new DSUNode(p.first);
            for(node0=nameMap[p.first];node0->next!=NULL;node0=node0->next)
                ;
            nameFreqMap[node0->name] += p.second;
        }

        for(auto it=nameFreqMap.begin();it!=nameFreqMap.end();it++)
        {
            result.push_back(it->first);
            result.back() += '(';
            result.back() += to_string(it->second);
            result.back() += ')';
        }
        return result;
    }
};