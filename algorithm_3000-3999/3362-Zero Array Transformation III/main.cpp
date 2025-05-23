class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size(), n = queries.size();

        int diffs[m + 1];
        std::fill(diffs, diffs + m + 1, 0);

        std::sort(queries.begin(), queries.begin() + n);

        priority_queue<int> maxPQ;
        for (int i = 0, j = 0, sum = 0; i < m; ++i) {
            sum += diffs[i];

            for (; j < n && queries[j][0] <= i; ++j) {
                maxPQ.push(queries[j][1]);
            }

            while (sum < nums[i] && !maxPQ.empty() && maxPQ.top() >= i) {
                ++sum;
                --diffs[maxPQ.top() + 1];
                maxPQ.pop();
            }

            if (sum < nums[i]) {
                return -1;
            }
        }

        return maxPQ.size();
    }
};
