class Solution {
public:
    // Time: O(n), Space: O(1)
    int math(const vector<int>& nums) {
        int n = nums.size();

        int sum = (1 + n) * n / 2;
        for (int num : nums) {
            sum -= num;
        }

        return sum;
    }

    // Time: O(n), Space: O(1)
    int bit(const vector<int>& nums) {
        int n = nums.size();

        int x = 0;
        for (int i = 1; i <= n; ++i) {
            x ^= i;
        }
        for (int num : nums) {
            x ^= num;
        }

        return x;
    }

    // Time: O(n), Space: O(1)
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
