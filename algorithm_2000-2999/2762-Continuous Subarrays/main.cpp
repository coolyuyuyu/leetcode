class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        deque<int> dqMax, dqMin;

        std::function<bool(int)> check = [&](int rht) {
            if (dqMax.empty()) { return true; }
            return std::max(nums[dqMax.front()], nums[rht]) - std::min(nums[dqMin.front()], nums[rht]) <= 2;
        };

        long long ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && check(rht); ++rht) {
                while (!dqMax.empty() && nums[dqMax.back()] <= nums[rht]) {
                    dqMax.pop_back();
                }
                dqMax.push_back(rht);

                while (!dqMin.empty() && nums[dqMin.back()] >= nums[rht]) {
                    dqMin.pop_back();
                }
                dqMin.push_back(rht);
            }

            ret += (rht - lft);

            if (!dqMax.empty() && dqMax.front() == lft) {
                dqMax.pop_front();
            }
            if (!dqMin.empty() && dqMin.front() == lft) {
                dqMin.pop_front();
            }
        }

        return ret;
    }
};
