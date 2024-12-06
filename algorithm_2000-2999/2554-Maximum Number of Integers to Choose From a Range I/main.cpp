class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> flags(n + 1, false);
        for (int num : banned) {
            if (num > n) { continue; }
            flags[num] = true;
        }

        int ret = 0;
        for (int i = 1, sum = 0; i <= n; ++i) {
            if (flags[i]) { continue; }
            if (sum + i > maxSum) { break; }
            ++ret;
            sum += i;
        }

        return ret;
    }
};
