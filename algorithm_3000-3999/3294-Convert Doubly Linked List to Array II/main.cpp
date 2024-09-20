/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
    vector<int> toArray(Node *node){
        vector<int> ret;
        ret.push_back(node->val);
        for (Node* cur = node->prev; cur; cur = cur->prev) {
            ret.push_back(cur->val);
        }
        std::reverse(ret.begin(), ret.end());
        for (Node* cur = node->next; cur; cur = cur->next) {
            ret.push_back(cur->val);
        }

        return ret;
    }
};
