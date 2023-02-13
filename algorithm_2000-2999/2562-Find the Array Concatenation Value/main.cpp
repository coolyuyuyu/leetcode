class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ret = 0;
        for (size_t lft = 0, rht = nums.size() - 1; lft < rht; ++lft, --rht) {
            string s1 = std::to_string(nums[lft]);
            string s2 = std::to_string(nums[rht]);
            ret += std::stoi(s1 + s2);
        }

        if ((nums.size() % 2) == 1) {
            ret += nums[nums.size() / 2];
        }

        return ret;
    }
};
