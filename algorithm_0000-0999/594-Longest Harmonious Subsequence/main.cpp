class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        int ret = 0;
        for (auto cur = cnts.begin(); cur != cnts.end();) {
            auto nxt = std::next(cur);
            if (nxt != cnts.end() && cur->first + 1 == nxt->first) {
                ret = std::max(ret, cur->second + nxt->second);
            }
            cur = nxt;
        }

        return ret;
    }
};
