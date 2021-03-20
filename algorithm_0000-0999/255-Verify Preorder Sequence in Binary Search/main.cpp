class Solution {
public:
    bool verifyPreorder_Recursive(vector<int>::const_iterator first, vector<int>::const_iterator last) {
        assert(first <= last);
        if (distance(first, last) <= 2) {
            return true;
        }

        int root = *first;

        vector<int>::const_iterator lftFirst = ++first, lftLast = lftFirst;
        for (; lftLast != last && *lftLast < root; ++lftLast) {
        }

        vector<int>::const_iterator rhtFirst = lftLast, rhtLast = rhtFirst;
        for (; rhtLast != last && root < *rhtLast; ++rhtLast) {
        }

        return rhtLast == last && verifyPreorder_Recursive(lftFirst, lftLast) && verifyPreorder_Recursive(rhtFirst, rhtLast);
    }

    bool verifyPreorder_Iterative(vector<int>& preorder) {
        int tmp;
        int* pRootVal = nullptr;

        stack<int> stk;
        for (int num : preorder) {
            if (pRootVal && num < *pRootVal) {
                return false;
            }

            while (!stk.empty() && stk.top() < num) {
                if (!pRootVal) {
                    pRootVal = &tmp;
                }
                *pRootVal = stk.top();

                stk.pop();
            }

            stk.push(num);
        }

        return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
        //return verifyPreorder_Recursive(preorder.begin(), preorder.end());
        return verifyPreorder_Iterative(preorder);
    }
};