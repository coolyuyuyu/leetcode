class Solution {
public:
    bool mancraft(vector<string>& words, const string& order) {
        array<unsigned, 26> weights;
        for (int i = 0; i < 26; ++i) {
            weights[order[i] - 'a'] = i;
        }

        auto comp = [&](const string& s1, const string& s2) {
            auto itr1 = s1.begin(), itr2 = s2.begin();
            for (; itr1 != s1.end(); ++itr1, ++itr2) {
                if (itr2 == s2.end() || weights[*itr2 - 'a'] < weights[*itr1 - 'a']) {
                    return false;
                }
                else if (weights[*itr1 - 'a'] < weights[*itr2 - 'a']) {
                    return true;
                }
            }

            return itr2 != s2.end();
        };

        return std::is_sorted(words.begin(), words.end(), comp);
    }

    bool stdlib(vector<string>& words, const string& order) {
        array<unsigned char, 26> weights;
        for (unsigned char i = 0; i < 26; ++i) {
            weights[order[i] - 'a'] = i;
        }

        auto charComp = [&weights](char c1, char c2) {
            return weights[c1 - 'a'] < weights[c2 - 'a'];
        };
        auto wordComp = [&charComp](const string& s, const string& t) {
            return std::lexicographical_compare(s.begin(), s.end(), t.begin(), t.end(), charComp);
        };
        return std::is_sorted(words.begin(), words.end(), wordComp);
    }

    bool isAlienSorted(vector<string>& words, string order) {
        //return mancraft(words, order);
        return stdlib(words, order);
    }
};
