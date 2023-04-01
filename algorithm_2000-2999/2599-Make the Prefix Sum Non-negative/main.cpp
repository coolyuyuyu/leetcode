class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        long long presum = 0;
        int ret = 0;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int num : nums) {
            if (num < 0) {
                pq.push(num);
            }
            presum += num;
            if (presum < 0) {
                presum -= pq.top();
                pq.pop();
                ++ret;
            }
        }

        return ret;
    }
};
