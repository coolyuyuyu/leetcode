class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            else if (num == k) {}
            else {
                s.insert(num);
            }
        }

        return s.size();
    }
};
