class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int, int>, int> m; // <xor sum, cntO - cntE>
        m[{0, 0}] = -1;

        int ret = 0;

        int sum = 0, diff = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum ^= nums[i];
            diff += (nums[i] & 1 ? 1 : -1);
            if (m.find({sum, diff}) != m.end()) {
                ret = std::max(ret, i - m[{sum, diff}]);
            }
            else {
                m[{sum, diff}] = i;
            }
        }

        return ret;
    }
};
