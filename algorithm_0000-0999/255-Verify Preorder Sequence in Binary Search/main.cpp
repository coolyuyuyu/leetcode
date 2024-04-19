class Solution {
public:

    // Time: O(NlogN)
    bool dfs(vector<int>& preorder) {
        std::function<bool(int, int)> f = [&](int lft, int rht) {
            if (lft >= rht) {
                return true;
            }

            int root = preorder[lft];
            int mid;
            for (mid = lft + 1; mid <= rht; ++mid) {
                if (preorder[mid] > root) {
                    break;
                }
            }
            for (int i = mid; i <= rht; ++i) {
                if (preorder[i] < root) {
                    return false;;
                }
            }

            return f(lft + 1, mid - 1) && f(mid, rht);
        };

        return f(0, preorder.size() - 1);
    }

    // Time: O(N)
    bool linear(vector<int>& preorder) {
        int root = INT_MIN;
        stack<int> stk;
        for (int val : preorder) {
            if (val < root) {
                return false;
            }

            while (!stk.empty() && val > stk.top()) {
                root = stk.top();
                stk.pop();
            }
            stk.push(val);
        }

        return true;
    }

    bool verifyPreorder(vector<int>& preorder) {
        //return dfs(preorder);
        return linear(preorder);
    }
};
