class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> cnts(32);
        for (int num : nums) {
            int i = 0;
            while (1 < num) {
                ++i;
                num /= 2;
            }

            ++cnts[i];
        }

        vector<int> indexes;
        for (int i = 0; i < 31; ++i) {
            if ((target >> i) & 1) {
                indexes.push_back(i);
            }
        }

        int ret = 0;
        for (int i : indexes) {
            if (cnts[i] == 0) {
                for (int j = 0; j < i; ++j) {
                    cnts[j + 1] += cnts[j] / 2;
                    cnts[j] %= 2;
                }
            }

            if (cnts[i] == 0) {
                int j = i + 1;
                while (j < 32 && cnts[j] == 0) {
                    ++j;
                }
                if (j == 32) {
                    return -1;
                }

                ret += (j - i);

                cnts[j--] -= 1;
                while (i <= j) {
                    cnts[j] += 1;
                    --j;
                }
            }

            --cnts[i];
        }

        return ret;
    }
};
