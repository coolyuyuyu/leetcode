class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int lastGroup = -1;
        vector<string> ret;
        for (int i = 0; i < words.size(); ++i) {
            if (groups[i] != lastGroup) {
                lastGroup = groups[i];
                ret.push_back(words[i]);
            }
        }

        return ret;
    }
};
