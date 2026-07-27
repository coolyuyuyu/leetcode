class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> freqs;
        for (int num : nums) {
            ++freqs[num];
            if (freqs[num] <= k) {
                ret.push_back(num);
            }
        }

        return ret;
    }
};
