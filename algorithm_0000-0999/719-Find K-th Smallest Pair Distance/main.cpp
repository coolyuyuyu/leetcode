class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int lo = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            lo = std::min(lo, nums[i] - nums[i - 1]);
        }
        int hi = nums.back() - nums.front();

        std::function<int(int)> cntPairsDistLE = [&](int target) {
            int n = nums.size();
            int ret = 0;
            for (int i = 0; i < n; ++i) {
                auto itr = std::upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + target);
                ret += std::distance(nums.begin() + i + 1, itr);
            }

            return ret;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (cntPairsDistLE(mid) < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }


        return lo;
    }
};
