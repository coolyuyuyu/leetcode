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
    Node* cloneTree_Recursive(Node* root) {
        if (!root) {
            return nullptr;
        }

        Node* rootNew = new Node(root->val);
        for (Node* child : root->children) {
            rootNew->children.push_back(cloneTree_Recursive(child));
        }

        return rootNew;
    }

    Node* cloneTree_Iterative(Node* root) {
        Node* pRootOld = root;
        Node** ppRootOld = &pRootOld;
        Node* pRootNew = nullptr;
        Node** ppRootNew = &pRootNew;

        queue<pair<Node**, Node**>> q;
        if (*ppRootOld) {
            q.emplace(ppRootOld, ppRootNew);
        }
        while (!q.empty()) {
            ppRootOld = q.front().first;
            ppRootNew = q.front().second;
            q.pop();

            *ppRootNew = new Node((*ppRootOld)->val);
            (*ppRootNew)->children.resize((*ppRootOld)->children.size());

            for (size_t i = 0; i < (*ppRootNew)->children.size(); ++i) {
                q.emplace(&((*ppRootOld)->children[i]), &((*ppRootNew)->children[i]));
            }
        }

        return pRootNew;
    }

    Node* cloneTree(Node* root) {
        //return cloneTree_Recursive(root);
        return cloneTree_Iterative(root);
    }
};