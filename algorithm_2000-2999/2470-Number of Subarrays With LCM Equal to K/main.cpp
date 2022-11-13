class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }

    int lcm(int a, int b){
        return a / gcd(a, b) * b;
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int m = 1;
            for (size_t j = i; j < nums.size() && m <= k; ++j) {
                m = lcm(m, nums[j]);
                if (m == k) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};
