class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        deque<int> maxDeque, minDeque;
        auto check = [&](int rht) {
            int maxVal = std::max(nums[rht], maxDeque.empty() ? INT_MIN : nums[maxDeque.front()]);
            int minVal = std::min(nums[rht], minDeque.empty() ? INT_MAX : nums[minDeque.front()]);
            return (maxVal - minVal) <= 2;
        };

        long long ret = 0;
        for (int lft = 0, rht = 0; lft < n; ++lft) {
            for (; rht < n && check(rht); ++rht) {
                while (!maxDeque.empty() && nums[maxDeque.back()] < nums[rht]) {
                    maxDeque.pop_back();
                }
                maxDeque.push_back(rht);

                while (!minDeque.empty() &&  nums[minDeque.back()] > nums[rht]) {
                    minDeque.pop_back();
                }
                minDeque.push_back(rht);
            }

            ret += (rht - lft);

            if (!maxDeque.empty() && maxDeque.front() <= lft) {
                maxDeque.pop_front();
            }
            if (!minDeque.empty() && minDeque.front() <= lft) {
                minDeque.pop_front();
            }
        }

        return ret;
    }
};
