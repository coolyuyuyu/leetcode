class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> flips(n + 1, 0);
        for (int query : queries) {
            ++flips[query];
        }

        for (int i = 1; i <= n; ++i) {
            flips[i] += flips[i / 2];
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if (flips[i] % 2) {
                ++ret;
            }
        }

        return ret;
    }
};
