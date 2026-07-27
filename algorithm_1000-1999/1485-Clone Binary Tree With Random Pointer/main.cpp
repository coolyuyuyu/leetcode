/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* recursive(Node* root) {
        unordered_map<Node*, NodeCopy*> cache;
        std::function<NodeCopy*(Node*)> f = [&](Node* root) -> NodeCopy* {
            if (!root) { return nullptr; }
            if (cache.find(root) != cache.end()) { return cache[root]; }

            NodeCopy*& ret = cache[root];
            ret = new NodeCopy(root->val);
            ret->left = f(root->left);
            ret->right = f(root->right);
            ret->random = f(root->random);

            return ret;
        };

        return f(root);
    }

    NodeCopy* iterative(Node* root) {
        unordered_map<Node*, NodeCopy*> cache;

        NodeCopy* rootCopy = nullptr;
        stack<pair<Node**, NodeCopy**>> stk({{&root, &rootCopy}});
        while (!stk.empty()) {
            auto [ppNode, ppNodeCopy] = stk.top();
            stk.pop();

            if (*ppNode == nullptr) {
                continue;
            }

            if (cache.find(*ppNode) == cache.end()) {
                cache[*ppNode] = new NodeCopy((*ppNode)->val);
            }
            *ppNodeCopy = cache[*ppNode];
            if ((*ppNode)->random) {
                if (cache.find((*ppNode)->random) == cache.end()) {
                     cache[(*ppNode)->random] = new NodeCopy((*ppNode)->random->val);
                }
                (*ppNodeCopy)->random = cache[(*ppNode)->random];
            }

            stk.emplace(&((*ppNode)->left), &((*ppNodeCopy)->left));
            stk.emplace(&((*ppNode)->right), &((*ppNodeCopy)->right));
        }

        return rootCopy;
    }

    NodeCopy* copyRandomBinaryTree(Node* root) {
        //return recursive(root);
        return iterative(root);
    }
};
