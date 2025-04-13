class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }

        unordered_set<int> xors;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                xors.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> s;
        for (int num : nums) {
            for (int p : xors) {
                s.insert(num ^ p);
            }
        }

        return s.size();
    }
};
