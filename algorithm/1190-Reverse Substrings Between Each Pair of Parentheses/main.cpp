class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");

        string s1, s2;
        for (char c : s) {
            switch (c) {
            case '(':
                stk.push("");
                break;
            case ')':
                s1 = stk.top();
                stk.pop();
                s2 = stk.top();
                stk.pop();

                reverse(s1.begin(), s1.end());
                s2 += s1;
                stk.push(s2);
                break;
            default:
                string s1 = stk.top();
                stk.pop();

                s1 += c;
                stk.push(s1);
                break;
            }
        }

        return stk.top();
    }
};