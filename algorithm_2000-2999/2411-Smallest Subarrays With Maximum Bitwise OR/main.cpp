class Solution {
public:
    bool stripable(const vector<int>& cnts, int num) {
        for (int i = 0; i < 32; ++i) {
            if (cnts[i] == 1 && ((num >> i) & 1)) {
                return false;
            }
        }

        return true;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n);

        vector<int> cnts(32, 0);
        for (int lft = n - 1, rht = n - 1; 0 <= lft; --lft) {
            for (int i = 0; i < 32; ++i) {
                cnts[i] += ((nums[lft] >> i) & 1) ? 1 : 0;
            }

            while (lft < rht && stripable(cnts, nums[rht])) {
                for (int i = 0; i < 32; ++i) {
                    if ((nums[rht] >> i) & 1) {
                        --cnts[i];
                    }
                }
                --rht;
            }

            ret[lft] = rht - lft + 1;
        }

        return ret;
    }
};
