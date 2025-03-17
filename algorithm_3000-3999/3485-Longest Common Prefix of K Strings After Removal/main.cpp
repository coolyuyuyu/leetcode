class Solution {
public:
    struct Node {
        std::array<Node*, 26> nexts;
        int cnt;
        Node() {
            nexts.fill(nullptr);
            cnt = 0;
        }
    };

    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Node* root = new Node();
        map<int, int> len2cnt;
        std::function<void(const string&)> addWord = [&](const string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); ++i) {
                if (node->nexts[word[i] - 'a'] == nullptr) {
                    node->nexts[word[i] - 'a'] = new Node();
                }
                node = node->nexts[word[i] - 'a'];
                node->cnt += 1;
                if (node->cnt == k) {
                    len2cnt[i + 1] += 1;
                }
            }
        };
        std::function<void(const string&)> removeWord = [&](const string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); ++i) {
                node = node->nexts[word[i] - 'a'];
                if (node->cnt == k) {
                    len2cnt[i + 1] -= 1;
                    if (len2cnt[i + 1] == 0) {
                        len2cnt.erase(i + 1);
                    }
                }
                node->cnt -= 1;
            }
        };

        for (const string& word : words) {
            addWord(word);
        }

        int n = words.size();
        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            removeWord(words[i]);
            ret[i] = len2cnt.empty() ? 0 : len2cnt.rbegin()->first;
            addWord(words[i]);
        }

        return ret;
    }
};
