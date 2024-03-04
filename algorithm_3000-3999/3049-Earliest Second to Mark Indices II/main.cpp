class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        nums.insert(nums.begin(), -1);
        changeIndices.insert(changeIndices.begin(), -1);

        std::function<bool(int)> checkOk = [&](int t) {
            int firstClearTimes[n + 1];
            std::fill(firstClearTimes + 1, firstClearTimes + n + 1, 0);
            for (int i = 1; i <= t; ++i) {
                int index = changeIndices[i];
                if (firstClearTimes[index] == 0 && nums[index] > 0) {
                    firstClearTimes[index] = i;
                }
            }

            priority_queue<int, vector<int>, std::greater<int>> minPQ;
            for (int i = t; i >= 1; --i) {
                int index = changeIndices[i];
                if (firstClearTimes[index] != i) {
                    continue;
                }

                minPQ.push(nums[index]);
                if (minPQ.size() > t - i + 1 - minPQ.size()) {
                    minPQ.pop();
                }
            }

            int clearCnt = minPQ.size();
            long long total = std::accumulate(nums.begin() + 1, nums.end(), 0LL);
            for (; !minPQ.empty(); minPQ.pop()) {
                total -= minPQ.top();
            }

            return total <= t - n - clearCnt;
        };

        int lo = 1, hi = m;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (checkOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return checkOk(lo) ? lo : -1;
    }
};
