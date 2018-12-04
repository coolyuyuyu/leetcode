class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* pRoot = buildTrie(dict);

        ostringstream oss;
        for (size_t i = 0, wordBegin = 0; i <= sentence.size(); ++i) {
            if (sentence.size() == i) {
                string word = sentence.substr(wordBegin, i - wordBegin);
                oss << searchTrieShortestAbbr(pRoot, word);

            }
            else if (isblank(sentence[i])) {
                string word = sentence.substr(wordBegin, i - wordBegin);
                oss << searchTrieShortestAbbr(pRoot, word);

                oss << sentence[i];
                wordBegin = i + 1;
            }
        }

        return oss.str();
    }
private:
    class TrieNode {
    public:
        TrieNode()
            : childs(26, nullptr)
            , end(false) {
        }

        vector<TrieNode*> childs;
        bool end;
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* pRoot = new TrieNode();
        for (const string& word : words) {
            insertTrie(pRoot, word);
        }

        return pRoot;
    }

    void insertTrie(TrieNode* pRoot, const string& word) {
        TrieNode** ppNode = &pRoot;
        for (char c : word) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }

        (*ppNode)->end = true;
    }

    string searchTrieShortestAbbr(TrieNode* pRoot, const string& word) {
        string abbr;

        for (char c : word) {
            pRoot = pRoot->childs[c - 'a'];
            if (pRoot == nullptr) {
                break;
            }
            abbr.push_back(c);

            if (pRoot->end) {
                return abbr;
            }
        }

        return word;
    }
};