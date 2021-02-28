class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> counts(1001, 0);
        for (int val : target) {
            ++counts[val];
        }
        for (int val : arr) {
            if (--counts[val] < 0) {
                return false;
            }
        }

        return all_of(counts.begin(), counts.end(), [](int c){ return c == 0; });
    }
};