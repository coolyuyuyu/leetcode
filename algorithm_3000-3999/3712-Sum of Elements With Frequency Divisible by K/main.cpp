class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        int ret = 0;
        for (const auto& [num, cnt] : cnts) {
            if (cnt % k == 0) {
                ret += num * cnt;
            }
        }

        return ret;
    }
};
