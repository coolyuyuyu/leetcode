class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); i += 2) {
            ret.insert(ret.end(), nums[i], nums[i + 1]);
        }

        return ret;
    }
};
