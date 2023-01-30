class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        // XXXXXXXXXXXX
        //     j   k

        // dpPre[i][v]: number of elements in nums[1:i] which is less than v
        // dpSuf[i][v]: number of elements in nums[i:]  which is greater than v
        // For each (j, k):
        //     ans += (dpPre[j - 1][nums[k]] * dpSuf[k + 1][nums[j]]);

        vector<vector<int>> dpPre(n + 1, vector<int>(n + 1, 0));
        for (int v = 1; v <= n; ++v) {
            for (int i = 1; i <= n; ++i) {
                if (nums[i] < v) {
                    dpPre[i][v] = dpPre[i - 1][v] + 1;
                }
                else {
                    dpPre[i][v] = dpPre[i - 1][v];
                }
            }
        }

        vector<vector<int>> dpSuf(n + 2, vector<int>(n + 2, 0));
        for (int v = 1; v <= n; ++v) {
             for (int i = n; 1 <= i; --i) {
                if (nums[i] > v) {
                    dpSuf[i][v] = dpSuf[i + 1][v] + 1;
                }
                else {
                    dpSuf[i][v] = dpSuf[i + 1][v];
                }
            }
        }

        long long ret = 0;
        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (nums[k] < nums[j]) {
                    ret += (dpPre[j - 1][nums[k]] * dpSuf[k + 1][nums[j]]);
                }
            }
        }

        return ret;
    }
};
