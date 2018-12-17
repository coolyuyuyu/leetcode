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
    ListNode* quicksortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }

        ListNode* pHead1 = NULL;
        ListNode** ppCur1 = &pHead1;
        ListNode* pHead2 = NULL;
        ListNode** ppCur2 = &pHead2;

        ListNode* pPivot = head;
        ListNode* pCur = pPivot->next;
        while (pCur) {
            if (pCur->val < pPivot->val) {
                *ppCur1 = pCur;
                ppCur1 = &((*ppCur1)->next);
            }
            else {
                *ppCur2 = pCur;
                ppCur2 = &((*ppCur2)->next);
            }
            pCur = pCur->next;
        }
        *ppCur1 = NULL;
        *ppCur2 = NULL;

        pHead1 = quicksortList(pHead1);
        ListNode** ppCur = &pHead1;
        while (*ppCur) {
            ppCur = &((*ppCur)->next);
        }

        *ppCur = pPivot;

        pHead2 = quicksortList(pHead2);
        pPivot->next = pHead2;

        return pHead1;
    }

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

    ListNode* mergesortListMergeByMinHeap(ListNode* head) {
        auto comp = [](const pair<ListNode*, size_t>& lft, const pair<ListNode*, size_t>& rht) { return rht.second < lft.second; };
        priority_queue<pair<ListNode*, size_t>, vector<pair<ListNode*, size_t>>, decltype(comp)> pq(comp);
        for (ListNode *prev = nullptr, *node = head; node;) {
            prev = node;
            node = node->next;

            prev->next = nullptr;
            pq.push(pair<ListNode*, size_t>(prev, 1));
        }
        if (pq.empty()) {
            return nullptr;
        }

        while (1 < pq.size()) {
            pair<ListNode*, size_t> p1 = pq.top();
            pq.pop();
            pair<ListNode*, size_t> p2 = pq.top();
            pq.pop();

            ListNode* head = mergeTwoLists(p1.first, p2.first);
            pq.emplace(head, p1.second + p2.second);
        }

        return pq.top().first;
    }

    ListNode* mergesortListBottomUpMerge(ListNode* head) {
        vector<ListNode*> lists;
        for (ListNode *prev = nullptr, *node = head; node;) {
            prev = node;
            node = node->next;

            prev->next = nullptr;
            lists.emplace_back(prev);
        }
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

    ListNode* sortList(ListNode* head) {
        //return quicksortList(head);

        //return mergesortListMergeByMinHeap(head);
        return mergesortListBottomUpMerge(head);
    }
};