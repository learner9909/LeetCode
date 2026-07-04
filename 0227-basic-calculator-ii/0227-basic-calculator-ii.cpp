#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long current = 0, last = 0, result = 0;
        char op = '+'; // previous operator
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                current = current * 10 + (c - '0');
            }
            
            if ((!isdigit(c) && !isspace(c)) || i == s.size() - 1) {
                if (op == '+') {
                    result += last;
                    last = current;
                } else if (op == '-') {
                    result += last;
                    last = -current;
                } else if (op == '*') {
                    last = last * current;
                } else if (op == '/') {
                    last = last / current;
                }
                op = c;
                current = 0;
            }
        }
        result += last;
        return result;
    }
};
