class Solution {
public:
    int singleNumber(vector<int>& nums) {
        assert(!nums.empty());

        int d = nums.front();
        for (vector<int>::const_iterator iter = nums.begin() + 1; iter != nums.end(); ++iter) {
            d ^= *iter;
        }
        return d;
    }
};