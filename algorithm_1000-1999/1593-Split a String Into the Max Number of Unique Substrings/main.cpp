class Solution {
public:
    int bySet(const string& s) {
        unordered_set<string> uniques;
        std::function<int(int)> dfs = [&](int i) {
            if (i >= s.size()) {
                return 0;
            }

            int ret = 0;
            for (string part; i < s.size(); ++i) {
                part += s[i];
                if (uniques.find(part) == uniques.end()) {
                    uniques.insert(part);
                    ret = std::max(ret, 1 + dfs(i + 1));
                    uniques.erase(part);
                }
            }

            return ret;
        };

        return dfs(0);
    }

    int byTrie(const string& s) {
        struct Node {
            std::array<Node*, 26> childs;
            bool end;
            Node() {
                childs.fill(nullptr);
                end = false;
            }
        };

        Node* root = new Node();
        std::function<int(int)> dfs = [&](int i) {
            if (i >= s.size()) {
                return 0;
            }

            int ret = 0;
            for (Node* node = root; i < s.size(); ++i) {
                if (node->childs[s[i] - 'a'] == nullptr) {
                    node->childs[s[i] - 'a'] = new Node();
                }
                node = node->childs[s[i] - 'a'];
                if (node->end == false) {
                    node->end = true;
                    ret = std::max(ret, 1 + dfs(i + 1));
                    node->end = false;
                }
            }

            return ret;
        };

        return dfs(0);
    }

    int maxUniqueSplit(string s) {
        //return bySet(s);
        return byTrie(s);
    }
};
