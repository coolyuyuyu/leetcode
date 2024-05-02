class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> negatives;
        for (int num : nums) {
            if (num < 0) {
                negatives.insert(num);
            }
        }

        int ret = -1;
        for (int num : nums) {
            if (num > 0 && negatives.find(-num) != negatives.end()) {
                ret = std::max(ret, num);
            }
        }

        return ret;
    }
};
