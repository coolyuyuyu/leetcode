class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ret;

        int lastGroup = groups[0];
        ret.push_back(words[0]);
        for (int i = 1; i < n; ++i) {
            if (lastGroup != groups[i]) {
                ret.push_back(words[i]);
                lastGroup = groups[i];
            }
        }

        return ret;
    }
};
