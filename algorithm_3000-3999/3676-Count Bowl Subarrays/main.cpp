class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> nxtGT(n, n), preGT(n, -1);
        vector<int> stk; // decreasing monotonic stack
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.back()] < nums[i]) {
                int j = stk.back();
                stk.pop_back();

                nxtGT[j] = i;
            }
            if (!stk.empty()) {
                preGT[i] = stk.back();
            }
            stk.push_back(i);
        }

        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            if (nxtGT[i] < n && nxtGT[i] - i >= 2) { ++ret; }
            if (preGT[i] >= 0 && i - preGT[i] >= 2) { ++ret; }
        }

        return ret;
    }
};
