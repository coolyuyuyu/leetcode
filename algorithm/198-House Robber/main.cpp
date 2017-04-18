class Solution {
public:
    int rob(vector<int>& nums) {
        int e = 0; // the maximum number excluding the current one
        int i = 0; // the maximum number including the current one
        for (auto num: nums) {
            int tmp = i;
            i = e + num;
            e = max(e, tmp);
        }

        return max(e, i);
    }
};