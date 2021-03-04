class Solution {
public:
    bool verifyPreorderHelper(vector<int>::const_iterator first, vector<int>::const_iterator last) {
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

        return rhtLast == last && verifyPreorderHelper(lftFirst, lftLast) && verifyPreorderHelper(rhtFirst, rhtLast);
    }

    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorderHelper(preorder.begin(), preorder.end());
    }
};