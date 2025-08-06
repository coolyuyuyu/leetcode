class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0, maxNum = INT_MIN;
        unordered_set<int> s;
        for (int num : nums) {
            if (num > 0 && s.insert(num).second) {
                sum += num;
            }
            maxNum = std::max(maxNum, num);
        }

        return sum > 0 ? sum : maxNum;
    }
};
