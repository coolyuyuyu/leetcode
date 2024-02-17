class Solution {
public:
    // Time: O(3n)
    bool f1(vector<int>& nums) {
        int n = nums.size();

        int lftMins[n];
        lftMins[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            lftMins[i] = std::min(lftMins[i - 1], nums[i]);
        }

        int rhtMaxs[n];
        rhtMaxs[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rhtMaxs[i] = std::max(rhtMaxs[i + 1], nums[i]);
        }

        for (int i = 1; i + 1 < n; ++i) {
            if (lftMins[i - 1] < nums[i] && nums[i] < rhtMaxs[i + 1]) {
                return true;
            }
        }
        return false;
    }

    // Time: O(3n)
    bool f2(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis;
        for (int num : nums) {
            if (lis.empty() || lis.back() < num) {
                lis.push_back(num);
            }
            else {
                auto itr = std::lower_bound(lis.begin(), lis.end(), num);
                *itr = num;
            }

            if (lis.size() >= 3) {
                return true;
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        //return f1(nums);
        return f2(nums);
    }
};
