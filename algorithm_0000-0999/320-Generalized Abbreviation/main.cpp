class Solution {
public:
    vector<string> recursive(string word) {
        int n = word.size();

        string abbr;
        vector<string> ret;
        std::function<void(int)> f = [&](int start) {
            if (start >= n) {
                ret.push_back(abbr);
                return;
            }

            abbr += word[start];
            f(start + 1);
            abbr.pop_back();

            if (abbr.empty() || !std::isdigit(abbr.back())) {
                for (int i = start; i < n; ++i) {
                    string substr = std::to_string(i - start + 1);
                    abbr += substr;
                    f(i + 1);
                    abbr.resize(abbr.size() - substr.size());
                }
            }
        };
        f(0);

        return ret;
    }

    vector<string> iterative(string word) {
        int n = word.size();

        vector<string> ret;
        for (int state = 0; state < (1 << n); ++state) {
            string abbr;
            for (int i = 0; i < n;) {
                if ((state >> i) & 1) {
                    int j = i + 1;
                    for (; j < n && (state >> j) & 1; ++j)
                        ;
                    abbr += std::to_string(j - i);
                    i = j;
                }
                else {
                    abbr.push_back(word[i++]);
                }
            }
            ret.push_back(abbr);
        }

        return ret;
    }

    vector<string> generateAbbreviations(string word) {
        //return recursive(word);
        return iterative(word);
    }
};
