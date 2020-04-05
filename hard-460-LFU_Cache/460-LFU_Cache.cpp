struct StorageNode
{
    int key;
    int value;
    int freq;
    int pre;
    int next;
    StorageNode(): key(-1), value(-1), freq(0), pre(-1), next(-1){}
};

class LFUCache {
private:
    unordered_map<int, int> keyMap;
    unordered_map<int, int> freqMap;
    vector<StorageNode> storage;
    int size;
    int used;

    void moveTo(int to, int idx)
    {
        StorageNode &node = storage[idx];
        int &pre = to;

        storage[node.pre].next = node.next;
        storage[node.next].pre = node.pre;

        node.pre = pre;
        node.next = storage[pre].next;

        storage[node.pre].next = idx;
        storage[node.next].pre = idx;
    }

    void accumulateFreq(int idx)
    {
        StorageNode &node = storage[idx];

        if(freqMap[node.freq] == idx)
        {
            if(storage[node.pre].freq == node.freq)
                freqMap[node.freq] = node.pre;
            else
                freqMap.erase(node.freq);
        }
        else
        {
            int pre = freqMap[node.freq];
            moveTo(pre, idx);
        }

        node.freq++;
        
        if(freqMap.count(node.freq) > 0)
        {
            int pre = freqMap[node.freq];
            moveTo(pre, idx);
        };

        freqMap[node.freq] = idx;

    }

    void releaseNode(int idx)
    {
        StorageNode &node = storage[idx];

        keyMap.erase(node.key);
        if(freqMap[node.freq] == idx)
        {
            if(storage[node.pre].freq == node.freq)
                freqMap[node.freq] = node.pre;
            else
                freqMap.erase(node.freq);
        }

        storage[node.pre].next = node.next;
        storage[node.next].pre = node.pre;

    }

    void insertNode(int idx, int key, int value)
    {
        StorageNode &node = storage[idx];
        node.key = key;
        node.value = value;
        node.freq = 1;

        int pre = freqMap.count(1) == 0 ? 0 : freqMap[1];

        node.pre = pre;
        node.next = storage[pre].next;
        storage[storage[pre].next].pre = idx;
        storage[pre].next = idx;
        freqMap[1] = idx;

        keyMap[key] = idx;
    }

public:
    LFUCache(int capacity) {
        storage.resize(capacity + 2);
        size = capacity;
        used = 1;

        storage[0].next = size+1;
        storage[size+1].pre = 0;
    }
    
    int get(int key) {
        if(keyMap.count(key) == 0)
            return -1;
        
        int idx = keyMap[key];

        accumulateFreq(idx);
        return storage[idx].value;
    }
    
    void put(int key, int value) {
        if(size <= 0)
            return;
        
        if(keyMap.count(key) == 0)
        {
            if(used <= size)
            {
                insertNode(used, key, value);
                used++;
            }
            else
            {
                int idx = storage[0].next;
                releaseNode(idx);
                insertNode(idx, key, value);
            }
        }
        else
        {
            int idx = keyMap[key];
            storage[idx].value = value;
            accumulateFreq(idx);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */