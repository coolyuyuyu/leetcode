class Solution {
public:
    class TreeNode {
    public:
        TreeNode(int v)
            : lft(nullptr)
            , rht(nullptr)
            , val(v) {}
        TreeNode* lft;
        TreeNode* rht;
        int val;
    };

    int M = 1e9 + 7;

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        TreeNode* root = nullptr;
        for (int num : nums) {
            TreeNode** ppNode = &root;
            while (*ppNode) {
                ppNode = &(num < (*ppNode)->val ? (*ppNode)->lft : (*ppNode)->rht);
            }
            *ppNode = new TreeNode(num);
        }

        // dp[n][r]: combination C(n, r)
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = -1;
            }
        }
        std::function<int(int, int)> comb = [&] (int n, int r) {
            if (n - r < r) {
                return comb(n, n - r);
            }
            else if (r == 0) {
                return 1;
            }
            else if (r == 1) {
                return n;
            }

            int& ret = dp[n][r];
            if (ret < 0) {
                ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % M;
            }

            return ret;
        };

        std::function<pair<int, long>(TreeNode*)> dfs = [&](TreeNode* root) -> pair<int, long> {
            if (!root) { return {0, 1}; }
            auto [lftNodeCnt, lftSeqCnt] = dfs(root->lft);
            auto [rhtNodeCnt, rhtSeqCnt] = dfs(root->rht);
            int nodeCnt = lftNodeCnt + 1 + rhtNodeCnt;
            long seqCnt = (lftSeqCnt * rhtSeqCnt) % M * comb(lftNodeCnt + rhtNodeCnt, lftNodeCnt) % M;
            return {nodeCnt, seqCnt};
        };
        auto [_, seqCnt] = dfs(root);

        return seqCnt - 1;
    }
};
