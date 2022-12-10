class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ret = stones[1];
        for (size_t i = 2; i < stones.size(); ++i) {
            ret = std::max(ret, stones[i] - stones[i - 2]);
        }

        return ret;
    }
};
