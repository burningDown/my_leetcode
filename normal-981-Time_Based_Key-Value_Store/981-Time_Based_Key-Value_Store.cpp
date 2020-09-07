class TimeMap {
private:
    vector<pair<string, int>> storage;
    unordered_map<string, vector<int>> storageMap;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        storage.push_back({value, timestamp});
        storageMap[key].push_back(storage.size() - 1);
    }
    
    string get(string key, int timestamp) {
        if(storageMap.find(key) == storageMap.end())
            return "";
        
        auto &idxList = storageMap[key];
        const int l = idxList.size();
        int i = 0, j = l-1;
        while(i < j)
        {
            int mid = (i + j) / 2;
            if(storage[idxList[mid]].second == timestamp)
            {
                return storage[idxList[mid]].first;
            }
            else if(storage[idxList[mid]].second < timestamp)
            {
                if(storage[idxList[mid+1]].second > timestamp)
                    return storage[idxList[mid]].first;
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        return storage[idxList[i]].second <= timestamp ? storage[idxList[i]].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */