class Solution {
public:
    // Time: O(nk), TLE
    vector<int> byBruteForce(vector<int>& nums, int k) {
        vector<int> ret(nums.size() - k + 1);
        for (int i = 0; i + k <= nums.size(); ++i) {
            ret[i] = *std::max_element(nums.begin() + i, nums.begin() + i + k);
        }

        return ret;
    }

    // Time: O(nlogk)
    vector<int> byMultiSet(vector<int>& nums, int k) {
        multiset<int> ms;

        vector<int> ret(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (k <= i) {
                ms.erase(ms.find(nums[i - k]));
            }
            ms.insert(nums[i]);
            if (k - 1 <= i) {
                ret[i - k + 1] = *ms.rbegin();
            }
        }

        return ret;
    }

    // Time: O(n)
    vector<int> byDeque(vector<int>& nums, int k) {
        deque<int> dq;

        vector<int> ret(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (k - 1 <= i) {
                ret[i - k + 1] = nums[dq.front()];
            }
        }

        return ret;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //return byBruteForce(nums, k);
        //return byMultiSet(nums, k);
        return byDeque(nums, k);
    }
};
