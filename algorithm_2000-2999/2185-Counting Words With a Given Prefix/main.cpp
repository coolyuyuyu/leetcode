class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (const string& word : words) {
            if (word.size() < pref.size()) {
                continue;
            }
            if (word.compare(0, pref.size(), pref) == 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};
