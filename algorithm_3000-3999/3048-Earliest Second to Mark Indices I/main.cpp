class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        nums.insert(nums.begin(), -1);
        changeIndices.insert(changeIndices.begin(), -1);

        std::function<bool(int)> checkOk = [&](int t) {
            int markTimes[n + 1];
            std::fill(markTimes + 1, markTimes + n + 1, 0);
            for (int i = 1; i <= t; ++i) {
                cout << i << " " << changeIndices[i] << endl;
                markTimes[changeIndices[i]] = i;
            }
            if (std::any_of(markTimes + 1, markTimes + n + 1, [](int markTime){ return markTime == 0; })) {
                return false;
            }

            int cnt = 0;
            for (int i = 1; i <= t; ++i) {
                if (markTimes[changeIndices[i]] > i) {
                    ++cnt;
                }
                else {
                    cnt -= nums[changeIndices[i]];
                    if (cnt < 0) {
                        return false;
                    }
                }
            }

            return true;
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
