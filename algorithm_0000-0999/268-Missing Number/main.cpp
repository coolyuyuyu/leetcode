class Solution {
public:
    // Time: O(n), Space: O(1)
    int math(const vector<int>& nums) {
        int n = nums.size();

        int ret = n * (n + 1) / 2;
        for (int num : nums) {
            ret -= num;
        }

        return ret;
    }

    // Time: O(n), Space: O(1)
    int bit(const vector<int>& nums) {
        int n = nums.size();

        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            ret ^= i;
        }
        for (int num : nums) {
            ret ^= num;
        }

        return ret;
    }

    // Time: O(nlogn), Space: O(n)
    int cyclesort(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] != i && nums[i] < n) {
                std::swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                return i;
            }
        }

        return n;
    }

    int missingNumber(vector<int>& nums) {
        //return math(nums);
        //return bit(nums);
        return cyclesort(nums);
    }
};

