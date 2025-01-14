class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if (dictionary.empty()) {
            return to_string(target.size());
        }

        int n = target.size();

        {
            unordered_set<string> ss;
            for (const string& word : dictionary) {
                if (word.size() != n) {
                    continue;
                }
                ss.insert(word);
            }
            dictionary.clear();
            for (const string& word : ss) {
                dictionary.push_back(word);
            }
        }

        std::function<int(int)> computeLen = [&](int state) {
            int len = 0;
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    int j = i;
                    while (j < n && ((state >> j) & 1)) {
                        ++j;
                    }
                    i = j - 1;
                }
                ++len;
            }
            return len;
        };

        std::function<string(const string&, int)> abbrivate = [&](const string& s, int state) {
            string ret;
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1) {
                    int j = i;
                    while (j < n && ((state >> j) & 1)) {
                        ++j;
                    }
                    ret += std::to_string(j - i);
                    i = j - 1;
                }
                else {
                    ret += s[i];
                }
            }
            return ret;
        };

        int mask = 0;
        for (const string& w : dictionary) {
            int word = 0;
            if (w.size() != n) continue;
            for (int i = n-1, bit = 1; i >= 0; --i, bit <<= 1)
                if (target[i] != w[i]) word += bit;
            mask |= word;
        }

        map<int, vector<int>> len2masks;
        for (int s = 1; s < (1 << n); ++s) {
            len2masks[computeLen(s)].push_back(s);
        }

        for (const auto& [_, masks]: len2masks) {
            for (int mask : masks) {
                string ret = abbrivate(target, mask);
                bool found = false;
                for (const string& word : dictionary) {
                    if (abbrivate(word, mask) == ret) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    return ret;
                }
            }
        }

        return target;
    }
};
