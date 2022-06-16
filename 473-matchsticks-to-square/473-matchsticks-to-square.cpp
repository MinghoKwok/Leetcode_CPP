class Solution {
    int sum;
public:
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides(4, 0);
        for (int i : matchsticks) {
            sum += i;
        }
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        if (sum % 4 != 0) 
            return false;
        
        return backtrack(0, matchsticks, sides);
    }
    
    bool backtrack(int start, vector<int>& sticks, vector<int>& sides) {
        if (start == sticks.size()) {
            if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
                return true;
            
            return false;
        }
        
        int count_0 = 0;
        for (int i = 0 ; i < 4; i++) {
            if (sides[i] == 0)
                count_0++;
            if (sides[i] > sum / 4)
                return false;
        }
        if (count_0 > sticks.size() - start)
            return false;
        
        bool check_zero = false;
        for (int i = 0; i < 4; i++) {
            if (sides[i] == 0) {
                if (check_zero)
                    return false;
                else 
                    check_zero = true;
            }
            
            sides[i] += sticks[start];
            if (backtrack(start + 1, sticks, sides))
                return true;
            sides[i] -= sticks[start];
        }
        
        return false;
    }
    
    
};