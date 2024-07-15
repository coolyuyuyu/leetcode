class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ret = {"0", "1"};
        for (int i = 1; i < n; ++i) {
            vector<string> tmps = std::move(ret);
            for (const string& s : tmps) {
                if (s.back() == '0') {
                    ret.push_back(s + "1");
                }
                else {
                    ret.push_back(s + "0");
                    ret.push_back(s + "1");
                }
            }
        }

        return ret;
    }
};
