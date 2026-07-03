class Solution {
public:
    string processStr(string s) {
        string ret;
        for (char c : s) {
            switch (c) {
                case '*':
                    if (!ret.empty()) {
                        ret.pop_back();
                    }
                    break;
                case '#':
                    ret += ret;
                    break;
                case '%':
                    std::reverse(ret.begin(), ret.end());
                    break;
                default:
                    ret += c;
                    break;
            }
        }

        return ret;
    }
};
