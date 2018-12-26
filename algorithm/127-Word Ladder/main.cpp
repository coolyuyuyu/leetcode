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

    size_t ladderLengthBfsV1(const string& beginWord, const string& endWord, vector<string>& wordList) {
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

    // Time: O(wordLen * wordList.size())
    size_t ladderLengthBfsV2(const string& beginWord, const string& endWord, vector<string>& wordList) {
        unordered_set<string> candidates(wordList.begin(), wordList.end());
        candidates.erase(beginWord);
        if (candidates.find(endWord) == candidates.end()) {
            return 0;
        }

        size_t ladderLen = 1;

        unordered_set<string> check;
        check.emplace(beginWord);
        while (!check.empty()) {
            ++ladderLen;

            unordered_set<string> checkTmp;
            for (string word : check) {
                for (size_t j = 0; j < word.size(); ++j) {
                    char letter = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (candidates.find(word) != candidates.end()) {
                            if (word == endWord) {
                                return ladderLen;
                            }

                            checkTmp.emplace(word);
                            candidates.erase(word);
                        }
                    }
                    word[j] = letter;
                }
            }
            check.swap(checkTmp);
        }

        return 0;
    }

    size_t ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        assert(beginWord != endWord);

        //return ladderLengthBfsV1(beginWord, endWord, wordList);

        return ladderLengthBfsV2(beginWord, endWord, wordList);
    }
};