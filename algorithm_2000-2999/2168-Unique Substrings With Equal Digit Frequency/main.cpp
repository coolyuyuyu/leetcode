class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();

        std::array<int, 10> cnts;
        unordered_set<unsigned long long> hashs;
        for (int i = 0, n = s.size(); i < n; ++i) {
            cnts.fill(0);
            unsigned long long hash = 0;
            for (int j = i; j < n; ++j) {
                ++cnts[s[j] - '0'];
                hash = hash * 11 + (s[j] - '0' + 1);

                bool same = true;
                for (int k = 0, cnt = -1; k < cnts.size() && same; ++k) {
                    if (cnts[k] == 0) { continue; }
                    if (cnt == -1) { cnt = cnts[k]; }
                    else if (cnt != cnts[k]) { same = false; }
                }

                if (same) {
                    hashs.insert(hash);
                }
            }
        }

        return hashs.size();
    }
};
