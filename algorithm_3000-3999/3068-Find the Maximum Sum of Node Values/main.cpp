class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ret = 0;
        priority_queue<int> maxPQ;
        for (int num : nums) {
            ret += num;
            maxPQ.push((num ^ k) - num);
        }

        while (maxPQ.size() >= 2) {
            int diff1 = maxPQ.top(); maxPQ.pop();
            int diff2 = maxPQ.top(); maxPQ.pop();
            if (diff1 + diff2 <= 0) { break; }

            ret += (diff1 + diff2);
        }

        return ret;
    }
};
