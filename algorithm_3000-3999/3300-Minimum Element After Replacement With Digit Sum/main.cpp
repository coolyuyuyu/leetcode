class Solution {
public:
    int minElement(vector<int>& nums) {
        int ret = INT_MAX;
        for (int num : nums) {
            int sum = 0;
            for (; num; num /= 10) {
                sum += num % 10;
            }

            ret = std::min(ret, sum);
        }

        return ret;
    }
};
