class Solution {
public:
    class TrieNode {
    public:
        array<TrieNode*, 26> childs;
        bool end;
        TrieNode() {
            childs.fill(nullptr);
            end = false;
        }
    };

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (const string& word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->childs[c - 'a'] == nullptr) {
                    node->childs[c - 'a'] = new TrieNode();
                }
                node = node->childs[c - 'a'];
            }
            node->end = true;
        }

        std::function<string(const string&)> replace = [&](const string& word) {
            TrieNode* node = root;
            string ret;
            for (char c : word) {
                node = node->childs[c - 'a'];
                if (!node) { return word; }
                ret += c;
                if (node->end) {
                    return ret;
                }
            }

            return word;
        };

        istringstream iss(sentence);
        string ret;
        for (string token; iss >> token;) {
            ret += replace(token);
            ret += " ";
        }
        ret.pop_back();

        return ret;
    }
};
