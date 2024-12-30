class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ret = INT_MIN, pre = INT_MIN;
        for (int val : values) {
            ret = std::max(ret, pre + val);
            pre = std::max(pre, val) - 1;
        }

        return ret;
    }
};
