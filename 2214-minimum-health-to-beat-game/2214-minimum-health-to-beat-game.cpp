class Solution {
    /*
    1. clarification
        if [3], 1   then ?   (if damage[i] > armor)
    
    */
    
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long res = 0;
        long long sum = accumulate(damage.begin(), damage.end(), 0L);
        int max_dmg = 0;
        for (int i = 0; i < damage.size(); i++) {
            max_dmg = max(max_dmg, damage[i]);
        }
        
        if (max_dmg > armor) {
            res = sum + 1 - armor;
        } else {
            res = sum + 1 - max_dmg;
        }
        
        return res;
    }
};