class Solution {
public:
    struct TrieNode {
        TrieNode() {
            nexts.fill(nullptr);
        }

        std::array<TrieNode*, 2> nexts;
    };

    int trieDFS(TrieNode* node, int num, int i) {
        if (!node) {
            return -1;
        }
        if (i < 0) {
            return 0;
        }

        int b = (num >> i) & 1;
        if (b == 0) {
            int ans1 = trieDFS(node->nexts[1], num, i - 1);
            if (ans1 != -1) {
                return ans1 + (1 << i);
            }
            int ans0 = trieDFS(node->nexts[0], num, i - 1);
            if (ans0 != -1) {
                return ans0;
            }
        }
        else {
            int ans0 = trieDFS(node->nexts[0], num, i - 1);
            if (ans0 != -1) {
                return ans0;
            }
        }

        return -1;
    }

    long long byTrie(vector<int>& nums) {
        int m = 32 - __builtin_clz(*std::max_element(nums.begin(), nums.end()));

        TrieNode* root = new TrieNode();

        std::function<void(int)> addTrie = [&](int num) {
            TrieNode* node = root;
            for (int i = m; 0 < i--;) {
                int b = (num >> i) & 1;
                if (node->nexts[b] == nullptr) {
                    node->nexts[b] = new TrieNode();
                }
                node = node->nexts[b];
            }
        };

        long long ret = 0;
        for (int x : nums) {
            int y = trieDFS(root, x, m - 1);
            if (y != -1) {
                ret = std::max(ret, 1LL * x * y);
            }
            addTrie(x);
        }

        return ret;
    }

    long long byDP(vector<int>& nums) {
        int m = 32 - __builtin_clz(*std::max_element(nums.begin(), nums.end()));
        // dp[mask]: the maximum element from nums such that element is a submask of mask
        int dp[1 << m];
        for (int mask = 0; mask < (1 << m); ++mask) {
            dp[mask] = 0;
        }
        for (int num : nums) {
            dp[num] = num;
        }

        for (int mask = 1; mask < (1 << m); ++mask) {
            for (int i = 0; i < m; ++i) {
                if ((mask >> i) & 1) {
                    dp[mask] = std::max(dp[mask], dp[mask & ~(1 << i)]);
                }
            }
        }

        long long ret = 0;
        for (int x : nums) {
            ret = std::max(ret, 1LL * x * dp[((1 << m) - 1) ^x]);
        }
        return ret;
    }

    long long maxProduct(vector<int>& nums) {
        //return byTrie(nums);
        return byDP(nums);
    }
};
