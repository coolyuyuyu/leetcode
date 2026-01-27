class Solution {
public:
    int minLengthAfterRemovals(string s) {
        string ret;
        for (char c : s) {
            if (!ret.empty() && ret.back() != c) {
                ret.pop_back();
            }
            else {
                ret.push_back(c);
            }
        }

        return ret.size();
    }
};
