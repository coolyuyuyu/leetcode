class Solution {
public:
    long long validSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> peaks;
        peaks.push_back(-1);
        for (int i = 1; i + 1 < n; ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                peaks.push_back(i);
            }
        }
        peaks.push_back(n);

        long long ret = 0;
        for (int i = 1; i + 1 < peaks.size(); ++i) {
            int pre = peaks[i - 1], cur = peaks[i], nxt = peaks[i + 1];
            int lftBound = std::max(cur - k, pre + 1), rhtBound = std::min(cur + k, nxt - 1);
            ret += 1LL * (cur - lftBound + 1) * (rhtBound - cur + 1);
        }

        return ret;
    }
};
