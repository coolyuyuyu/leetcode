class Solution {
public:
    vector<vector<string>> findLaddersBfs(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        unordered_set<string> candidates(wordList.begin(), wordList.end());
        candidates.erase(beginWord);
        if (candidates.find(endWord) == candidates.end()) {
            return {};
        }

        vector<vector<string>> ans;

        queue<vector<string>> paths;
        paths.push({beginWord});
        while (!paths.empty() && ans.empty()) {
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

    vector<vector<string>> findLaddersBfsTwoEnd(const string& beginWord, const string& endWord, const vector<string>& wordList) {
        unordered_set<string> candidates(wordList.begin(), wordList.end());
        if (candidates.find(endWord) == candidates.end()) {
            return {};
        }

        vector<vector<string>> ans;

        unordered_map<string, vector<vector<string>>> pathSets1 = {{beginWord, {{{beginWord}}}}};
        unordered_map<string, vector<vector<string>>> pathSets2 = {{endWord, {{{endWord}}}}};
        while (!pathSets1.empty() && ans.empty()) {
            for (auto p1 : pathSets1) {
                candidates.erase(p1.first);
            }

            unordered_map<string, vector<vector<string>>> pathSetsTmp;
            for (auto p1 : pathSets1) {
                string word = p1.first;
                const vector<vector<string>>& paths1 = p1.second;
                for (size_t j = 0; j < word.size(); ++j) {
                    char letter = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == letter) {
                            continue;
                        }
                        word[j] = c;

                        auto itr2 = pathSets2.find(word);
                        if (itr2 != pathSets2.end()) {
                            const vector<vector<string>>& paths2 = itr2->second;
                            bool headIsPaths1 = paths1.front().front() == beginWord;
                            const vector<vector<string>>& pathsHead = headIsPaths1 ? paths1 : paths2;
                            const vector<vector<string>>& pathsTail = headIsPaths1 ? paths2 : paths1;
                            for (const vector<string>& pathHead : pathsHead) {
                                vector<string> path = pathHead;
                                for (const vector<string>& pathTail : pathsTail) {
                                    path.resize(pathHead.size());
                                    path.insert(path.end(), pathTail.rbegin(), pathTail.rend());
                                    ans.emplace_back(path);
                                }
                            }
                        }

                        if (candidates.find(word) != candidates.end()) {
                            for (vector<string> path1 : paths1) {
                                path1.emplace_back(word);
                                pathSetsTmp[word].emplace_back(path1);
                            }
                        }
                    }
                    word[j] = letter;
                }

            }
            pathSets1.swap(pathSetsTmp);

            // KEY: Expand one end with fewer nodes.
            if (pathSets1.size() > pathSets2.size()) {
                pathSets1.swap(pathSets2);
            }
        }

        return ans;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        assert(beginWord != endWord);

        //return findLaddersBfs(beginWord, endWord, wordList);

        return findLaddersBfsTwoEnd(beginWord, endWord, wordList);
    }
};