class LRUCache {
public:
    // Doubly Linked List(DLL) for ordering nodes as per LRU
    list<pair<int, int>> lruList;
    // Hash map for mapping keys to the nodes in DLL
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key)==cacheMap.end()) return -1;
        // Put the recently used key node at start of list
        lruList.splice(lruList.begin(), lruList, cacheMap[key]);
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
        // If key exists, then update it's value and order in list
        if (cacheMap.find(key) != cacheMap.end()) {
            lruList.splice(lruList.begin(), lruList, cacheMap[key]);
            lruList.begin()->second = value;
            return;
        }
        
        // If capacity is reached, then delete LRU
        if (lruList.size() == size) {
            cacheMap.erase(lruList.back().first);
            lruList.pop_back();
        }
        
        // Insert new key-value pair in the map & DLL
        lruList.emplace_front(make_pair(key, value));
        cacheMap[key] = lruList.begin();
    }
};