class RandomizedSet {
private:
    map<int, bool> mp;
    
public:
    RandomizedSet() {
        mp.erase(mp.begin(), mp.end());
    }
    
    bool insert(int val) {
        if (mp[val] == false) {
            mp[val] = true;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (mp[val] == true) {
            mp[val] = false;
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        bool getTrue = false;
        int res;
        int len = mp.size();
        while (!getTrue) {
            auto it = mp.begin();
            int step = rand() % len;
            advance(it, step);
            if (it->second) {
                getTrue = true;
                res = it->first;
            } 
        }
        
        return res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */