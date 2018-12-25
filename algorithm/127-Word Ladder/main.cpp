class Solution {
public:
    bool transformable(const string& s1, const string& s2) {
        size_t diff = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
            }
            if (diff > 1) {
                return false;
            }
        }

        return true;
    }

    size_t ladderLengthBfs(const string& beginWord, const string& endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        unordered_set<string> reachable;
        reachable.emplace(beginWord);

        size_t len = 1;
        while (!reachable.empty() && reachable.count(endWord) == 0) {
            unordered_set<string> toAdd;
            for (const string& word1 : reachable) {
                for (const string& word2 : words) {
                    if (transformable(word1, word2)) {
                        toAdd.emplace(word2);
                    }
                }
            }

            for (const string& word2: toAdd) {
                words.erase(word2);
            }
            reachable.swap(toAdd);

            len++;
        }

        return 0 < reachable.count(endWord) ? len : 0;
    }

    size_t ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return ladderLengthBfs(beginWord, endWord, wordList);
    }
};