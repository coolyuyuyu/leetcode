class Solution {
public:
    // Time: O(NK)
    vector<int> bruteForce(vector<int>& nums, int k) {
        vector<int> ret;
        for (int i = 0; (i + k) <= nums.size(); ++i) {
            ret.push_back(*std::max_element(nums.begin() + i, nums.begin() + i + k));
        }

        return ret;
    }

    // TimeL O(NlogK)
    vector<int> orderedTree(vector<int>& nums, int k) {
        multiset<int> ms;

        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            ms.insert(nums[i]);
            if (k < ms.size()) {
                ms.erase(ms.find(nums[i - k]));
            }

            if (ms.size() == k) {
                ret.push_back(*ms.rbegin());
            }
        }

        return ret;
    }

    // Time: O(N)
    vector<int> monoQueue(vector<int>& nums, int k) {
        deque<int> dq;

        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (!dq.empty() && dq.front() <= (i - k)) {
                dq.pop_front();
            }

            if (k <= (i + 1)) {
                ret.push_back(nums[dq.front()]);
            }
        }
        return ret;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //return bruteForce(nums, k);
        //return orderedTree(nums, k);
        return monoQueue(nums, k);
    }
};
