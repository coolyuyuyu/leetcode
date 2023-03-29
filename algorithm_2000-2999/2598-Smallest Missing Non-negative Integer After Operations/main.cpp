class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnts(value, 0);
        for (int num : nums) {
            ++cnts[((num % value) + value) % value];
        }

        int index = std::min_element(cnts.begin(), cnts.end()) - cnts.begin();
        int minCnt = cnts[index];
        return minCnt * value + index;
    }
};
