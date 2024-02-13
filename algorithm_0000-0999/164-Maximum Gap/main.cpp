class Solution {
public:
    // Time: O(nlogn)
    int f1(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            ret = std::max(ret, nums[i + 1] - nums[i]);
        }

        return ret;
    }

    // Time: O(n), bucket sort
    int f2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return 0; }
        auto [mnItr, mxItr] = std::minmax_element(nums.begin(), nums.end());
        int mn = *mnItr, mx = *mxItr;
        int bucketCnt = n;
        int bucketSiz = (mx - mn) / bucketCnt + 1;

        // mnVals[i]: the minimal value of buckets[i]
        // mxVals[i]: the maximal value of buckets[i]
        int mnVals[bucketCnt], mxVals[bucketCnt];
        for (int i = 0; i < bucketCnt; ++i) {
            mnVals[i] = INT_MAX;
            mxVals[i] = INT_MIN;
        }
        for (int num : nums) {
            int buckedIdx = (num - mn) / bucketSiz;
            mnVals[buckedIdx] = std::min(mnVals[buckedIdx], num);
            mxVals[buckedIdx] = std::max(mxVals[buckedIdx], num);
        }

        int ret = 0;
        for (int i = 1, preMx = mxVals[0]; i < bucketCnt; ++i) {
            if (mnVals[i] != INT_MAX) {
                ret = std::max(ret, mnVals[i] - preMx);
                preMx = mxVals[i];
            }
        }

        return ret;
    }

    int maximumGap(vector<int>& nums) {
        //return f1(nums);
        return f2(nums);
    }
};
