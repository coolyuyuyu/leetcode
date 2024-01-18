class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        unordered_map<int, int> freqs;
        for (int num : nums) {
            maxFreq = std::max(maxFreq, ++freqs[num]);
        }

        int ret = 0;
        for (const auto& [_, freq] : freqs) {
            if (freq == maxFreq) {
                ret += freq;
            }
        }

        return ret;
    }
};
