class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        int ret = -1;
        for (const auto& [num, cnt] : cnts) {
            if (cnt == 1) {
                ret = std::max(ret, num);
            }
        }

        return ret;
    }
};
