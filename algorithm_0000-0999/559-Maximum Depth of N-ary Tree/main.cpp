/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepthIter(Node* root) {        
        queue<Node*> nodes;
        if (root) {
            nodes.push(root);
        }
        
        int depth = 0;
        while (!nodes.empty()) {
            ++depth;
            
            queue<Node*> childs;
            while (!nodes.empty()) {
                Node* node = nodes.front();
                nodes.pop();
                
                for (Node* child : node->children) {
                    childs.push(child);
                }                
            }
            nodes.swap(childs);            
        }
        
        return depth;
    }
    
    int maxDepthRecv(Node* root) {
        if (!root) {
            return 0;
        }
        
        int maxDepth = 1;
        for (Node* node : root->children) {
            
            maxDepth = max(maxDepth, 1 + maxDepthRecv(node));
        }
        
        return maxDepth;
    }
    
    int maxDepth(Node* root) {
        return maxDepthIter(root);
        //return maxDepthRecv(root);
    }
};
