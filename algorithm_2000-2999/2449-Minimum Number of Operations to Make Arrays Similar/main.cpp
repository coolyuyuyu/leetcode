class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        auto cmp = [](int i1, int i2) {
            bool isOdd1 = i1 & 1, isOdd2 = i2 & 1;
            if (isOdd1 && !isOdd2) {
                return true;
            }
            else if (!isOdd1 && isOdd2) {
                return false;
            }
            else {
                return i1 < i2;
            }
        };
        std::sort(nums.begin(), nums.end(), cmp);
        std::sort(target.begin(), target.end(), cmp);

        long long totalPosDiff = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] < target[i]) {
                totalPosDiff += (target[i] - nums[i]);
            }
        }

        return totalPosDiff / 2;
    }
};
