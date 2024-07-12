class Solution {
public:
    // Time: O(n^2)
    string byStack(string s) {
        string ret;

        stack<int> stk;
        for (char c : s) {
            switch (c) {
            case '(':
                stk.push(ret.size());
                break;
            case ')':
                std::reverse(ret.begin() + stk.top(), ret.end());
                stk.pop();
                break;
            default:
                ret.push_back(c);
                break;
            }
        }

        return ret;
    }

    // Time: O(n)
    string byLinear(string s) {
        int n = s.size();

        vector<int> mapping(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
            case '(':
                stk.push(i);
                break;
            case ')':
                mapping[i] = stk.top();
                mapping[stk.top()] = i;
                stk.pop();
                break;
            default:
                break;
            }
        }

        string ret;
        for (int i = 0, dir = 1; i < n; i += dir) {
            switch (s[i]) {
            case '(':
            case ')':
                i = mapping[i];
                dir = -dir;
                break;
            default:
                ret.push_back(s[i]);
                break;
            }
        }

        return ret;
    }

    string reverseParentheses(string s) {
        //return byStack(s);
        return byLinear(s);
    }
};
