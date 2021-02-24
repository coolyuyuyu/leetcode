class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    stk.emplace(c);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(') {
                        return false;
                    }
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') {
                        return false;
                    }
                    stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') {
                        return false;
                    }
                    stk.pop();
                    break;
                default:
                    assert(false);
            }
        }

        return stk.empty();
    }
};