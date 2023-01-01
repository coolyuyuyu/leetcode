class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> m; //key: remainder, val: count
        int maxCnt = 0
        for (int num : nums) {
            int reminder = num % space;
            ++m[reminder];
            if (maxCnt < m[reminder]) {
                maxCnt = m[reminder];
            }
        }

        int minVal = INT_MAX
        for (int num : nums) {
            if (m[num % space] == maxCnt) {
                minVal = std::min(minVal, num);
            }
        }

        return minVal;
    }
};
