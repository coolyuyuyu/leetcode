class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        unordered_map<int, int> cnts;
        for (int num : nums) {
            if (++cnts[num] > nums.size() / k) {
                return false;
            }
        }

        return true;
    }
};
