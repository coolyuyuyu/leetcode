class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;
        for (char c : s) {
            if (ret.empty() || ret.back().size() == k) {
                ret.emplace_back();
            }
            ret.back().push_back(c);
        }

        if (!ret.empty()) {
            while (ret.back().size() < k) {
                ret.back().push_back(fill);
            }
        }

        return ret;
    }
};
