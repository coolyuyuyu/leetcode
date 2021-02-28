class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum()
        : m_pRoot(new TrieNode(0)) {
    }

    void insert(string key, int val) {
        TrieNode** ppNode = &m_pRoot;
        for (char c : key) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                *ppNode = new TrieNode(0);
            }
        }

        (*ppNode)->val = val;
    }

    int sum(string prefix) {
        TrieNode** ppNode = &m_pRoot;
        for (char c : prefix) {
            ppNode = &((*ppNode)->childs[c - 'a']);
            if (*ppNode == nullptr) {
                return 0;
            }
        }

        return sumRecv(*ppNode);
    }

private:
    class TrieNode {
    public:
        TrieNode(int v)
            : val(v)
            , childs(26, nullptr) {
        }

        vector<TrieNode*> childs;
        int val;
    };

    int sumRecv(TrieNode* pRoot) {
        if (!pRoot) {
            return 0;
        }

        int sum = pRoot->val;
        for (TrieNode* pChild : pRoot->childs) {
            sum += sumRecv(pChild);
        }

        return sum;
    }

    TrieNode* m_pRoot;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */