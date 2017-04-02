class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            char c = *iter;
            switch (c) {
            case '(':
            case '{':
            case '[':
                brackets.push(c);
                break;
            case ')':
                if (brackets.empty() || brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case '}':
                if (brackets.empty() || brackets.top() != '{')
                    return false;
                brackets.pop();
                break;
            case ']':
                if (brackets.empty() || brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
            default:
                break;
            }
        }
        return brackets.empty();
    }
};