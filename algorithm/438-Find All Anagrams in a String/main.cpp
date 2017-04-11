class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> counts(26, 0);
        for (auto c : p) {
            ++counts[c - 'a'];
        }

        size_t bgn = 0;
        size_t end = 0;
        vector<int> result;
        for (size_t i = 0; i < s.size(); ++i) {
            if ((end - bgn) == p.size()) {
                result.push_back(bgn);
                if (!p.empty()) {
                    ++counts[s[bgn] - 'a'];
                }
                ++bgn;
                end = max(bgn, end);
            }

            if (counts[s[i] - 'a']) {
                --counts[s[i] - 'a'];
                ++end;
            }
            else {
                bool found = false;
                for (size_t j = bgn; j < end; ++j) {
                    ++counts[s[j] - 'a'];
                    if (s[j] == s[i]) {
                        --counts[s[j] - 'a'];
                        bgn = j + 1;
                        ++end;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    bgn = i + 1;
                    end = max(bgn, end);
                }
            }
        }

        if ((end - bgn) == p.size()) {
            result.push_back(bgn);
        }

        return result;
    }
};