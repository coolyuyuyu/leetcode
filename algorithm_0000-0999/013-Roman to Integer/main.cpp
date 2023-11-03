class Solution {
public:
    int romanToInt(string s) {
        std::function<int(char)> c2n = [](char c) {
            switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
            }
        };

        int ret = 0;
        for (size_t i = s.size(), nxt = 0; 0 < i--;) {
            int cur = c2n(s[i]);
            ret += (cur >= nxt ? cur : -cur);
            nxt = cur;
        }

        return ret;
    }
};
