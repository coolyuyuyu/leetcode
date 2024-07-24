class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mappedNums;
        for (int num : nums) {
            int mappedNum = 0;
            int base = 1, x = num; 
            do {
                int d = x % 10;
                mappedNum += mapping[d] * base;

                base *= 10, x /= 10;
            } while (x);
            mappedNums[num] = mappedNum;
        }

        std::stable_sort(nums.begin(), nums.end(), [&](int num1, int num2){ return mappedNums[num1] < mappedNums[num2]; });

        return nums;
    }
};
