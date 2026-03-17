class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnts;
        for (int num : nums1) {
            ++cnts[num];
        }
        for (int num : nums2) {
            --cnts[num];
        }

        int ret = 0;
        int diff = 0;
        for (const auto& [_, cnt] : cnts) {
            if (cnt & 1) { return -1; }
            if (cnt > 0) {
                ret += cnt / 2;
            }
            diff += cnt / 2;
        }

        return diff == 0 ? ret : -1;
    }
};
