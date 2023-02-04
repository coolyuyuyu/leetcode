class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> cnts;
        for (auto c : s1) {
            ++cnts[c];
        }

        size_t x = cnts.size();
        for (size_t i = 0; i < s2.size(); ++i) {
            if (--cnts[s2[i]] == 0) {
                --x;
            }

            if (x == 0) {
                return true;
            }

            if (s1.size() <= (i + 1)) {
                if (cnts[s2[i + 1 - s1.size()]]++ == 0) {
                    ++x;
                }
            }
        }

        return false;
    }
};
