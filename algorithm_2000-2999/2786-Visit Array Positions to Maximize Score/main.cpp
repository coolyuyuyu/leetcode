class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        // dpEvn[i]: maximum total score from nums[0:i] and the last visited number is even
        // dpOdd[i]: maximum total score from nums[0:i] and the last visited number is odd
        long long dpEvn = LLONG_MIN / 2, dpOdd = LLONG_MIN / 2;
        if (nums[0] & 1) {
            dpOdd = nums[0];
        }
        else {
            dpEvn = nums[0];
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] & 1) { // odd
                dpOdd = std::max(dpOdd + nums[i], dpEvn + nums[i] - x);
            }
            else { // even
                dpEvn = std::max(dpEvn + nums[i], dpOdd + nums[i] - x);
            }
        }

        return std::max(dpEvn, dpOdd);
    }
};
