class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ret = 0;
        for (priority_queue<int> maxPQ(nums.begin(), nums.end()); k--;) {
            int num = maxPQ.top();
            maxPQ.pop();

            ret += num;

            maxPQ.emplace(ceil(1.0 * num / 3));
        }

        return ret;
    }
};
