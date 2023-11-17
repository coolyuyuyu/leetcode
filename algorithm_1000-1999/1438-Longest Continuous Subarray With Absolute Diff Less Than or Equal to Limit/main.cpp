class Solution {
public:
    // Time: O(nlogn)
    int byMultiSet(vector<int>& nums, int limit) {
        int n = nums.size();

        multiset<int> ms;

        int ret = 0;
        for (int lft = 0, rht = 0; rht < n; ++lft) {
            for (; rht < n && (ms.empty() || (std::max(nums[rht], *ms.rbegin()) -  std::min(nums[rht], *ms.begin())) <= limit); ++rht) {
                ms.insert(nums[rht]);
            }

            ret = std::max(ret, rht - lft);

            ms.erase(ms.find(nums[lft]));
        }

        return ret;
    }

    // Time: O(n)
    int byDeque(vector<int>& nums, int limit) {
        int n = nums.size();

        deque<int> dqMax, dqMin;

        int ret = 0;
        for (int lft = 0, rht = 0; rht < n; ++lft) {
            for (; rht < n && (dqMax.empty() || (std::max(nums[rht], nums[dqMax.front()]) -  std::min(nums[rht], nums[dqMin.front()])) <= limit); ++rht) {
                while (!dqMax.empty() && nums[dqMax.back()] <= nums[rht]) {
                    dqMax.pop_back();
                }
                dqMax.push_back(rht);
                while (!dqMin.empty() && nums[dqMin.back()] >= nums[rht]) {
                    dqMin.pop_back();
                }
                dqMin.push_back(rht);
            }

            ret = std::max(ret, rht - lft);

            if (dqMax.front() == lft) {
                dqMax.pop_front();
            }
            if (dqMin.front() == lft) {
                dqMin.pop_front();
            }
        }

        return ret;
    }

    int longestSubarray(vector<int>& nums, int limit) {
        //return byMultiSet(nums, limit);
        return byDeque(nums, limit);
    }
};
