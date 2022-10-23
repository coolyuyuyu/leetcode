class Solution {
public:
    long long binarySearch(vector<int>& nums, vector<int>& costs) {
        auto computeCost = [&](int target) {
            long long totalCost = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                totalCost += (long long)(abs(nums[i] - target)) * costs[i];
            }

            return totalCost;
        };

        auto result = std::minmax_element(nums.begin(), nums.end());
        int lo = *result.first, hi = *result.second;
        long long minCost = computeCost(lo);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long aCost = computeCost(mid);
            long long bCost = computeCost( mid + 1);
            if (aCost < bCost) {
                minCost = aCost;
                hi = mid;
            }
            else {
                minCost = bCost;
                lo = mid + 1;
            }
        }

        return minCost;
    }

    long long linearScan(vector<int>& nums, vector<int>& costs) {
        vector<int> indexes(nums.size());
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int index1, int index2) { return nums[index1] < nums[index2]; });

        vector<long long> lftCosts(nums.size()), rhtCosts(nums.size());
        long long totalCost;

        lftCosts.front() = 0 ;
        totalCost = 0;
        for (size_t i = 0; (i + 1) < nums.size(); ++i) {
            totalCost += costs[indexes[i]];
            lftCosts[i + 1] = lftCosts[i] + totalCost * (nums[indexes[i + 1]] - nums[indexes[i]]);
        }

        rhtCosts.back() = 0 ;
        totalCost = 0;
        for (size_t i = nums.size(); 1 < i--;) {
            totalCost += costs[indexes[i]];
            rhtCosts[i - 1] = rhtCosts[i] + totalCost * (nums[indexes[i]] - nums[indexes[i - 1]]);
        }

        long long minCost = std::numeric_limits<long long>::max();
        for (size_t i = 0; i < nums.size(); ++i) {
            minCost = min(minCost, lftCosts[i] + rhtCosts[i]);
        }

        return minCost;
    }

    long long minCost(vector<int>& nums, vector<int>& costs) {
        //return binarySearch(nums, costs);
        return linearScan(nums, costs);
    }
};
