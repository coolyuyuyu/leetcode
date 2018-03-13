class Solution {
public:

    bool wordBreak(const string& s, size_t index, vector<bool>& cacheFails, const vector<string>& wordDict) {
        size_t len = s.size();
        if (index == len) {
            return true;
        }

        if (cacheFails[index]) {
            return false;
        }

        size_t leftLen = len - index;
        for (size_t i = 0; i < wordDict.size(); ++i) {
            const string& word = wordDict[i];
            size_t wordLen = word.size();
            if (leftLen >= wordLen) {
                if (strncmp(s.c_str() + index, word.c_str(), wordLen) == 0) {
                    if (wordBreak(s, index + wordLen, cacheFails, wordDict)) {
                        return true;
                    }
                }
            }
        }

        cacheFails[index] = true;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> cacheFails(s.size(), false);
        return wordBreak(s, 0, cacheFails, wordDict);
    }
};