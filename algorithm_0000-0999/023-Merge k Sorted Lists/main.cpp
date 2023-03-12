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

    // skew merge tree
    ListNode* mergeKListsOneByOne(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        for (size_t i = 1; i < lists.size(); ++i) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists.front();
    }

    // balanced merge tree
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

    // balanced merge tree with least comparison.
    ListNode* mergeKListsByAlwaysMerge2Shortest(vector<ListNode*>& lists) {
        auto comp = [](const pair<ListNode*, size_t>& lft, const pair<ListNode*, size_t>& rht) { return rht.second < lft.second; };
        priority_queue<pair<ListNode*, size_t>, vector<pair<ListNode*, size_t>>, decltype(comp)> pq(comp);
        for (ListNode* head : lists) {
            size_t size = 0;
            for (ListNode* node = head; node; node = node->next) {
                ++size;
            }
            if (0 < size) {
                pq.push(pair<ListNode*, size_t>(head, size));
            }
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

    ListNode* mergeKListsByMinHeap(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* pNode1, const ListNode* pNode2) { return pNode1->val > pNode2->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (ListNode* pHead : lists) {
            if (pHead) {
                pq.push(pHead);
            }
        }

        ListNode *pHead = nullptr;
        for (ListNode **ppNode = &pHead; !pq.empty();) {
            *ppNode = pq.top();
            pq.pop();

            ppNode = &((*ppNode)->next);
            if (*ppNode) {
                pq.push(*ppNode);
            }
        }

        return pHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //return mergeKListsOneByOne(lists);
        //return mergeKListsBottomUpMerge(lists);
        //return mergeKListsByAlwaysMerge2Shortest(lists);

        return mergeKListsByMinHeap(lists);
    }
};
