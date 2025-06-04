class Solution {
public:
    string resultingString(string s) {
        string ret;
        for (char c : s) {
            if (!ret.empty() && (std::abs(c - ret.back()) == 1 || std::abs(c - ret.back()) == 25)) {
                ret.pop_back();
            }
            else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};
