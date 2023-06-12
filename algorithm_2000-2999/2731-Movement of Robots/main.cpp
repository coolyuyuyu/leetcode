class Solution {
public:
    int M = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();

        vector<long long> positions(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                positions[i] = nums[i] - d;
            }
            else {
                positions[i] = nums[i] + d;
            }
        }

        std::sort(positions.begin(), positions.end());

        int ret = 0;
        for (int i = 1; i < n; ++i) {
            long long tmp = (positions[i] - positions[i - 1]) % M;
            tmp *= (i);
            tmp %= M;
            tmp *= (n - i);
            tmp %= M;

            ret += tmp;
            ret %= M;
        }

        return ret;
    }
};
