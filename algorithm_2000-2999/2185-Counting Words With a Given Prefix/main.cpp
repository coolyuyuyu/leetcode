class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for (const string& word : words) {
            if (word.compare(0, pref.size(), pref) == 0) {
                ++ret;
            }
        }

        return ret;
    }
};
