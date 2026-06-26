class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> dic;
    list<pair<int, int>> lru;

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        auto it = dic.find(key);

        if (it == dic.end()) {
            return -1;
        }

        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});

        dic.erase(it);
        dic[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        auto it = dic.find(key);

        if (dic.find(key) != dic.end()) {
            lru.erase(it->second);
            dic.erase(it);
        }

        lru.push_front({key, value});
        dic[key] = lru.begin();

        if (dic.size() > capacity) {
            auto it = dic.find(lru.rbegin()->first);
            dic.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
