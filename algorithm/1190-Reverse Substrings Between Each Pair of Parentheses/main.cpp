class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");

        string tmp;
        for (char c : s) {
            switch (c) {
            case '(':
                stk.push("");
                break;
            case ')':
                tmp = stk.top();
                stk.pop();

                reverse(tmp.begin(), tmp.end());
                stk.top() += tmp;
                break;
            default:
                stk.top() += c;
                break;
            }
        }

        return stk.top();
    }
};