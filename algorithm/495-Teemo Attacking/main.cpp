class Solution {
public:
    inline int searchInsert(const vector<int>& nums, size_t lo, size_t hi, int target) {
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (target <= nums[mid]) {
                hi = mid;
            }
            else {
                assert(nums[mid] < target);
                lo = mid + 1;
            }
        }

        assert(lo == hi);
        return hi;
    }

    // Time(n): O((n/duration)(logn))
    int findPoisonedDurationV1(const vector<int>& timeSeries, int duration) {
        if (duration == 0) {
            return 0;
        }

        int totalTime = 0;
        for (size_t index = 0; index < timeSeries.size();) {
            int target = timeSeries[index] + duration;
            size_t indexTmp = searchInsert(timeSeries, index + 1, timeSeries.size(), target);
            if (index + 1 == indexTmp) {
                totalTime += duration;
                index = indexTmp;
            }
            else {
                totalTime += (timeSeries[indexTmp - 1] - timeSeries[index]);
                index = indexTmp - 1;
            }
        }

        return totalTime;
    }

    // Time(n): O(n)
    int findPoisonedDurationV2(const vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }

        int totalTime = duration;
        for (size_t i = 1; i < timeSeries.size(); ++i) {
            totalTime += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }

        return totalTime;
    }

    // Mix of V1 and V2
    int findPoisonedDurationV3(const vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) {
            return 0;
        }

        int totalTime = duration;
        for (size_t index = 0; index + 1 < timeSeries.size();) {
            if (timeSeries[index + 1] - timeSeries[index] >= duration) {
                totalTime += duration;
                index += 1;
            }
            else {
                int target = timeSeries[index] + duration;
                size_t indexTmp = searchInsert(timeSeries, index + 1, timeSeries.size(), target);
                totalTime += (timeSeries[indexTmp - 1] - timeSeries[index]);
                index = indexTmp - 1;
            }
        }

        return totalTime;
    }

    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //return findPoisonedDurationV1(timeSeries, duration);

        //return findPoisonedDurationV2(timeSeries, duration);

        return findPoisonedDurationV3(timeSeries, duration);
    }
};