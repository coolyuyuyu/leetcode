class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        result.reserve(S.size());

        int count = 0;
        for (auto c : S) {
            if (c == '(') {
                if (++count != 1) {
                    result.push_back(c);
                }
            }
            else {
                if (--count != 0) {
                    result.push_back(c);
                }
            }
        }

        return result;
    }
};