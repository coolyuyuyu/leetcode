class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> counts(502, 0);
        for (int num : arr) {
            ++counts[num];
        }

        for (int i = counts.size() - 1; 0 < i; --i) {
            if (i == counts[i]) {
                return i;
            }
        }

        return -1;
    }
};
