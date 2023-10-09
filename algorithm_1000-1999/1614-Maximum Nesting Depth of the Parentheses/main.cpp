class Solution {
public:
    int maxDepth(string s) {
        int ret = 0;

        int d = 0;
        for (char c : s) {
            if (c == '(') {
                ++d;
                ret = std::max(ret, d);
            }
            else if (c == ')') {
                --d;
            }
        }

        return ret;
    }
};
