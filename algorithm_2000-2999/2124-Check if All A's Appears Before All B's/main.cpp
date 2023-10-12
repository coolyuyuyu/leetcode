class Solution {
public:
    bool checkString(string s) {
        return std::is_sorted(s.begin(), s.end());
    }
};
