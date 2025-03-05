/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* recursive(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* ret = new Node(root->val);
        for (auto& child : root->children) {
            ret->children.push_back(recursive(child));
        }

        return ret;
    }

    Node* iterative(Node* root) {
        Node* pRootOld = root;
        Node* pRootNew = nullptr;
        queue<pair<Node**, Node**>> q;
        if (root) {
            q.emplace(&pRootNew, &pRootOld);
        }
        while (!q.empty()) {
            auto [ppNew, ppOld] = q.front();
            q.pop();

            *ppNew = new Node((*ppOld)->val);
            int n = (*ppOld)->children.size();
            (*ppNew)->children.resize(n);
            for (int i = 0; i < n; ++i) {
                q.emplace(&((*ppNew)->children[i]), &((*ppOld)->children[i]));
            }
        }

        return pRootNew;
    }

    Node* cloneTree(Node* root) {
        //return recursive(root);
        return iterative(root);
    }
};
