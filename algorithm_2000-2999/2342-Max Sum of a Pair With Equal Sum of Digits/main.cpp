class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> m;
        std::function<int(int)> sumDigits = [](int num) {
            int ret = 0;
            for (; num; num /= 10) {
                ret += num % 10;
            }
            return ret;
        };

        int ret = -1;
        for (int num : nums) {
            auto& [max1, max2] = m[sumDigits(num)];
            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }

            if (max2 > 0 && max1 + max2 > ret) {
                ret = max1 + max2;
            }
        }

        return ret;
    }
};
