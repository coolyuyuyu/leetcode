class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> cnts(51, 0);

        vector<int> ret(n - k + 1);
        for (int i = 0; i < n; ++i) {
            ++cnts[nums[i]];

            if (i + 1 >= k) {
                priority_queue<pair<int, int>> pq; // <cnt, num>
                for (int num = 0; num < cnts.size(); ++num) {
                    if (cnts[num]) { pq.emplace(cnts[num], num); }
                }

                for (int j = 0; j < x && !pq.empty(); ++j) {
                    auto [cnt, num] = pq.top();
                    pq.pop();

                    ret[i + 1 - k] += cnt * num;
                }
            }

            if (i + 1 >= k) {
                --cnts[nums[i - k + 1]];
            }
        }

        return ret;
    }
};
