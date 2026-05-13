class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ret;
        for (int i = nums.size(); 0 < i--;) {
            for (int num = nums[i]; num; num /= 10) {
                ret.push_back(num % 10);
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
