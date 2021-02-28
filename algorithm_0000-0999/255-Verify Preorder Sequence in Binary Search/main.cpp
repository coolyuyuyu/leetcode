class Solution {
public:
    bool verifyPreorder(const vector<int>& preorder, size_t first, size_t last) {
        assert(first <= last);

        size_t len = last - first;
        if (len <= 1) {
            return true;
        }

        int root = preorder[first];

        size_t index = first + 1;
        for (; index < last; ++index) {
            if (root < preorder[index]) {
                break;
            }
        }
        size_t rootIndex = index;
        for (; index < last; ++index) {
            if (preorder[index] < root) {
                return false;
            }
        }

        return verifyPreorder(preorder, first + 1, rootIndex) && verifyPreorder(preorder, rootIndex, last);

    }

    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorder(preorder, 0, preorder.size());
    }
};