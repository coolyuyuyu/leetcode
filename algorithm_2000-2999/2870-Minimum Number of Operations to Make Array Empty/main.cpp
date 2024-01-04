class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        int ret = 0;
        for (auto [_, cnt] : cnts) {
            if (cnt == 1) {
                return -1;
            }

            if (cnt >= 3 && cnt & 1) {
                cnt -= 3;
                ++ret;
            }

            ret += (cnt / 6) * 2;
            cnt -= (cnt / 6) * 6;
            ret += cnt / 2;
        }

        return ret;
    }
};
