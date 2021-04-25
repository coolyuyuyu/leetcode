class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> counts;
        for (int num : nums) {
            ++counts[num];
        }

        int sum = 0;
        for (const auto& p : counts) {
            if (p.second == 1) {
                sum += p.first;
            }
        }

        return sum;
    }
};