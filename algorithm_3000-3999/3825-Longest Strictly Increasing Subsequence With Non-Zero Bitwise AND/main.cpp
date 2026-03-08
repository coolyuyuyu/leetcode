class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 31; ++i) {
            // longest increasing subsequence
            vector<int> lis;
            for (int num : nums) {
                if (((num >> i) & 1) == 0) { continue; }

                if (lis.empty() || lis.back() < num) {
                    lis.push_back(num);
                }
                else {
                    auto itr = std::lower_bound(lis.begin(), lis.end(), num);
                    *itr = num;
                }
            }
            ret = std::max<int>(ret, lis.size());
        }

        return ret;
    }
};
