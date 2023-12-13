class Solution {
public:
    int byBfsOneEnd(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        queue<string> q({beginWord});
        for (int ret = 1; !q.empty(); ++ret) {
            for (int x = q.size(); 0 < x--;) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); ++i) {
                    char letter = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (words.find(word) != words.end()) {
                            if (word == endWord) {
                                return ret + 1;
                            }

                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
        }

        return 0;
    }

    int byBfsTwoEnd(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) { return 0; }
        words.erase(beginWord);
        words.erase(endWord);

        unordered_set<string> self({beginWord}), other({endWord});
        for (int ret = 1; !self.empty(); ++ret) {
            unordered_set<string> next;
            for (string word : self) {
                for (int i = 0; i < word.size(); ++i) {
                    char letter = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (other.find(word) != other.end()) {
                            return ret + 1;
                        }
                        if (words.find(word) != words.end()) {
                            next.insert(word);
                            words.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            std::swap(self, next);

            if (other.size() < self.size()) {
                std::swap(self, other);
            }
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //return byBfsOneEnd(beginWord, endWord, wordList);
        return byBfsTwoEnd(beginWord, endWord, wordList);
    }
};
