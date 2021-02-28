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
private:
    ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode** ppCur = &head;
        while (l1 && l2) {
            ListNode** ppNode = &(l1->val <= l2->val ? l1 : l2);
            *ppCur = *ppNode;
            *ppNode = (*ppNode)->next;

            ppCur = &((*ppCur)->next);
        }
        *ppCur = (l1 ? l1 : l2);

        return head;
    }

    ListNode* splitList(ListNode* head, size_t k) {
        ListNode** ppCur = &head;
        while (*ppCur && 0 < k--) {
            ppCur = &((*ppCur)->next);
        }

        ListNode* headLeft = *ppCur;
        *ppCur = nullptr;
        return headLeft;
    }

    ListNode* mergeSortedList(ListNode* l1, ListNode* l2, ListNode**& ppTail) {
        assert(l1 || l2);

        ListNode* head = nullptr;
        ListNode** ppCur = &head;
        while (l1 && l2) {
            ListNode** ppNode = &(l1->val <= l2->val ? l1 : l2);
            *ppCur = *ppNode;
            *ppNode = (*ppNode)->next;

            ppCur = &((*ppCur)->next);
        }
        *ppCur = (l1 ? l1 : l2);

        while (*ppCur) {
            ppCur = &((*ppCur)->next);
        }
        ppTail = ppCur;

        return head;
    }

public:
    ListNode* quicksortList(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        if (pHead->next == nullptr) {
            return pHead;
        }

        ListNode* pPivot = nullptr; {
            ListNode* pFast = pHead;
            ListNode* pSlow = pHead;
            while (pFast && pFast->next) {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
            }
            pPivot = pSlow;
        }

        ListNode* pHead1 = nullptr;
        ListNode** ppCur1 = &pHead1;
        ListNode* pHead2 = nullptr;
        ListNode** ppCur2 = &pHead2;

        ListNode* pCur = pHead;
        while (pCur) {
            if (pCur != pPivot) {
                if (pCur->val < pPivot->val) {
                    *ppCur1 = pCur;
                    ppCur1 = &((*ppCur1)->next);
                }
                else {
                    *ppCur2 = pCur;
                    ppCur2 = &((*ppCur2)->next);
                }
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

    void quicksortListV2(ListNode* pHead, ListNode*& pHeadNew, ListNode**& ppTailNew) {
        if (pHead == nullptr) {
            pHeadNew = *ppTailNew = nullptr;
            return;
        }
        if (pHead->next == nullptr) {
            pHeadNew = pHead;
            ppTailNew = &(pHead->next);
            return;
        }

        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        while (pFast && pFast->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        ListNode* pPivot = pSlow;

        ListNode* pHead1 = nullptr;
        ListNode** ppCur1 = &pHead1;
        ListNode* pHead2 = nullptr;
        ListNode** ppCur2 = &pHead2;

        ListNode* pCur = pHead;
        while (pCur) {
            if (pCur != pPivot) {
                if (pCur->val < pPivot->val) {
                    *ppCur1 = pCur;
                    ppCur1 = &((*ppCur1)->next);
                }
                else {
                    *ppCur2 = pCur;
                    ppCur2 = &((*ppCur2)->next);
                }
            }
            pCur = pCur->next;
        }
        *ppCur1 = NULL;
        *ppCur2 = NULL;

        ListNode* pHeadLo;
        ListNode* pTailLo;
        ListNode** ppTailLo = &pTailLo;
        quicksortListV2(pHead1, pHeadLo, ppTailLo);

        ListNode* pHeadHi;
        ListNode* pTailHi;
        ListNode** ppTailHi = &pTailHi;
        quicksortListV2(pHead2, pHeadHi, ppTailHi);

        if (pHeadLo) {
            pHeadNew = pHeadLo;
            *ppTailLo = pPivot;
        }
        else {
            pHeadNew = pPivot;
        }

        pPivot->next = pHeadHi;

        if (pHeadHi) {
            ppTailNew = ppTailHi;
        }
        else {
            ppTailNew = &(pPivot->next);
        }
    }

    // Time: O(nlog(n)), Space: O(log(n))
    ListNode* mergesort_TopDown(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }

        ListNode** ppFast = &head;
        ListNode** ppSlow = &head;
        while (*ppFast && (*ppFast)->next) {
            ppFast = &((*ppFast)->next->next);
            ppSlow = &((*ppSlow)->next);
        }

        ListNode* head1 = head;
        ListNode* head2 = *ppSlow;
        *ppSlow = nullptr;

        return mergeSortedList(mergesort_TopDown(head1), mergesort_TopDown(head2));
    }

    // Time: O(nlog(n)), Space: O(n)
    ListNode* mergesort_BottomUpQueue(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        queue<ListNode*> lists;
        for (ListNode* pCur = head; pCur;) {
            ListNode* pNode = pCur;
            pCur = pCur->next;

            pNode->next = nullptr;
            lists.emplace(pNode);
        }

        while (1 < lists.size()) {
            ListNode* l1 = lists.front();
            lists.pop();
            ListNode* l2 = lists.front();
            lists.pop();

            lists.emplace(mergeSortedList(l1, l2));
        }

        return lists.front();
    }

    // Time: O(nlog(n)), Space: O(n)
    ListNode* mergesort_BottomUpArray(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        vector<ListNode*> lists;
        for (ListNode* pCur = head; pCur;) {
            ListNode* pNode = pCur;
            pCur = pCur->next;

            pNode->next = nullptr;
            lists.emplace_back(pNode);
        }

        for (size_t height = ceil(log2(lists.size())), step = 2; 0 < height; --height, step *= 2) {
            for (size_t i = 0; (i + step / 2) < lists.size(); i += step) {
                lists[i] = mergeSortedList(lists[i], lists[i + step / 2]);
            }
        }

        return lists.front();
    }

    // Time: O(nlog(n)), Space: O(n)
    ListNode* mergesort_BottomUpHeap(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        auto comp = [](const pair<ListNode*, size_t>& lft, const pair<ListNode*, size_t>& rht) { return rht.second < lft.second; };
        priority_queue<pair<ListNode*, size_t>, vector<pair<ListNode*, size_t>>, decltype(comp)> pq(comp);
        for (ListNode* pCur = head; pCur;) {
            ListNode* pNode = pCur;
            pCur = pCur->next;

            pNode->next = nullptr;
            pq.emplace(pNode, 1);
        }

        while (1 < pq.size()) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            pq.emplace(mergeSortedList(p1.first, p2.first), p1.second + p2.second);
        }

        return pq.top().first;
    }

    // Time: O(nlog(n)), Space: O(1)
    ListNode* mergesort_BottomUpInplace(ListNode* head) {
        size_t size = 0;
        for (ListNode* pCur = head; pCur; pCur = pCur->next) {
            ++size;
        }

        for (size_t count = 1; count < size; count *= 2) {
            ListNode** ppCur = &head;
            while (*ppCur) {
                ListNode* pLft = *ppCur;
                ListNode* pRht = splitList(pLft, count);
                ListNode* pPending = splitList(pRht, count);

                ListNode** ppTail;
                *ppCur = mergeSortedList(pLft, pRht, ppTail);
                *ppTail = pPending;

                ppCur = ppTail;
            }
        }

        return head;
    }

    ListNode* sortList(ListNode* head) {
        //return quicksortList(head);

        /*
        ListNode* pHeadNew = nullptr;
        ListNode* pTailNew = nullptr;
        ListNode** ppTailNew = &pTailNew;
        quicksortListV2(head, pHeadNew, ppTailNew);
        return pHeadNew;
        */

        //return mergesort_TopDown(head);
        //return mergesort_BottomUpQueue(head);
        //return mergesort_BottomUpArray(head);
        //return mergesort_BottomUpHeap(head);
        return mergesort_BottomUpInplace(head);
    }
};