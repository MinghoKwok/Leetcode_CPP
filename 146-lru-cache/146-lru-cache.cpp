class LRUCache {
    // https://leetcode.com/problems/lru-cache/discuss/792449/Simple-C%2B%2B-Solution-with-Detailed-Explanation-%3A-
    
private:
    list<pair<int, int>> used;  // (key, val)
    unordered_map<int, list<pair<int, int>>:: iterator> cache;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            used.splice(used.begin(), used, cache[key]);
            return cache[key]->second;
        }
        
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        if (iter == cache.end()) {  // not exist
            if (used.size() >= this->capacity) {
                // erase
                int pop_key = used.back().first;    // pair.first, Not used.back()->first
                used.pop_back();
                cache.erase(cache.find(pop_key));
            } 
            
            // insert
            used.insert(used.begin(), pair<int, int>(key, value));
            cache.insert(pair<int, list<pair<int, int>>:: iterator>(key, used.begin()));
            
        } else {    // exist
            cache[key]->second = value;
            used.splice(used.begin(), used, cache[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */