class Solution {
public:

    bool wordBreakMemoDfs(const string& s, size_t index, vector<bool>& cacheFails, const vector<string>& wordDict) {
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
                    if (wordBreakMemoDfs(s, index + wordLen, cacheFails, wordDict)) {
                        return true;
                    }
                }
            }
        }

        cacheFails[index] = true;
        return false;
    }

    bool wordBreakMemoDfs(const string& s, const vector<string>& wordDict) {
        vector<bool> cacheFails(s.size(), false);
        return wordBreakMemoDfs(s, 0, cacheFails, wordDict);
    }


    struct TrieNode {
        TrieNode()
            : childs()
            , end(false) {
        }
        map<char, TrieNode*> childs;
        bool end;
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
            node->end = true;
        }

        return root;
    }

    bool wordBreakTrieMemoDfs(const string& s, size_t index, const TrieNode* root, vector<bool>& dones, vector<bool>& breakables) {
        size_t len = s.size();
        assert(index < len);

        if (dones[index]) {
            return breakables[index];
        }

        bool breakable = false;
        const TrieNode* node = root;
        for (size_t i = index; i < len && !breakable; ++i) {
            map<char, TrieNode*>::const_iterator itr = node->childs.find(s[i]);
            if (itr == node->childs.end()) {
                break;
            }

            node = itr->second;
            if (node->end) {
                if (i + 1 < len) {
                    breakable = wordBreakTrieMemoDfs(s, i + 1, root, dones, breakables);
                }
                else {
                    breakable = true;
                }
            }
        }

        dones[index] = true;
        breakables[index] = breakable;

        return breakable;
    }

    bool wordBreakTrieMemoDfs(const string& s, const vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }

        const TrieNode* root = buildTrie(wordDict);
        vector<bool> dones(s.size(), false);
        vector<bool> breakables(s.size(), false);
        return wordBreakTrieMemoDfs(s, 0, root, dones, breakables);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //return wordBreakMemoDfs(s, wordDict);
        return wordBreakTrieMemoDfs(s, wordDict);
    }

};