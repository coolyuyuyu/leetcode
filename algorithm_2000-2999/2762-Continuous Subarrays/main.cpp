class Solution {
public:
    long long f1(vector<int>& nums) {
        deque<int> dqMax, dqMin;

        std::function<bool(int)> check = [&](int i) {
            int maxVal = std::max((dqMax.empty() ? INT_MIN : nums[dqMax.front()]), nums[i]);
            int minVal = std::min((dqMin.empty() ? INT_MAX : nums[dqMin.front()]), nums[i]);
            return maxVal - minVal <= 2;
        };

        long long ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(); lft < n; ++lft) {
            for (; rht < n && check(rht); ++rht) {
                while (!dqMax.empty() && nums[dqMax.back()] < nums[rht]) {
                    dqMax.pop_back();
                }
                dqMax.push_back(rht);
                while (!dqMin.empty() && nums[dqMin.back()] > nums[rht]) {
                    dqMin.pop_back();
                }
                dqMin.push_back(rht);
            }

            ret += (rht - lft);

            if (dqMax.front() == lft) {
                dqMax.pop_front();
            }
            if (dqMin.front() == lft) {
                dqMin.pop_front();
            }
        }

        return ret;
    }

    long long f2(vector<int>& nums) {
        deque<int> dqMax, dqMin;

        long long ret = 0;
        for (int lft = 0, rht = 0, n = nums.size(); rht < n; ++rht) {
            while (!dqMax.empty() && nums[dqMax.back()] < nums[rht]) {
                dqMax.pop_back();
            }
            dqMax.push_back(rht);
            while (!dqMin.empty() && nums[dqMin.back()] > nums[rht]) {
                dqMin.pop_back();
            }
            dqMin.push_back(rht);

            for (; nums[dqMax.front()] - nums[dqMin.front()] > 2; ++lft) {
                if (dqMax.front() == lft) {
                    dqMax.pop_front();
                }
                if (dqMin.front() == lft) {
                    dqMin.pop_front();
                }
            }

            ret += (rht - lft + 1);
        }

        return ret;
    }

    long long continuousSubarrays(vector<int>& nums) {
        return f1(nums);
        //return f2(nums);
    }
};
