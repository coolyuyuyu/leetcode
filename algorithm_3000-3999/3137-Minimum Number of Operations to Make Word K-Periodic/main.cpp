class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();

        unordered_map<string, int> cnts;
        for (int i = 0; i < n; i += k) {
            ++cnts[word.substr(i, k)];
        }

        int mxCnt = 0;
        for (const auto& [_, cnt] : cnts) {
            mxCnt = std::max(mxCnt, cnt);
        }

        return n / k - mxCnt;
    }
};
