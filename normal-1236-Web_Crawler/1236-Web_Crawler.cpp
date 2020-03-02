/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    string rootHostName;
    string hostNameParser(string &url)
    {
        const int l = url.size();
        int i;
        for(i=7;i<l;i++)
        {
            if(url[i] == '/')
                break;
        }
        return url.substr(7, i-7);
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        this->rootHostName = hostNameParser(startUrl);
        queue<string> urlQueue;
        unordered_set<string> urlSet;
        vector<string> result;

        urlQueue.push(startUrl);
        urlSet.insert(startUrl);
        while(!urlQueue.empty())
        {
            string &curl = urlQueue.front();
            result.push_back(curl);
            for(string &url : htmlParser.getUrls(curl))
                if(urlSet.find(url) == urlSet.end() && hostNameParser(url) == rootHostName)
                {
                    urlQueue.push(url);
                    urlSet.insert(url);
                }

            urlQueue.pop();
        }

        return result;
    }
};