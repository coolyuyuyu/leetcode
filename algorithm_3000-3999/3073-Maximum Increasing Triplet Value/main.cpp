class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        int rhtMax[n];
        rhtMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rhtMax[i] = std::max(rhtMax[i + 1], nums[i]);
        }

        int ret = INT_MIN;

        set<int> lfts = {nums[0]};
        for (int j = 1; j + 1 < n; ++j) {
            if (nums[j] < rhtMax[j + 1]) {
                auto itr = lfts.lower_bound(nums[j]);
                if (itr != lfts.begin()) {
                    itr = std::prev(itr);
                    ret = std::max(ret, *itr - nums[j] + rhtMax[j + 1]);
                }
            }

            lfts.insert(nums[j]);
        }

        return ret;
    }
};
