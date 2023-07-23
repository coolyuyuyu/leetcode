class Solution {
public:
    string forward(const string& expression) {
        int n = expression.size();

        std::function<string(const string&)> eval = [](const string& expression) -> string {
            if (expression[0] == 'T') {
                return expression.substr(2, 1);
            }
            else {
                return expression.substr(4, 1);
            }
        };

        string token;
        stack<string> stk;
        for (int i = 0; i < n; ++i) {
            if ((i + 1) < n && expression[i + 1] == '?') {
                stk.push(std::move(token));
                token += expression[i];
            }
            else {
                token += expression[i];
                while (token.size() == 5) {
                    token = stk.top() + eval(token);
                    stk.pop();
                }
            }
        }

        return token;
    }

    string backward(const string& expression) {
        stack<char> stk;
        for (int i = expression.size(); 0 < i--;) {
            char c = expression[i];
            if (!stk.empty() && stk.top() == '?') {
                stk.pop(); // question mark
                char e1 = stk.top(); stk.pop();
                stk.pop(); // colon mark
                char e2 = stk.top(); stk.pop();
                stk.push(c == 'T' ? e1 : e2);
            }
            else {
                stk.push(c);
            }
        }

        return string(1, stk.top());
    }

    string parseTernary(string expression) {
        //return forward(expression);
        return backward(expression);
    }
};
