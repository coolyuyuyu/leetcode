class Solution {
public:
    int maxDistance(vector<string>& words) {
        int n = words.size();

        int ret = 0;
        for (int i = 1; i < n; ++i) {
            if (words[0] != words[i]) {
                ret = std::max(ret, i - 0 + 1);
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (words[i] != words[n - 1]) {
                ret = std::max(ret, n - 1 - i + 1);
            }
        }

        return ret;
    }
};
