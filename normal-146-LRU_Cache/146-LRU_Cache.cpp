struct BiListNode
{
    int key;
    int value;
    BiListNode *pre;
    BiListNode *next;
    BiListNode(int k, int v): key(k), value(v), pre(NULL), next(NULL) {}
};
class BiList
{
private:
    BiListNode virtualHead;
    BiListNode *endNode;
    int length;
public:
    BiList(): virtualHead(0, 0), length(0) {endNode = &virtualHead;}
    int size()
    {
        return length;
    }
    void push_back(int key, int value)
    {
        BiListNode *newNode = new BiListNode(key, value);
        endNode->next = newNode;
        newNode->pre = endNode;
        endNode = newNode;
        length++;
    }
    void pop_front()
    {
        if(virtualHead.next != NULL)
        {
            BiListNode *temp = virtualHead.next;
            virtualHead.next = temp->next;
            if(temp != endNode)
                temp->next->pre = &virtualHead;
            else
                endNode = &virtualHead;

            length--;
            delete temp;
        }
    }
    BiListNode *front()
    {
        return virtualHead.next;
    }
    BiListNode *end()
    {
        return endNode;
    }
    void erase(BiListNode *pNode)
    {
        pNode->pre->next = pNode->next;
        if(pNode != endNode)
            pNode->next->pre = pNode->pre;
        else
            endNode = pNode->pre;
        
        length--;
        delete pNode;
    }
};

class LRUCache {
private:
    BiList buffer;
    unordered_map<int, BiListNode*> cacheMap;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        
        auto it = cacheMap[key];
        int value = it->value;
        buffer.push_back(key, value);
        buffer.erase(it);
        cacheMap[key] = buffer.end();
        
        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end())
        {
            if(buffer.size() >= capacity)
            {
                cacheMap.erase(buffer.front()->key);
                buffer.pop_front();
            }
            buffer.push_back(key, value);
            cacheMap[key] = buffer.end();
        }
        else
        {
            auto it = cacheMap[key];
            buffer.erase(it);
            buffer.push_back(key, value);
            cacheMap[key] = buffer.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */