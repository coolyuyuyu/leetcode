class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ret = {"a"};
        while (ret.back() != target) {
            string s = ret.back();
            if (s.back() != target[s.size() - 1]) {
                s.back() += 1;
            }
            else {
                s += "a";
            }
            ret.push_back(s);
        }

        return ret;
    }
};
