class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ret = 0;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (long long sum = 0, i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                pq.push(nums[i]);
            }
            sum += nums[i];
            if (sum < 0) {
                sum -= pq.top();
                pq.pop();
                ++ret;
            }
        }

        return ret;
    }
};
