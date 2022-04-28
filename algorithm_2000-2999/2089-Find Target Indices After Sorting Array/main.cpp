class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int numEqualTarget = 0, numLessTarget = 0;
        for (int num : nums) {
            if (num < target) {
                ++numLessTarget;
            }
            else if (num == target) {
                ++numEqualTarget;
            }
        }

        vector<int> ans;
        while (0 < numEqualTarget--) {
            ans.push_back(numLessTarget++);
        }
        return ans;
    }
};
