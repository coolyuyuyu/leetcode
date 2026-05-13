class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();

        vector<int> ret(n);

        int cnts[2] = {0, 0};
        for (int i = n; 0 < i--;) {
            ret[i] = cnts[1 - (nums[i] & 1)];
            ++cnts[nums[i] & 1];
        }

        return ret;
    }
};
