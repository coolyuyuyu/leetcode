class Solution {
public:
    int maxSameLengthRuns(string s) {
        unordered_map<int, int> cntFreq;
        for (int i = 0, n = s.size(); i < n;) {
            int j = i;
            while (j < n && s[i] == s[j]) {
                ++j;
            }
            ++cntFreq[j - i];

            i = j;
        }

        int ret = 0;
        for (const auto& [_, freq] : cntFreq) {
            ret = std::max(ret, freq);
        }

        return ret;
    }
};
