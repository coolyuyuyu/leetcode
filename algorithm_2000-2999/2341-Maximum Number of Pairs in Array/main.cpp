class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<bool> left(101, false);

        int numPair = 0, numLeft = 0;
        for (int num : nums) {
            if (left[num]) {
                --numLeft;
                ++numPair;
                left[num] = false;
            }
            else {
                left[num] = true;
                ++numLeft;
            }
        }

        return {numPair, numLeft};
    }
};
