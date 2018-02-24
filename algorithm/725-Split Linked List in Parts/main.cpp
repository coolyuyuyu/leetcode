/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        assert(k);

        if (k == 1) {
            return vector<ListNode*>{root};
        }

        int len = 0;
        ListNode* pCur = root;
        while (pCur) {
            pCur = pCur->next;
            ++len;
        }

        vector<ListNode*> nodes(k);
        int count = len / k;
        int remaining = len % k;
        pCur = root;
        for (int i = 0; i < k && pCur; ++i) {
            nodes[i] = pCur;

            int n = count;
            if (remaining) {
                --remaining;
                ++n;
            }

            for (; n > 1; --n) {
                pCur = pCur->next;
            }

            ListNode* pNxt = pCur->next;
            pCur->next = NULL;
            pCur = pNxt;
        }

        return nodes;

    }
};