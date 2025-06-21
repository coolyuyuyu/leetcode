class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnts(26, 0);
        for (char c : word) {
            ++cnts[c - 'a'];
        }

        int ret = INT_MAX;
        for (int minFreq : cnts) {
            int x = 0;
            for (int freq : cnts) {
                x += (freq < minFreq ? freq: std::max(freq - minFreq - k, 0));
            }

            ret = std::min(ret, x);
        }

        return ret;
    }
};
