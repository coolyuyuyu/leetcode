class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k; {
            unordered_set<int> s(nums.begin(), nums.end());
            k = s.size();
        }

        int ret = 0;
        unordered_map<int, int> cnts;
        for (int i = 0, j = 0, n = nums.size(), numDistinct = 0; i < n; ++i) {
            for (; j < n && numDistinct < k; ++j) {
                if (++cnts[nums[j]] == 1) {
                    ++numDistinct;
                }
            }

            if (numDistinct == k) {
                ret += n - j + 1;
            }

            if (--cnts[nums[i]] == 0) {
                --numDistinct;
            }
        }

        return ret;
    }
};
