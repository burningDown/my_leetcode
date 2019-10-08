class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        unordered_map<string, int>::iterator it;
        vector<string> topk(k, "");
        int l = words.size();
        int top, topf;
        string tops;
        for(int i=0;i<l;i++)
        {
            if((it = m.find(words[i])) != m.end())
                it->second+=1;
            else
                m.insert(make_pair(words[i], 1));
        }
        top=0;
        tops="";
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second>=top)
            {
                if(it->second>top||it->first<tops)
                {
                    top = it->second;
                    tops = it->first;
                }
            }
        }
        topk[0] = tops;
        topf = top;
        for(int i=1;i<k;i++)
        {
            top=0;
            tops="";
            for(it=m.begin();it!=m.end();it++)
            {
                if(it->second>=top&&it->second<=topf)
                {
                    if((it->second>top||it->second==top&&it->first<tops)&&(it->second<topf||it->second==topf&&it->first>topk[i-1]))
                    {
                        top = it->second;
                        tops = it->first;
                    }
                }
            }
            topk[i] = tops;
            topf = top;
        }
        return topk;
    }
};