class Solution {
public:
    // Time: O(nlogn)
    int bsearch(const vector<int>& nums) {
        auto isOk = [&nums](int maxNum) -> bool {
            long buf = 0;
            for (int num : nums) {
                if (num <= maxNum) {
                    buf += (maxNum - num);
                }
                else {
                    buf -= (num - maxNum);
                    if (buf < 0) {
                        return false;
                    }
                }
            }

            return true;
        };

        int lo = 0, hi = *std::max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isOk(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Time: O(n)
    int greedy(const vector<int>& nums) {
        int maxNum = 0;
        long presum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            maxNum = std::max<int>(maxNum, std::ceil(static_cast<double>(presum) / (i + 1)));
        }

        return maxNum;
    }

    int minimizeArrayValue(vector<int>& nums) {
        //return bsearch(nums);
        return greedy(nums);
    }
};
