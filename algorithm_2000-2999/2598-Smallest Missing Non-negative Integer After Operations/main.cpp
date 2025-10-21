class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnts(value, 0);
        for (int num : nums) {
            ++cnts[(num % value + value) % value];
        }

        int idx = std::distance(cnts.begin(), std::min_element(cnts.begin(), cnts.end()));
        int cnt = cnts[idx];
        return value * cnt + idx;
    }
};
