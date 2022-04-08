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

    int missingNumber(vector<int>& nums) {
        //return missingNumber_Sum(nums);
        return missingNumber_Bit(nums);
    }
};
