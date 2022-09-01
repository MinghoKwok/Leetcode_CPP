class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        bool res = true;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) {
                    res = false;
                    break;
                }
                
                switch (c) {
                    case ')' :
                        if (stack.top() == '(')
                            stack.pop();
                        else 
                            res = false;
                        
                        break;
                        
                    case ']' :
                        if (stack.top() == '[')
                            stack.pop();
                        else 
                            res = false;
                        
                        break;
                        
                    case '}' :
                        if (stack.top() == '{')
                            stack.pop();
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