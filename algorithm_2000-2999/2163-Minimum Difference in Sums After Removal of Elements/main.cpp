class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        long long lftMinSums[nums.size()], rhtMaxSums[nums.size()];

        priority_queue<int> maxPQ;
        long long lftSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxPQ.push(nums[i]);
            lftSum += nums[i];
            if (maxPQ.size() > n) {
                lftSum -= maxPQ.top();
                maxPQ.pop();
            }

            if (maxPQ.size() == n) {
                lftMinSums[i] = lftSum;
            }
        }

        priority_queue<int, vector<int>, std::greater<>> minPQ;
        long long rhtSum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            minPQ.push(nums[i]);
            rhtSum += nums[i];
            if (minPQ.size() > n) {
                rhtSum -= minPQ.top();
                minPQ.pop();
            }

            if (minPQ.size() == n) {
                rhtMaxSums[i] = rhtSum;
            }
        }

        long long ret = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            ret = std::min(ret, lftMinSums[i] - rhtMaxSums[i + 1]);
        }

        return ret;
    }
};
