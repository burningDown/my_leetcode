class Solution {
private:
    void trackback(vector<string> &result, string &buffer, string &S, vector<bool> &visited)
    {
        if(buffer.size() == S.size())
        {
            result.push_back(buffer);
            return;
        }

        const int l = S.size();

        for(int i=0;i<l;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                buffer += S[i];
                trackback(result, buffer, S, visited);
                buffer.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<string> permutation(string S) {
        vector<string> result;
        string buffer;
        vector<bool> visited(S.size(), false);

        trackback(result, buffer, S, visited);

        return result;
    }
};