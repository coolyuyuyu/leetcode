class Solution {
public:
    string sortString(string s) {
        map<char, int> cnts;
        for (char c : s) {
            ++cnts[c];
        }

        string ret;
        while (!cnts.empty()) {
            for (auto itr = cnts.begin(); itr != cnts.end();) {
                ret.push_back(itr->first);
                if (--itr->second == 0) {
                    itr = cnts.erase(itr);
                }
                else {
                    ++itr;
                }
            }
            for (auto itr = cnts.rbegin(); itr != cnts.rend();) {
                ret.push_back(itr->first);
                if (--itr->second == 0) {
                    itr = std::reverse_iterator(cnts.erase(std::next(itr).base()));
                }
                else {
                    ++itr;
                }
            }
        }

        return ret;
    }
};
