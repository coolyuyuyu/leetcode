class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> m;
        m[0] = 1;

        long long ret = 0;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            cnt += ((nums[i] % modulo) == k ? 1 : 0);
            ret +=  m[((cnt % modulo - k) % modulo + modulo) % modulo];
            ++m[cnt % modulo];
        }

        return ret;
    }
};
