class Solution {
public:
    int byHash(vector<int>& nums, int original) {
        unordered_set<int> exist;
        for (int num : nums) {
            exist.emplace(num);
        }

        while (exist.find(original) != exist.end()) {
            original *= 2;
        }

        return original;
    }

    int byArray(vector<int>& nums, int original) {
        bitset<1001> exist;
        for (int num : nums) {
            exist.set(num);
        }

        while (original < exist.size() && exist[original]) {
            original *= 2;
        }

        return original;
    }

    int findFinalValue(vector<int>& nums, int original) {
        //return byHash(nums, original)
        return byArray(nums, original);
    }
};
