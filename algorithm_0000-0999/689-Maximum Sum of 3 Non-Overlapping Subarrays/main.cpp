class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>& presums = nums;
        std::partial_sum(nums.begin(), nums.end(), presums.begin());
        std::function<int(int, int)> sum = [&](int l, int r) {
            return presums[r] - (l > 0 ? presums[l - 1] : 0);
        };

        // dpL[i]=(sum, idx): the maximal sum of legnth-k-subarrays from nums[0:i] and it's lft end index is idx.
        pair<int, int> dpL[n];
        for (int l = 0, r = k - 1, mx = INT_MIN, idx; r < n; ++l, ++r) {
            int s = sum(l, r);
            if (s > mx) {
                mx = s, idx = l;
            }
            dpL[r] = {mx, idx};
        }

        // dpR[i]=(sum, idx): the maximal sum of legnth-k-subarrays from nums[i:] and it's lft end index is idx.
        pair<int, int> dpR[n];
        for (int l = n - k, r = n - 1, mx = INT_MIN, idx; l >= 0; --l, --r) {
            int s = sum(l, r);
            if (s >= mx) {
                mx = s, idx = l;
            }
            dpR[l] = {mx, idx};
        }

        vector<int> ret;
        for (int l = k, r = k + k - 1, mx = INT_MIN; r + k < n; ++l, ++r) {
            int s = dpL[l - 1].first + sum(l, r) + dpR[r + 1].first;
            if (s > mx) {
                mx = s;
                ret = {dpL[l - 1].second, l, dpR[r + 1].second};
            }
        }

        return ret;
    }
};
