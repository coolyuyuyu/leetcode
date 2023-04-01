class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        vector<bool> marked(n, false);

        // max queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        long long ret = 0;
        while (!pq.empty()) {
            auto [num, index] = pq.top();
            pq.pop();

            if (marked[index] == true) {
                continue;
            }

            marked[index] = true;
            if (0 < index) {
                marked[index - 1] = true;
            }
            if ((index + 1) < n) {
                marked[index + 1] = true;
            }

            ret += num;
        }

        return ret;
    }
};
