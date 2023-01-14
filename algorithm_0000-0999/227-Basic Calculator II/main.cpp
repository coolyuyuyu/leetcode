class Solution {
public:
    bool isop(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int calculate(string s) {
        int num = 0;
        int op = '+';
        stack<int> stk;
        for (size_t i = 0; i <= s.size(); ++i) {
            if (i == s.size() || isop(s[i])) {
                if (op == '+') {
                    stk.push(num);
                }
                else if (op == '-') {
                    stk.push(-num);
                }
                else if (op == '*') {
                    int n = stk.top();
                    stk.pop();
                    stk.push(n * num);
                }
                else {
                    int n = stk.top();
                    stk.pop();
                    stk.push(n / num);
                }

                num = 0;
                if (i < s.size()) {
                    op = s[i];
                }
            }
            else if (isdigit(s[i])) {
                num *= 10;
                num += (s[i] - '0');
            }
        }

        int ret = 0;
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }

        return ret;
    }
};
