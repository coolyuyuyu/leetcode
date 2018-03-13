class Solution {
public:
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

    bool wordBreak(string s, size_t index, vector<bool>& cacheFails, TrieNode* root, string& sentence, vector<string>& sentences) {
        if (index == s.size()) {
            sentences.emplace_back(sentence);
            return true;
        }

        if (cacheFails[index]) {
            return false;
        }

        bool success = false;
        string word;
        TrieNode* node = root;
        for (size_t i = index; i < s.size(); ++i) {
            char c = s[i];
            if (node->childs[c]) {
                word.push_back(c);
                node = node->childs[c];
                if (node->end) {
                    size_t sentenceLen = sentence.size();
                    if (sentenceLen != 0) {
                        sentence.push_back(' ');
                    }
                    sentence.append(word);
                    if (wordBreak(s, i + 1, cacheFails, root, sentence, sentences)) {
                        success = true;
                    }
                    sentence.resize(sentenceLen);
                }
            }
            else {
                break;
            }
        }

        if (!success) {
            cacheFails[index] = true;
        }
        return success;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = buildTrie(wordDict);
        vector<bool> cacheFails(s.size(), false);
        string sentence;
        vector<string> sentences;

        wordBreak(s, 0, cacheFails, root, sentence, sentences);

        return sentences;
    }
};