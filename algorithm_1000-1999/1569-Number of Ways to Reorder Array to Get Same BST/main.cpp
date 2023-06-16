class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *lft, *rht;
        TreeNode(int v)
            : val(v)
            , lft(nullptr)
            , rht(nullptr) {
        }
    };

    int M = 1e9 + 7;

    int numOfWays(vector<int>& nums) {
        TreeNode* root = nullptr;
        for (int num : nums) {
            TreeNode** ppNode = &root;
            while (*ppNode) {
                if ((*ppNode)->val < num) {
                    ppNode = &((*ppNode)->rht);
                }
                else {
                    ppNode = &((*ppNode)->lft);
                }
            }
            *ppNode = new TreeNode(num);
        }

        int cache[nums.size()][nums.size()];
        std::memset(cache, -1, sizeof(cache));
        std::function<int(int, int)> comb = [&](int n, int r) {
            if ((n - r) < r) {
                r = n - r;
            }

            if (r == 0) {
                return 1;
            }
            else if (r == 1) {
                return n;
            }

            int& ret = cache[n][r];
            if (ret < 0) {
                // C(m, n) = C(m-1, n) + C(m-1, n-1)
                ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % M;
            }

            return ret;
        };

        std::function<pair<long, int>(TreeNode*)> dfs = [&](TreeNode* root) -> pair<long, int>{
            if (!root) {
                return {1, 0};
            }

            auto [lftSeqNum, lftNodeNum] = dfs(root->lft);
            auto [rhtSeqNum, rhtNodeNum] = dfs(root->rht);
            long seqNum = lftSeqNum * rhtSeqNum % M * comb(lftNodeNum + rhtNodeNum, lftNodeNum) % M;
            int nodeNum = lftNodeNum + rhtNodeNum + 1;
            return {seqNum, nodeNum};
        };
        auto [seqNum, nodeNum] = dfs(root);
        return seqNum - 1;
    }
};
