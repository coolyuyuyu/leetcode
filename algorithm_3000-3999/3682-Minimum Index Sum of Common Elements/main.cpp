class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num2idx;
        for (int i = 0; i < nums1.size(); ++i) {
            num2idx.emplace(nums1[i], i);
        }

        int ret = INT_MAX;
        for (int j = 0; j < nums2.size(); ++j) {
            auto itr = num2idx.find(nums2[j]);
            if (itr != num2idx.end()) {
                ret = std::min(ret, itr->second + j);
            }
        }

        return ret < INT_MAX ? ret : -1;
    }
};
