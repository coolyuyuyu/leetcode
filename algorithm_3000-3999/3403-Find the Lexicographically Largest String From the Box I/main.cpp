class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        char target = *std::max_element(word.begin(), word.end());

        string ret;
        for (int i = 0, n = word.size(); i < n; ++i) {
            if (word[i] != target) { continue; }
            ret = std::max(ret, word.substr(i, n - numFriends + 1));
        }

        return ret;
    }
};
