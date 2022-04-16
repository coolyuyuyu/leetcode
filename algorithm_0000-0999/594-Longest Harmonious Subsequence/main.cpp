class Solution {
public:
    // Time: O(NlogN), Space: O(N), Loop twice
    int findLHS_count1(vector<int>& nums) {
        map<int, size_t> cnts;
        for (int num : nums) {
            ++cnts[num];
        }

        size_t lhs = 0;
        for (auto itr1 = cnts.begin(); itr1 != cnts.end(); ++itr1) {
            auto itr2 = itr1;
            ++itr2;
            if (itr2 != cnts.end() && itr1->first + 1 == itr2->first) {
                lhs = std::max(lhs, itr1->second + itr2->second);
            }
        }

        return lhs;
    }

    // Time: O(NlogN), Space: O(N), Loop once
    int findLHS_count2(vector<int>& nums) {
        size_t lhs = 0;
        map<int, size_t> cnts;
        for (int num : nums) {
            size_t cnt = ++cnts[num];

            auto itr1 = cnts.find(num - 1);
            if (itr1 != cnts.end()) {
                lhs = std::max(lhs, cnt + itr1->second);
            }
            auto itr2 = cnts.find(num + 1);
            if (itr2 != cnts.end()) {
                lhs = std::max(lhs, cnt + itr2->second);
            }
        }

        return lhs;
    }

    // Time: O(NlogN), Space: O(1)
    int findLHS_sort(vector<int>& nums) {
        assert(!nums.empty());

        std::sort(nums.begin(), nums.end());

        size_t lhs = 0;
        for (auto pre = nums.begin(), cur = std::lower_bound(pre + 1, nums.end(), *pre + 1); cur != nums.end();) {
            auto nxt = std::lower_bound(cur + 1, nums.end(), *cur + 1);
            if (*pre + 1 == *cur) {
                lhs = std::max(lhs, size_t(nxt - pre));
            }
            pre = cur;
            cur = nxt;
        }

        return lhs;
    }

    int findLHS(vector<int>& nums) {
        //return findLHS_count1(nums);
        //return findLHS_count2(nums);

        return findLHS_sort(nums);
    }
};
