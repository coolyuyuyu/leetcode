class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num1 : nums) {
            for (int num2 : nums) {
                ++cnts[num1 & num2];
            }
        }

        int ret = 0;
        for (int num1 : nums) {
            for (const auto& [num2, cnt] : cnts) {
                if ((num1 & num2) == 0) {
                    ret += cnt;
                }
            }
        }

        return ret;
    }
};
