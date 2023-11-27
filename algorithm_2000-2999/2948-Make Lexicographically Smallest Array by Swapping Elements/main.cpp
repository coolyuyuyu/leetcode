class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        int indexes[n];
        std::iota(indexes, indexes + n, 0);
        std::sort(indexes, indexes + n, [&](const int i1, const int i2){ return nums[i1] < nums[i2]; });

        vector<int> ret(n);
        for (int lft = 0, rht = 0; rht < n; lft = rht) {
            while (lft == rht || (rht < n  && nums[indexes[rht]] - nums[indexes[rht - 1]] <= limit)) {
                ++rht;
            }

            priority_queue<int, vector<int>, std::greater<int>> pq;
            for (int i = lft; i < rht; ++i) {
                pq.push(indexes[i]);
            }

            for (int i = lft; i < rht; ++i) {
                ret[pq.top()] = nums[indexes[i]];
                pq.pop();
            }
        }

        return ret;
    }
};
