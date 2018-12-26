class Solution {
public:
    vector<vector<string>> findLaddersBfs(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> candidates(wordList.begin(), wordList.end());
        candidates.erase(beginWord);
        if (candidates.find(endWord) == candidates.end()) {
            return {};
        }

        vector<vector<string>> ans;

        bool stop = false;
        queue<vector<string>> paths;
        paths.push({beginWord});
        while (!paths.empty() && !stop) {
            unordered_set<string> visited;

            size_t n = paths.size();
            for (size_t i = 0; i < n; ++i) {
                vector<string> path = paths.front();
                paths.pop();

                string word = path.back();
                for (size_t j = 0; j < word.size(); ++j) {
                    char letter = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == letter) {
                            continue;
                        }

                        word[j] = c;
                        if (candidates.find(word) != candidates.end()) {
                            path.emplace_back(word);
                            paths.emplace(path);
                            if (word == endWord) {
                                stop = true;
                                ans.emplace_back(path);
                            }
                            path.pop_back();

                            visited.emplace(word);
                        }
                    }
                    word[j] = letter;
                }
            }

            for (const string& word : visited) {
                candidates.erase(word);
            }
        }

        return ans;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        assert(beginWord != endWord);

        return findLaddersBfs(beginWord, endWord, wordList);
    }
};