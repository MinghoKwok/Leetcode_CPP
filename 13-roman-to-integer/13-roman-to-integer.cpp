class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int res = 0;
        int pos = 0;
        while (pos < s.size()) {
            if (pos + 1 < s.size()) {
                if (s[pos] == 'I') {
                    if (s[pos + 1] == 'V') {
                        res += 4;
                        pos += 2;
                        continue;
                    }
                    if (s[pos + 1] == 'X') {
                        res += 9;
                        pos += 2;
                        continue;
                    }
                } else if (s[pos] == 'X') {
                    if (s[pos + 1] == 'L') {
                        res += 40;
                        pos += 2;
                        continue;
                    }
                    if (s[pos + 1] == 'C') {
                        res += 90;
                        pos += 2;
                        continue;
                    }
                } else if (s[pos] == 'C') {
                    if (s[pos + 1] == 'D') {
                        res += 400;
                        pos += 2;
                        continue;
                    }
                    if (s[pos + 1] == 'M') {
                        res += 900;
                        pos += 2;
                        continue;
                    }
                }
            }
            
            res += mp[s[pos]];
            pos++;
        }
        
        return res;
        
    }
};