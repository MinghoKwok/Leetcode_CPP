class Solution {
public:
    bool isValid(string s) {
        list<char> stack;
        bool res = true;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            } else {
                if (stack.empty()) {
                    res = false;
                    break;
                }
                
                switch (c) {
                    case ')' :
                        if (stack.back() == '(')
                            stack.pop_back();
                        else 
                            res = false;
                        
                        break;
                        
                    case ']' :
                        if (stack.back() == '[')
                            stack.pop_back();
                        else 
                            res = false;
                        
                        break;
                        
                    case '}' :
                        if (stack.back() == '{')
                            stack.pop_back();
                        else 
                            res = false;
                        
                        break;
                        
                }
                
                
                if (!res)
                    break;
            }
        }
        
        if (!stack.empty()) {
            res = false;
        }
        
        return res;
    }
};