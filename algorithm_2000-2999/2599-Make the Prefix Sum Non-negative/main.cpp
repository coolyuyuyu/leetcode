class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int ret = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long presum = 0;
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
