class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int diffs[2 * limit + 2];
        std::fill(diffs, diffs + 2 * limit + 1, 0);
        for (int i = 0, n = nums.size(); i * 2 < n; ++i) {
            auto [a, b] = std::minmax(nums[i], nums[n - 1 - i]);
            diffs[2] += 2;
            diffs[a + 1] -= 1;
            diffs[a + b] -= 1;
            diffs[a + b + 1] += 1;
            diffs[limit + b + 1] += 1;
            diffs[2 * limit + 1] -= 2;
        }

        int ret = INT_MAX;
        for (int i = 2, sum = 0; i <= 2 * limit; ++i) {
            sum += diffs[i];
            ret = std::min(ret, sum);
        }

        return ret;
    }
};

// pair sum of a and b: x

// 0 move: x = a + b

// Increase x
//     1 move: x ∈ [a + b + 1, limit + b]
//     2 move: x ∈ [limit + b + 1, 2 * limit]
// Decrease x:
//     1 move: x ∈ [a + 1, a + b - 1]
//     2 move: x ∈ [2, a]
