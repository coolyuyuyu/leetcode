class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ret = 0;
        for (int i = 0; i < 24; ++i) {
            int cnt = 0;
            for (int num : candidates) {
                if (num & (1 << i)) {
                    ++cnt;
                }
            }
            ret = std::max(ret, cnt);
        }

        return ret;
    }
};
