/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {       
        unordered_map<RandomListNode*, RandomListNode*> hash;
        pair<unordered_map<RandomListNode*, RandomListNode*>::iterator, bool> p;

        RandomListNode* pHead = NULL;
        RandomListNode** ppCur = &pHead;
        while (head) {
            p = hash.insert(make_pair(head, (RandomListNode*)NULL));
            if (p.second) {
                p.first->second = new RandomListNode(head->label);
            }
            *ppCur = p.first->second;

            if (head->random) {
                p = hash.insert(make_pair(head->random, (RandomListNode*)NULL));
                if (p.second) {
                    p.first->second = new RandomListNode(head->random->label);
                }
                (*ppCur)->random = p.first->second;
            }

            head = head->next;
            ppCur = &((*ppCur)->next);
        }
        
        return pHead;
    }
};