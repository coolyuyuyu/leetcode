class Solution {
public:
    int minOperations(string s) {
        if (std::is_sorted(s.begin(), s.end())) { return 0; }
        if (s.size() == 2) { return -1; }

        auto p = std::minmax_element(std::next(s.begin()), std::prev(s.end()));
        char mn = *p.first, mx = *p.second;
        if ((s.front() <= mn || mx <= s.back()) && s.front() <= s.back()) {
            return 1;
        }
        else {
            return s.front() > mx && mn < s.back() ? 1 : 2;
        }
    }
};
