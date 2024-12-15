class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
        }

        vector<bool> marked(nums.size(), false);
        long long ret = 0;
        while (!pq.empty()) {
            auto [num, i] = pq.top();
            pq.pop();

            if (marked[i]) { continue;}

            ret += num;
            marked[i] = true;
            if (i > 0) {
                marked[i - 1] = true;
            }
            if (i + 1 < nums.size()) {
                marked[i + 1] = true;
            }
        }

        return ret;
    }
};
