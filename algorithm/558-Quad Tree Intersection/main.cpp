/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }
        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }

        Node* topLft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRht = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* btmLft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* btmRht = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (topLft->isLeaf
            && topRht->isLeaf
            && btmLft->isLeaf
            && btmRht->isLeaf
            && topLft->val == topRht->val
            && topRht->val == btmLft->val
            && btmLft->val == btmRht->val) {
            return new Node(topLft->val, true, topLft, topRht, btmLft, btmRht);
        }
        else {
            return new Node(false, false, topLft, topRht, btmLft, btmRht);
        }
    }
};