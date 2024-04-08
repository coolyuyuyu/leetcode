class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        std::function<int(int)> encrypt = [](int num) {
            int d = 0, len = 0;
            for (int x = num; x; x /= 10) {
                d = std::max(d, x % 10);
                ++len;
            }

            int ret = 0;
            for (int i = 0; i < len; ++i) {
                ret = ret * 10 + d;
            }

            return ret;
        };

        int ret = 0;
        for (int num : nums) {
            ret += encrypt(num);
        }

        return ret;
    }
};
