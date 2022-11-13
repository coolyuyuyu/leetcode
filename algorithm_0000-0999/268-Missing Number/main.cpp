class Solution {
public:
    int missingNumber_Sum(vector<int>& nums) {
        int cnt = nums.size();
        int sum = cnt * (cnt + 1) / 2;
        for (int num : nums) {
            sum -= num;
        }

        return sum;
    }

    int missingNumber_Bit(vector<int>& nums) {
        int target = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            target ^= i;
            target ^= nums[i];
        }

        return target;
    }

    int missingNumber_CycleSort(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] < nums.size() && nums[i] != i) {
                std::swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.size();
    }

    int missingNumber(vector<int>& nums) {
        //return missingNumber_Sum(nums);
        //return missingNumber_Bit(nums);
        return missingNumber_CycleSort(nums);
    }
};
