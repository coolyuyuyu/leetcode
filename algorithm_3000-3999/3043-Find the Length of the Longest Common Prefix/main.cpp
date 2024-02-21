class Solution {
public:
    struct TrieNode {
        TrieNode() {
            childs.fill(nullptr);
        }

        array<TrieNode*, 10> childs;
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();

        vector<string> strs1(m), strs2(n);
        for (int i = 0; i < m; ++i) {
            strs1[i] = std::to_string(arr1[i]);
        }
        for (int i = 0; i < n; ++i) {
            strs2[i] = std::to_string(arr2[i]);
        }

        TrieNode* root = new TrieNode();

        std::function<void(const string&)> add = [&](const string& s) {
            TrieNode* node = root;
            for (char c : s) {
                if (node->childs[c - '0'] == nullptr) {
                    node->childs[c - '0'] = new TrieNode();
                }
                node = node->childs[c - '0'];
            }
        };
        for (const string& str : strs1) {
            add(str);
        }

        int ret = 0;
        std::function<int(const string&)> find = [&](const string& s) {
            TrieNode* node = root;
            int ret = 0;
            for (char c : s) {
                if (node->childs[c - '0'] == nullptr) { return ret; }
                node = node->childs[c - '0'];
                ++ret;
            }

            return ret;
        };
        for (const string& str : strs2) {
            ret = std::max(ret, find(str));
        }

        return ret;
    }
};
