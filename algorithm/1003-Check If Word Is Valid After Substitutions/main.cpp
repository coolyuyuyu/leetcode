class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 3 != 0) {
            return false;
        }

        stack<char> stk;
        for (char c : s) {
            switch (c) {
                case 'a':
                    stk.push('a');
                    break;
                case 'b':
                    if (stk.empty() || stk.top() != 'a') {
                        return false;
                    }
                    else {
                        stk.pop();
                    }
                    stk.push('b');
                    break;
                case 'c':
                    if (stk.empty() || stk.top() != 'b') {
                        return false;
                    }
                    else {
                        stk.pop();
                    }
                    break;
            }
        }

        return stk.empty();
    }
};