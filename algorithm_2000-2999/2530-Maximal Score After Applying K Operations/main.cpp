class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ret = 0;

        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            int num = pq.top();
            pq.pop();

            ret += num;

            pq.push(ceil(static_cast<double>(num) / 3));
        }

        return ret;
    }
};
