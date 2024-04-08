class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
            sum += nums[i];
        }

        vector<long long> ret(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            const auto& query = queries[i];
            sum -= nums[query[0]];
            nums[query[0]] = 0;
            int k = query[1];
            while (!pq.empty() && k) {
                auto [_, idx] = pq.top();
                pq.pop();

                if (nums[idx] == 0) {
                    continue;
                }

                sum -= nums[idx];
                nums[idx] = 0;
                --k;
            }

            ret[i] = sum;
        }

        return ret;
    }
};
