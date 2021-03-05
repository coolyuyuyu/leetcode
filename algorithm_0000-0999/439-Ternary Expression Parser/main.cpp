class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        for (size_t i = expression.size(); 0 < i--;) {
            char c = expression[i];
            if ((c == 'T' || c == 'F') && !stk.empty() && stk.top() == '?') {
                stk.pop();
                char a = stk.top();
                stk.pop();

                stk.pop();
                char b = stk.top();
                stk.pop();

                stk.push(c == 'T' ? a : b);
            }
            else {
                stk.push(c);
            }
        }

        return string(1, stk.top());
    }
};