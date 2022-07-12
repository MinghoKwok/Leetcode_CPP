class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        //string cur_srch = "";
        int len = searchWord.size();
        int left = 0;
        int right = products.size() - 1;
        
        for (int i = 0; i < len; i++) {
            char c = searchWord[i];
            while (left < right && products[left][i] != c) {
                left++;
            }
            while (left <= right && products[right][i] != c) {
                right--;
            }
            
            vector<string> vec;
            //cout << left << endl;
            for (int j = left; j < left + 3; j++) {
                if (j > right)
                    break;
                
                vec.push_back(products[j]);
            }
            res.push_back(vec);
        }
        
        
    
        return res;
    }
};