/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* rootN) {
        if (!rootN) {
            return nullptr;
        }

        TreeNode* rootB = new TreeNode(rootN->val);
        if (!(rootN->children.empty())) {
            rootB->left = encode(rootN->children.front());

            TreeNode* tmp = rootB->left;
            for (size_t i = 1; i < rootN->children.size(); ++i) {
                tmp->right = encode(rootN->children[i]);
                tmp = tmp->right;
            }
        }

        return rootB;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* rootB) {
        if (!rootB) {
            return nullptr;
        }

        vector<Node*> children;
        if (rootB->left) {
            children.emplace_back(decode(rootB->left));

            TreeNode* tmp = rootB->left->right;
            while (tmp) {
                children.emplace_back(decode(tmp));
                tmp = tmp->right;
            }
        }
        return new Node(rootB->val, children);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));