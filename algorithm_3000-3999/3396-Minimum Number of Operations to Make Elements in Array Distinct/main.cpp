class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ret = 0;
        for (int i = 0, n = nums.size(); i < n; i += 3) {
            unordered_set<int> s;
            bool duplicate = false;
            for (int j = i; j < n; ++j) {
                if (s.insert(nums[j]).second == false) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                break;
            }

            ++ret;
        }

        return ret;
    }
};
