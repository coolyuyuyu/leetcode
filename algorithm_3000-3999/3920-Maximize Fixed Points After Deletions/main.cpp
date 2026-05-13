class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<pair<int, int>> pairs;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] >= 0 && nums[i] <= i) {
                pairs.emplace_back(i - nums[i], nums[i]);
            }
        }
        std::sort(pairs.begin(), pairs.end());

        vector<int> lis; // longest increasing subsequence
        for (const auto& [_, num] : pairs) {
            auto itr = std::lower_bound(lis.begin(), lis.end(), num);
            if (itr == lis.end()) {
                lis.push_back(num);
            }
            else {
                *itr = num;
            }
        }

        return lis.size();
    }
};
