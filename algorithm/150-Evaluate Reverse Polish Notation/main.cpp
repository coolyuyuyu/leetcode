class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (size_t i = 0; i < tokens.size(); ++i) {
            const string& token = tokens[i];
            if (token == "+") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a + b);
            }
            else if (token == "-") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a - b);
            }
            else if (token == "*") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a * b);
            }
            else if (token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a / b);
            }
            else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};