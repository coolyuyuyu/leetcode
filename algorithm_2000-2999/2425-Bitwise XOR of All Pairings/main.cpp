class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        if (nums2.size() & 1) {
            ret = std::accumulate(nums1.begin(), nums1.end(), ret, std::bit_xor<int>());
        }
        if (nums1.size() & 1) {
            ret = std::accumulate(nums2.begin(), nums2.end(), ret, std::bit_xor<int>());
        }

        return ret;
    }
};
