class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            unordered_set<int> divisors;
            for (int i = 1; i * i <= num && divisors.size() <= 4; ++i) {
                if ((num % i) == 0) {
                    divisors.insert(i);
                    divisors.insert(num / i);
                }
            }
            if (divisors.size() == 4) {
                ret += std::accumulate(divisors.begin(), divisors.end(), 0);
            }
        }

        return ret;
    }
};
