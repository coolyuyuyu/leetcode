class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        array<int, 101> cnts;
        cnts.fill(0);

        for (int num : nums) {
            ++cnts[num];
        }

        int ret = 0;
        for (int cnt : cnts) {
            ret += cnt * (cnt - 1) / 2;
        }

        return ret;
    }
};
