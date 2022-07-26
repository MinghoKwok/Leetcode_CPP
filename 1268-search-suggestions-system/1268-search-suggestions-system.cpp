class Solution {
    /*
    1. clarification
        constraints:
            products.length [1, 1000]
            products[i].length  <= 3000
            1 <= searchWord.length <= 1000
    
    2. Example
    
    3. Solution 
    a. assumption
        return null vector when no result
    
    b. input/output
        input: string array, string
    
    c. corner case:
        too many 
    
    d. algo:
        two pointers
    
    e. Complexity
        Time: nlogn
        Space:
    
    */
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        int pos = 0;
        int l = 0;
        int r = products.size() - 1;
        
        while (pos < searchWord.size()) {
            char cur = searchWord[pos];
            while (l < r && products[l][pos] != cur) {
                l++;
                if (l >= products.size())
                    break;
            } 
            while (l <= r && products[r][pos] != cur) {
                r--;
                if (r < 0)
                    break;
            }
            
            vector<string> vec;
            if (l <= r) {
                for (int i = l; i <= r && i - l <= 2; i++) {
                    vec.push_back(products[i]);
                }
            } else {
                
            }
            res.push_back(vec);
            
            pos++;
        }
        
        
        return res;
    }
};