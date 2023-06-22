class Solution {
public:
    long long byBinarySearch(const vector<int>& nums, const vector<int>& costs) {
        int n = nums.size();
        std::function<long long(int)> computeCost = [&](int target) {
            long long totalCost = 0;
            for (int i = 0; i < n; ++i) {
                totalCost += static_cast<long long>(costs[i]) * std::abs(target - nums[i]);
            }
            return totalCost;
        };

        int lo, hi; {
            auto result = std::minmax_element(nums.begin(), nums.end());
            lo = *(result.first);
            hi = *(result.second);
        }
        long long ret = computeCost(lo);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long totalCost1 = computeCost(mid), totalCost2 = computeCost(mid + 1);
            if (totalCost1 < totalCost2) {
                ret = std::min(ret, totalCost1);
                hi = mid;
            }
            else if (totalCost1 == totalCost2) {
                ret = std::min(ret, totalCost1);
                break;
            }
            else {
                ret = std::min(ret, totalCost2);
                lo = mid + 1;
            }
        }

        return ret;
    }

    long long byThreePass(const vector<int>& nums, const vector<int>& costs) {
        int n = nums.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int index1, int index2) { return nums[index1] < nums[index2]; });

        vector<long long> costLft(n); // costLft[i]: the total cost to make nums[0:i-1] as nums[i]
        costLft[0] = 0;
        for (long long i = 1, sum = costs[indexes[0]]; i < n; ++i) {
            costLft[i] = costLft[i - 1] + (nums[indexes[i]] - nums[indexes[i - 1]]) * sum;
            sum += costs[indexes[i]];
        }

        vector<long long> costRht(n); // costRht[i]: the total cost to make nums[i+1:n-1] as nums[i]
        costRht[n - 1] = 0;
        for (long long i = n - 1, sum = costs[indexes[n - 1]]; 0 < i--;) {
            costRht[i] = costRht[i + 1] + (nums[indexes[i + 1]] - nums[indexes[i]]) * sum;
            sum += costs[indexes[i]];
        }

        long long ret = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ret = std::min(ret, costLft[i] + costRht[i]);
        }

        return ret;
    }

    long long byMath(const vector<int>& nums, const vector<int>& costs) {
        int n = nums.size();

        vector<int> indexes(n);
        std::iota(indexes.begin(), indexes.end(), 0);
        std::sort(indexes.begin(), indexes.end(), [&](int index1, int index2) { return nums[index1] < nums[index2]; });

        long long sumCosts = std::accumulate(costs.begin(), costs.end(), 0LL);
        int target;
        for (long long i = 0, count = 0; i < n; ++i) {
            count += costs[indexes[i]];
            if ((sumCosts * 1.0 / 2) < count) {
                target = nums[indexes[i]];
                break;
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalCost += static_cast<long long>(costs[i]) * std::abs(target - nums[i]);
        }

        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        return byBinarySearch(nums, cost);
        //return byThreePass(nums, cost);
        //return byMath(nums, cost);  
    }
};
