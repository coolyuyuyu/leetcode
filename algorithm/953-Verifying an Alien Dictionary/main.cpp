class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<unsigned char> indexes(26);
        for (unsigned char i = 0; i < 26; ++i) {
            indexes[order[i] - 'a'] = i;
        }

        auto comp = [&](const string& lft, const string& rht) {
            for (auto itrLft = lft.cbegin(), itrRht = rht.cbegin(); itrLft != lft.cend() && itrRht != rht.cend(); ++itrLft, ++itrRht) {
                unsigned char indexLft = indexes[*itrLft - 'a'];
                unsigned char indexRht = indexes[*itrRht - 'a'];
                if (indexLft < indexRht) {
                    return true;
                }
                else if (indexRht < indexLft){
                    return false;
                }
            }

            return lft.size() < rht.size();
        };

        return is_sorted(words.begin(), words.end(), comp);
    }
};