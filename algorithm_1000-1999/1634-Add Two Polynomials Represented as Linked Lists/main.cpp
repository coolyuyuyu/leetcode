/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* pHead = nullptr;
        PolyNode** ppNode = &pHead;
        while (poly1 && poly2) {
            if (poly1->power < poly2->power) {
                *ppNode = new PolyNode(poly2->coefficient, poly2->power);
                ppNode = &((*ppNode)->next);
                poly2 = poly2->next;
            }
            else if (poly1->power == poly2->power) {
                if (poly1->coefficient + poly2->coefficient != 0) {
                    *ppNode = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
                    ppNode = &((*ppNode)->next);
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else {
                *ppNode = new PolyNode(poly1->coefficient, poly1->power);
                ppNode = &((*ppNode)->next);
                poly1 = poly1->next;
            }
        }
        for (PolyNode* poly = (poly1 ? poly1 : poly2); poly; poly = poly->next) {
            *ppNode = new PolyNode(poly->coefficient, poly->power);
            ppNode = &((*ppNode)->next);
        }

        return pHead;
    }
};
