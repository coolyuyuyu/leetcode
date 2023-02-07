class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> flags(n + 1, true);
        for (int num : banned) {
            if (num < flags.size()) {
                flags[num] = false;
            }
        }

        int sum = 0;
        int cnt = 0;
        for (int i = 1; i < flags.size(); ++i) {
            if (flags[i] == false) {
                continue;
            }

            if (maxSum < (sum + i)) {
                return cnt;
            }
            sum += i;
            ++cnt;
        }

        return cnt;
    }
};
