class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<size_t> stk;
        for (size_t i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    stk.emplace_back(i);
                    break;
                case ')':
                    if (!stk.empty() && s[stk.back()] == '(') {
                        stk.pop_back();
                    }
                    else {
                        stk.emplace_back(i);
                    }
                    break;
                default:
                    break;
            }
        }

        string result;
        size_t parenthesesIndex = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (parenthesesIndex < stk.size() && i == stk[parenthesesIndex]) {
                ++parenthesesIndex;
            }
            else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};