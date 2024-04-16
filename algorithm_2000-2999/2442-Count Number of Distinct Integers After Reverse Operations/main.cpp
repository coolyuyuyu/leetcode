class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);

            int rev = 0;
            for (; num; num /= 10) {
                rev = rev * 10 + num % 10;
            }
            s.insert(rev);
        }

        return s.size();
    }
};
