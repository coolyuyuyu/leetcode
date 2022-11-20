class Solution {
public:
    // Time: O(n^3)
    int bruteforce(vector<int>& nums) {
        size_t n = nums.size();

        int cnt = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    continue;;
                }

                for (size_t k = j + 1; k < n; ++k) {
                    if (nums[i] == nums[k] || nums[j] == nums[k]) {
                        continue;;
                    }
                    ++cnt;
                }
            }
        }

        return cnt;
    }

    // Time: O(nlogn)
    int bysort(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        size_t n = nums.size();

        int cnt = 0;
        for (size_t i = 0; i < n; ++i) {
            int cnt1 = 1;
            for (; (i + 1) < n && nums[i] == nums[i + 1]; ++i) {
                ++cnt1;
            }

            for (size_t j = i + 1; j < n; ++j) {
                int cnt2 = 1;
                for (; (j + 1) < n && nums[j] == nums[j + 1]; ++j) {
                    ++cnt2;
                }

                cnt += (cnt1 * cnt2 * (n - j - 1));
            }
        }

        return cnt;
    }

    // Time: O(n)
    int bycount(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        size_t n = nums.size();

        int ans = 0;
        int lft = 0, rht = nums.size();
        for (const auto& p : cnts) {
            rht -= p.second;
            ans += lft * p.second * rht;
            lft += p.second;
        }

        return ans;
    }

    int unequalTriplets(vector<int>& nums) {
        //return bruteforce(nums);
        //return bysort(nums);
        return bycount(nums);
    }
};
