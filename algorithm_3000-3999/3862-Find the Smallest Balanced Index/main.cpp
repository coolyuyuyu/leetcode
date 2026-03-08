class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);
        nums.push_back(1);

        long long sumLft[n + 2];
        sumLft[0] = nums[0];
        for (int i = 1; i <= n; ++i) {
            sumLft[i] = sumLft[i - 1] + nums[i];
        }

        long long prodRht[n + 2];
        prodRht[n + 1] = 1;
        for (int i = n; i >= 1; --i) {
            if (prodRht[i + 1] == -1) {
                prodRht[i] = -1;
                continue;
            }
            if (1.0 * nums[i] * prodRht[i + 1] > 1e14) {
                prodRht[i] = -1;
            }
            else {
                prodRht[i] = nums[i] * prodRht[i + 1];
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (sumLft[i - 1] == prodRht[i + 1]) {
                return i - 1;
            }
        }

        return -1;
    }
};
