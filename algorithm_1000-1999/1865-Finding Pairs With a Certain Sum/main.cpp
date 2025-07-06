class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : m_nums2(nums2) {
        for (int num1 : nums1) {
            ++m_cnts1[num1];
        }
        for (int num2 : nums2) {
            ++m_cnts2[num2];
        }
    }

    void add(int index, int val) {
        int num2Old = m_nums2[index];
        m_nums2[index] += val;
        int num2New = m_nums2[index];

        m_cnts2[num2Old] -= 1;
        m_cnts2[num2New] += 1;
    }

    int count(int tot) {
        int ret = 0;
        for (const auto& [num1, cnt1] : m_cnts1) {
            if (m_cnts2.find(tot - num1) == m_cnts2.end()) { continue; }
            ret += (m_cnts2[tot - num1] * cnt1);
        }

        return ret;
    }

private:
    unordered_map<int, int> m_cnts1;
    vector<int> m_nums2;
    unordered_map<int, int> m_cnts2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
