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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for (ListNode* node = head; node; node = node->next) {
            ++len;
        }

        std::function<ListNode*(ListNode* head, int cnt)> splitList = [](ListNode* head, int k) {
            ListNode** ppNode = &head;
            while (k-- && *ppNode)  {
                ppNode = &((*ppNode)->next);
            }

            ListNode* pRet = *ppNode;
            *ppNode = nullptr;
            return pRet;
        };

        vector<ListNode*> ret(k);
        for (int i = 0; i < k; ++i) {
            ret[i] = head;
            head = splitList(head, len / k + (i < len % k ? 1 : 0));
        }

        return ret;
    }
};
