class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* pRoot = buildTrie(nums);

        int ans = 0;
        for (int num : nums) {
            int val = 0;
            TrieNode* pNode = pRoot;
            for (int i = 31; 0 <= i; --i) {
                int bit = (num >> i) & 1;
                if (pNode->childs[bit ^ 1]) {
                    pNode = pNode->childs[bit ^ 1];
                    val += (1 << i);
                }
                else {
                    pNode = pNode->childs[bit];
                }
            }

            ans = max(ans, val);
        }

        return ans;
    }
private:
    class TrieNode {
    public:
        TrieNode()
            : childs(2, nullptr) {
        }

        vector<TrieNode*> childs;
    };

    TrieNode* buildTrie(const vector<int>& nums) {
        TrieNode* pRoot = new TrieNode();
        for (int num : nums) {
            insertTrie(pRoot, num);
        }

        return pRoot;
    }

    void insertTrie(TrieNode* pRoot, int num) {
        TrieNode** ppNode = &pRoot;
        for (int i = 31; 0 <= i; --i) {
            ppNode = &((*ppNode)->childs[(num >> i) & 1]);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode();
            }
        }
    }
};