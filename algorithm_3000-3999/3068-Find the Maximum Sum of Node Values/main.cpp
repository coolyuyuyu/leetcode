class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        priority_queue<int> maxPQ;
        long long ret = 0;
        for (int num : nums) {
            ret += num;
            maxPQ.push((num ^ k) - num);
        }

        while (maxPQ.size() >= 2) {
            int a = maxPQ.top(); maxPQ.pop();
            int b = maxPQ.top(); maxPQ.pop();
            if (a + b <= 0) { break; }

            ret += a + b;
        }

        return ret;
    }
};
