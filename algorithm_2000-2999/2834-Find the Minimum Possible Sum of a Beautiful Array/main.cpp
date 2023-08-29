class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> nums;
        long long ret = 0;
        for (int i = 1; nums.size() < n; ++i) {
            if (nums.find(target - i) != nums.end()) {
                continue;
            }

            nums.insert(i);
            ret += i;
        }

        return ret;
    }
};
