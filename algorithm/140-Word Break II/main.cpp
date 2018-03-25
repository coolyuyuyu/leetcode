class Solution {
public:
    struct TrieNode {
        TrieNode()
            : childs()
            , end(false) {
        }
        map<char, TrieNode*> childs;
        bool end;
        size_t index;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (size_t j = 0; j < words.size(); ++j) {
            TrieNode* node = root;
            const string& word = words[j];
            for (size_t i = 0; i < word.size(); ++i) {
                TrieNode* child = NULL; {
                    char c = word[i];
                    pair<map<char, TrieNode*>::iterator, bool> p = node->childs.emplace(c, nullptr);
                    if (p.second) {
                        child = new TrieNode();
                        p.first->second = child;
                    }
                    else {
                        child = p.first->second;
                    }

                }
                node = child;
            }
            if (node->end == false) {
                node->end = true;
                node->index = j;
            }
        }

        return root;
    }

    const vector<vector<size_t>>& wordBreak(const string& s, size_t index, const TrieNode* root, vector<bool>& dones, vector<vector<vector<size_t>>>& results) {
        size_t len = s.size();
        assert(index < len);

        if (dones[index]) {
            return results[index];
        }

        const TrieNode* node = root;
        vector<vector<size_t>>& result = results[index];
        for (size_t i = index; i < len; ++i) {
            map<char, TrieNode*>::const_iterator itr = node->childs.find(s[i]);
            if (itr == node->childs.end()) {
                break;
            }

            node = itr->second;
            if (node->end) {
                if (i + 1 < len) {
                    const vector<vector<size_t>>& subResults = wordBreak(s, i + 1, root, dones, results);
                    for (size_t j = 0; j < subResults.size(); ++j) {
                        const vector<size_t>& subResult = subResults[j];
                        result.emplace_back(subResult.begin(), subResult.end());
                        result.back().insert(result.back().begin(), node->index);
                    }
                }
                else {
                    result.emplace_back(1, node->index);
                }
            }
        }

        dones[index] = true;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return {};
        }

        const TrieNode* root = buildTrie(wordDict);
        vector<bool> dones(s.size(), false);
        vector<vector<vector<size_t>>> results(s.size());
        const vector<vector<size_t>>& result = wordBreak(s, 0, root, dones, results);

        vector<string> sentences;
        for (size_t i = 0; i < result.size(); ++i) {
            const vector<size_t>& indexes = result[i];
            string sentence;
            for (size_t j = 0; j < indexes.size(); ++j) {
                sentence += wordDict[indexes[j]];
                if (j + 1 < indexes.size()) {
                    sentence += " ";
                }
            }
            sentences.emplace_back(sentence);
        }

        return sentences;
    }
};