class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int target = 0, maxCnt = 0;
        array<int, 1001> cnts;
        cnts.fill(0);
        for (size_t i = 0; (i + 1) < nums.size(); ++i) {
            if (nums[i] == key) {
                int cnt = ++cnts[nums[i + 1]];
                if (maxCnt < cnt) {
                    target = nums[i + 1];
                    maxCnt = cnt;
                }
            }
        }

        return target;
    }
};
