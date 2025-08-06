class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        struct TreeNode {
            map<string, TreeNode*> nexts;
        };

        TreeNode* root = new TreeNode();
        for (const vector<string>& path : paths) {
            TreeNode* node = root;
            for (const string& v : path) {
                if (node->nexts.find(v) == node->nexts.end()) {
                    node->nexts[v] = new TreeNode();
                }
                node = node->nexts[v];
            }
        }

        unordered_map<int, int> id2cnt;
        unordered_map<string, int> hash2id;
        unordered_map<TreeNode*, int> node2id;

        // nullptr: id = 0
        // leaf: id = 1
        // other: id = 2, ...
        std::function<int(TreeNode*)> getId = [&](TreeNode* node) {
            if (!node) {
                return 0;
            }
            if (node2id.find(node) != node2id.end()) {
                return node2id[node];
            }

            string hash;
            for (const auto& [val, next] : node->nexts) {
                hash += val + "#";
                hash += std::to_string(getId(next)) + "#";
            }

            int& id = node2id[node];
            if (hash.empty()) {
                id = 1;
            }
            else {
                id = hash2id.emplace(hash, hash2id.size() + 2).first->second;
            }
            ++id2cnt[id];

            return id;
        };
        getId(root);

        vector<vector<string>> ret;
        vector<string> path;
        std::function<void(TreeNode*, vector<string>&)> dfs = [&](TreeNode* node, vector<string>& path) {
            int id = getId(node);
            if (id2cnt[id] >= 2 && id != 1) {
                return;
            }
            if (node != root) {
                ret.push_back(path);
            }

            for (const auto& [val, next] : node->nexts) {
                if (val != "/") {
                    path.push_back(val);
                }
                dfs(next, path);

                if (val != "/") {
                    path.pop_back();
                }
            }
        };
        dfs(root, path);

        return ret;
    }
};
