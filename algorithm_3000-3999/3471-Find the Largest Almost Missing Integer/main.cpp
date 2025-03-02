class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;

        unordered_map<int, int> freq;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            ++freq[nums[i]];
            if (i - k + 1 >= 0) {
                for (const auto& [num, _] : freq) {
                    ++num2cnt[num];
                }

                if (--freq[nums[i - k + 1]] == 0) {
                    freq.erase(nums[i - k + 1]);
                }
            }
        }

        int ret = -1;
        for (const auto& [num, cnt] : num2cnt) {
            if (cnt == 1) {
                ret = std::max(ret, num);
            }
        }

        return ret;
    }
};
