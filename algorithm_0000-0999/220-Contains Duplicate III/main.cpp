class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            if (i > indexDiff) {
                ms.erase(ms.find(nums[i - indexDiff - 1]));
            }

            auto itr = ms.lower_bound(nums[i] - valueDiff);
            if (itr != ms.end() && abs(nums[i] - *itr) <= valueDiff) {
                return true;
            }

            ms.insert(nums[i]);
        }

        return false;
    }
};
