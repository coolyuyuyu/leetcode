class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int>& nums = nums1;
        for (int i = 0; i < n; ++i) {
            nums[i] = nums1[i] - nums2[i];
        }

        int ret = 0;
        unordered_map<int, int> m; // presum -> smallest index
        m[0] = -1;
        for (int presum = 0, i = 0; i < n; ++i) {
            presum += nums[i];
            auto p = m.emplace(presum, i);
            if (p.second == false) {
                ret = std::max(ret, i - p.first->second);
            }
        }

        return ret;
    }
};

/*
X X X X X X X
    j       i
presum[i] - prefix[j] = sum(j+1:i) = 0
=> presum[i] = presum[j], len = i - j
*/
