class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int closet[n];
        closet[0] = 1;
        for (int i = 1; i + 1 < n; ++i) {
            int diffL = std::abs(nums[i] - nums[i - 1]), diffR = std::abs(nums[i] - nums[i + 1]);
            closet[i] = (diffL <= diffR ? (i - 1) : (i + 1));
        }
        closet[n - 1] = n - 2;

        int presumR[n];
        presumR[0] = 0;
        for (int i = 1; i < n; ++i) {
            presumR[i] = presumR[i - 1] + (closet[i - 1] == i ? 1 : std::abs(nums[i] - nums[i - 1]));
        }

        int presumL[n];
        presumL[n - 1] = 0;
        for (int i = n - 1; 0 < i--;) {
            presumL[i] = presumL[i + 1] + (closet[i + 1] == i ? 1 : std::abs(nums[i] - nums[i + 1]));
        }

        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int src = queries[i][0], dst = queries[i][1];
            if (src < dst) {
                ret[i] = presumR[dst] - presumR[src];
            }
            else if (src == dst) {
                ret[i] = 0;
            }
            else {
                ret[i] = presumL[dst] - presumL[src];
            }
        }

        return ret;
    }
};
