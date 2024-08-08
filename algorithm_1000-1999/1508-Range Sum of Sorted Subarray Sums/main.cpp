class Solution {
public:
    int M = 1e9 + 7;

    int byBruteForce(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        std::sort(sums.begin(), sums.end());

        int ret = 0;
        for (int i = left - 1; i < right; ++i) {
            ret += sums[i];
            ret %= M;
        }

        return ret;
    }

    int byPQ(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

        int ret = 0;

        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);   
        }
        for (int i = 1; i <= right; ++i) {
            auto [sum, endIdx] = pq.top();
            pq.pop();

            if (i >= left) {
                ret += sum;
                ret %= M;
            }
            if (endIdx + 1 < n) {
                sum += nums[++endIdx];
                sum %= M;
                pq.emplace(sum, endIdx);
            }
        }

        return ret;
    }

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        //return byBruteForce(nums, n, left, right);
        return byPQ(nums, n, left, right);
    }
};
