class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
        }

        for (; k > 0; --k) {
            auto [_, i] = pq.top();
            pq.pop();

            nums[i] *= multiplier;
            pq.emplace(nums[i], i);
        }

        return nums;
    }
};
