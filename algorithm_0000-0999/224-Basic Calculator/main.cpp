class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int sign = 1;
        int ret = 0;
        stack<int> stk;
        for (size_t i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                num *= 10;
                num += (s[i] - '0');
            }
            else if (s[i] == '+') {
                ret += (num * sign);
                num = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                ret += (num * sign);
                num = 0;
                sign = -1;
            }
            else if (s[i] == '(') {
                stk.push(ret);
                stk.push(sign);
                ret = 0;
                sign = 1;
            }
            else if (s[i] == ')'){
                ret += (num * sign);
                ret *= stk.top();
                stk.pop();
                ret += stk.top();
                stk.pop();
                num = 0;
            }
        }

        return ret + num*sign;
    }
};
