class Solution {
public:
    // Time: O(NlogN)
    bool recursive(const vector<int>& preorder) {
        std::function<bool(int, int)> dfs = [&](int lo, int hi) {
            if (lo >= hi) {
                return true;
            }

            int root = preorder[lo];
            int mid = lo + 1;
            while  (mid <= hi && preorder[mid] < root) {
                ++mid;
            }

            for (int i = mid + 1; i <= hi; ++i) {
                if (preorder[i] < root) {
                    return false;
                }
            }

            return dfs(lo + 1, mid - 1) && dfs(mid, hi);
        };

        return dfs(0, preorder.size() - 1);
    }

    // Time: O(N)
    bool iterative(const vector<int>& preorder) {
        stack<int> stk;
        int root = INT_MIN;
        for (int val : preorder) {
            if (val < root) { return false; }
            while (!stk.empty() && val > stk.top()  ) {
                root = stk.top();
                stk.pop();
            }
            stk.push(val);
        }

        return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
        //return recursive(preorder);
        return iterative(preorder);
    }
};
