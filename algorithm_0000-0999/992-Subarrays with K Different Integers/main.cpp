class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        std::function<int(int)> subarraysWithAtmostKDistinct = [&](int k) {
            unordered_map<int, int> freq;

            int ret = 0;
            for (int lft = 0, rht = 0, cnt = 0; rht < n; ++rht) {
                if (++freq[nums[rht]] == 1) {
                    ++cnt;
                }

                for (; cnt > k; ++lft) {
                    if (--freq[nums[lft]] == 0) {
                        --cnt;
                    }
                }

                ret += rht - lft + 1;
            }

            return ret;
        };

        return subarraysWithAtmostKDistinct(k) - subarraysWithAtmostKDistinct(k - 1);
    }
};
