class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (int num : nums) {
            if (num & 1) { continue; }
            ++cnts[num];
        }

        for (int num : nums) {
            if (num & 1) { continue; }
            if (cnts[num] == 1) {
                return num;
            }
        }

        return -1;
    }
};
