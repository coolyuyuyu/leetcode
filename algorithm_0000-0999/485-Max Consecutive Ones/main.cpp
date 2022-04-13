class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for (int num : nums) {
            if (num == 1) {
                ++cnt;
                if (ans < cnt) {
                    ans = cnt;
                }
            }
            else {
                cnt = 0;
            }
        }

        return ans;
    }
};
