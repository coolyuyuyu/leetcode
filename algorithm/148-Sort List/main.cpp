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

    // Min Heap is overkilled. The list of length N is already broken into N 1-lenth lists.
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

        ListNode* pHeadNew = nullptr;
        ListNode* pTailNew = nullptr;
        ListNode** ppTailNew = &pTailNew;
        quicksortListV2(head, pHeadNew, ppTailNew);
        return pHeadNew;

        //return mergesortListMergeByMinHeap(head);
        //return mergesortListBottomUpMerge(head);
    }
};