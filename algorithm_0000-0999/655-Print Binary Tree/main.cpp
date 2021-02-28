/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ret;
        queue<pair<TreeNode*, size_t>> nodes;
        if (root) {
            nodes.push(pair<TreeNode*, size_t>(root, 0));
        }

        size_t level = 0;
        while (!nodes.empty()) {
            ++level;

            vector<string> row(pow(2, level - 1));
            for (size_t n = nodes.size(); n > 0; --n) {
                pair<TreeNode*, size_t> p = nodes.front();
                nodes.pop();

                TreeNode* node = p.first;
                size_t index = p.second;
                row[index] = to_string(node->val);

                TreeNode* lft = node->left;
                if (lft) {
                    nodes.push(pair<TreeNode*, size_t>(lft, index * 2));
                }
                TreeNode* rht = node->right;
                if (rht) {
                    nodes.push(pair<TreeNode*, size_t>(rht, index * 2 + 1));
                }
            }
            ret.push_back(row);
        }
        assert(!ret.empty());

        size_t rowLen = pow(2, level) - 1;
        size_t emptyAhead = 0;
        size_t space = 2;
        for (size_t i = ret.size(); i > 0; --i) {
            vector<string>& row = ret[i - 1];

            for (size_t j = 0; j < emptyAhead; ++j) {
                row.insert(row.begin(), "");
            }

            for (vector<string>::iterator it = row.begin() + emptyAhead + 1; it != row.end(); ++it) {
                for (size_t k = space - 1; k > 0; --k) {
                    it = row.insert(it, "");
                };
                it += (space - 1);
            }

            while (row.size() < rowLen) {
                row.push_back("");
            }

            emptyAhead += (space / 2);
            space *= 2;
        }

        return ret;
    }
};