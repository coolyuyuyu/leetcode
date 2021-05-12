class Solution {
public:
    int specialArray_BruteForce(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto check = [&nums](int x) {
            for (int i = 0; i < nums.size(); ++i) {
                if (x <= nums[i]) {
                    return ((nums.size() - i) == x);
                }
            }

            return false;
        };
        for (int i = 0; i <= nums.size(); ++i) {
            if (check(i)) {
                return i;
            }
        }

        return -1;
    }

    int specialArray_BruteForce_Search(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto check = [&nums](int x) {
            auto itr = lower_bound(nums.begin(), nums.end(), x);
            return (distance(itr, nums.end()) == x);
        };
        for (int i = 0; i <= nums.size(); ++i) {
            if (check(i)) {
                return i;
            }
        }

        return -1;
    }

    int specialArray_CountingSort(vector<int>& nums) {
        vector<int> counts(102, 0);
        int n = nums.size();
        for (int num : nums) {
            ++counts[min(num, n)];
        }
        for (int i = n; i >= 0; --i) {
            counts[i] += counts[i + 1];
            if (counts[i] == i) {
                return i;
            }
        }

        return -1;
    }

    int specialArray(vector<int>& nums) {
        // Time: O(N^2)
        // return specialArray_BruteForce(nums);

        // Time: O(NlogN)
        // return specialArray_BruteForce_Search(nums);

        // Time: O(N)
        return specialArray_CountingSort(nums);
    }
};