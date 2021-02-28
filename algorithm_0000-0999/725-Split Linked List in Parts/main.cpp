/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* splitList(ListNode* head, int k) {
        ListNode** ppCur = &head;
        while (*ppCur && 0 < k--) {
            ppCur = &((*ppCur)->next);
        }

        ListNode* headLeft = *ppCur;
        *ppCur = nullptr;
        return headLeft;
    }

    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        assert(0 < k);

        int size = 0;
        for (ListNode* pCur = root; pCur; pCur = pCur->next) {
            ++size;
        }

        vector<ListNode*> parts(k, nullptr);
        parts[0] = root;
        for (int i = 1; i < k; ++i) {
            int count = size / k + (i <= (size % k) ? 1 : 0);
            parts[i] = splitList(parts[i - 1], count);
        }

        return parts;
    }
};