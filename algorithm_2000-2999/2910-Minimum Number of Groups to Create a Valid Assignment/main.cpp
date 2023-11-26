class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }

        unordered_map<int, int> freqOfFreq;
        int m = INT_MAX;
        for (const auto& [num, freq] : freq) {
            ++freqOfFreq[freq];
            m = std::min(m, freq);
        }

        int ret;
        for (int x = m + 1; x >= 1; x--) {
            ret = 0;
            for (const auto& [f, cnt] : freqOfFreq) {
                int q = f / x;
                int r = f % x;
                if (r == 0) {
                    ret += q * cnt;
                }
                else if (q + 1 >= x - r) {
                    ret += (q + 1) * cnt;
                }
                else {
                    ret = -1;
                    break;
                }
            }

            if (ret != -1) {
                break;
            }
        }

        return ret;
    }
};
