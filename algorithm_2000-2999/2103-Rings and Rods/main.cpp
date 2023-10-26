class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;

        int cntPair = 0;
        for (int num : nums) {
            cntPair += cnts[num + k];
            cntPair += cnts[num - k];

            ++cnts[num];
        }

        return cntPair;
    }
};
