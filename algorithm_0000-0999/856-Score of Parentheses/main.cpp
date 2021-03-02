class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk({0});
        int tmp;
        for (char c : S) {
            switch(c) {
                case '(':
                    stk.push(0);
                    break;
                case ')':
                    tmp = stk.top();
                    stk.pop();
                    if (tmp == 0) {
                        stk.top() += 1;
                    }
                    else {
                        stk.top() += (2 * tmp);
                    }
                    break;
                default:
                    assert(false);
            }
        }

        return stk.top();
    }
};