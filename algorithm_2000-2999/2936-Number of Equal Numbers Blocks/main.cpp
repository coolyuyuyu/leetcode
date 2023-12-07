/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int byDivideAndConquer(BigArray* nums) {
        std::function<int(long long, long long)> f = [&](long long lo, long long hi) {
            if (lo > hi) {
                return 0;
            }
            else if (lo == hi) {
                return 1;
            }
            else if (nums->at(lo) == nums->at(hi)) {
                return 1;
            }
            else if (lo + 1 == hi) {
                return 2;
            }

            long long mid = lo + (hi - lo) / 2;
            return f(lo, mid) + f(mid, hi) - 1;
        };
        return f(0, nums->size() - 1);
    }

    int countBlocks(BigArray* nums) {
        return byDivideAndConquer(nums);
    }
};
