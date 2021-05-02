class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> counts(102, 0);
        for (int num : nums) {
            ++counts[num];
        }

        int numPairs = 0;
        for (int count : counts) {
            if (count > 1) {
                numPairs += (count * (count - 1) / 2);
            }
        }

        return numPairs;
    }
};
