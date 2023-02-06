class Solution {
public:
    int find_bruteforce(const vector<int>& nums1, int pos, const vector<int>& nums2) {
        for (; (pos + nums2.size()) <= nums1.size(); ++pos) {
            if (std::equal(nums1.begin() + pos, nums1.begin() + pos + nums2.size(), nums2.begin())) {
                return pos;
            }
        }

        return -1;
    }

    int find_kmp(const vector<int>& nums1, int pos, const vector<int>& nums2) {
        if (nums1.size() <= pos) {
            return -1;
        }
        if (nums2.empty()) {
            return pos;
        }

        if (nums1[pos] == nums2[0] && nums2.size() == 1) {
            return pos;
        }

        // suffix[i]: the longest length k such that nums2[0:k-1] == nums2[i-k+1:i]
        vector<size_t> suffix(nums2.size());
        suffix[0] = 0;
        for (size_t i = 1; i < nums2.size(); ++i) {
            size_t j = suffix[i - 1];
            while (0 < j && nums2[j] != nums2[i]) {
                j = suffix[j - 1];
            }
            suffix[i] = j + (nums2[j] == nums2[i] ? 1 : 0);
        }

        // dp[i]: the longest length k such that nums2[0:k-1] == nums1[i-k+1:i]
        int dp = (nums2[0] == nums1[pos] ? 1 : 0);
        for (size_t i = pos + 1; i < nums1.size(); ++i) {
            size_t j = dp;
            while (0 < j && nums2[j] != nums1[i]) {
                j = suffix[j - 1];
            }
            dp = j +(nums2[j] == nums1[i] ? 1 : 0);
            if (dp == nums2.size()) {
                return i + 1 - nums2.size();
            }
        }

        return -1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0;
        for (const vector<int>& group : groups) {

            //pos = find_bruteforce(nums, pos, group);
            pos = find_kmp(nums, pos, group);

            if (pos == -1) {
                return false;
            }
            pos += group.size();
        }

        return true;
    }
};
