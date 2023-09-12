class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnts(26, 0);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        unordered_set<int> used;
        int ret = 0;
        for (int cnt : cnts) {
            for (int i = cnt; i >= 1 && used.insert(i).second == false; --i) {
                ++ret;
            }
        }

        return ret;
    }
};
