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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pHead = NULL;
        ListNode** ppCur = &pHead;
        while (l1 && l2) {
            ListNode** ppNode = l1->val < l2->val ? &l1 : &l2;
            *ppCur = *ppNode;
            *ppNode = (*ppNode)->next;

            ppCur = &((*ppCur)->next);
        }

        *ppCur = l1 ? l1 : l2;

        return pHead;
    }

    ListNode* mergeKListsOneByOne(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        for (size_t i = 1; i < lists.size(); ++i) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists.front();
    }

    ListNode* mergeKListsBottomUpMerge(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        for (size_t iteration = ceil(log2(lists.size())), space = 1; iteration > 0; --iteration, space *= 2) {
            size_t step = space * 2;
            for (size_t i = 0; i + space < lists.size(); i += step) {
                lists[i] = mergeTwoLists(lists[i], lists[i + space]);
            }
        }

        return lists.front();
    }

    ListNode* mergeKListsByMinHeap(vector<ListNode*>& lists)
    {
        auto itrBgn = lists.begin(), itrEnd = lists.end();
        itrEnd = remove(itrBgn, itrEnd, nullptr);
        auto comp = [](ListNode* lft, ListNode* rht) { return lft->val > rht->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(itrBgn, itrEnd, comp);

        ListNode* pHead = nullptr;
        ListNode** ppCur = &pHead;
        while (!pq.empty()) {
            ListNode* pNode = pq.top();
            pq.pop();

            *ppCur = pNode;
            ppCur = &((*ppCur)->next);

            pNode = pNode->next;
            if (pNode) {
                pq.push(pNode);
            }
        }

        return pHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return mergeKListsByMinHeap(lists);
    }

};