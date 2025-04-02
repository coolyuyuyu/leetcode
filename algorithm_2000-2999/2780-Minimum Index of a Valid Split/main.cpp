class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maj = 0, cnt = 1;
        for (int num : nums) {
            cnt += (num == maj ? 1 : -1);
            if (cnt == 0) {
                maj = num, cnt = 1;
            }
        }

        cnt = 0;
        for (int num : nums) {
            if (num == maj) {
                ++cnt;
            }
        }

        for (int i = 0, lftCnt = 0, rhtCnt = cnt; i < nums.size(); ++i) {
            if (nums[i] == maj) {
                ++lftCnt, --rhtCnt;
            }
            if (lftCnt > ((i + 1) / 2) && rhtCnt > (nums.size() - i - 1) / 2) {
                return i;
            }
        }
        return -1;
    }
};
