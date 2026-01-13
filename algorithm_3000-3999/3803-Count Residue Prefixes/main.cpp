class Solution {
public:
    int residuePrefixes(string s) {
        int ret = 0;

        unordered_set<char> ss;
        for (int len = 1; len <= s.size(); ++len) {
            ss.insert(s[len - 1]);
            if (ss.size() == len % 3) {
                ++ret;
            }
        }

        return ret;
    }
};
