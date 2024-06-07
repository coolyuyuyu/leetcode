class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnts(26, 0);
        for (char c : word) {
            ++cnts[c - 'a'];
        }

        int ret = INT_MAX;
        unordered_set<int> minCnts(cnts.begin(), cnts.end());
        for (int minCnt : minCnts) {
            int x = 0;
            for (int cnt : cnts) {
                x += cnt < minCnt ? cnt : std::max(0, (cnt - minCnt - k));
            }
            ret = std::min(ret, x);
        }

        return ret;
    }
};
