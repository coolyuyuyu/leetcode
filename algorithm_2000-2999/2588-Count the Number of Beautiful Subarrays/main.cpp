class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> counts = {{0, 1}};

        long long ret = 0;
        int state = 0;
        for (int num : nums) {
            state ^= num;
            ret += counts[state];
            ++counts[state];
        }

        return ret;
    }
};
