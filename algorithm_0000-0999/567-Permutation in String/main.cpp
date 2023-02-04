class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> cnts;
        for (auto c : s1) {
            ++cnts[c];
        }

        size_t x = cnts.size();
        for (size_t rht = 0; rht < s2.size(); ++rht) {
            if (--cnts[s2[rht]] == 0) {
                --x;
            }

            if (x == 0) {
                return true;
            }

            if (rht + 1 < s1.size()) {
                continue;
            }
            size_t lft = rht + 1 - s1.size();
            if (cnts[s2[lft]]++ == 0) {
                ++x;
            }
        }

        return false;
    }
};
