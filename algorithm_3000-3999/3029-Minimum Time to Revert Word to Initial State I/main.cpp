class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        for (int ret = 1; ret * k < n; ++ret) {
            int len = n - ret * k;
            if (word.compare(0, len, word, n - len, len) == 0) {
                return ret;
            }
        }

        return (n + k - 1) / k;
    }
};
