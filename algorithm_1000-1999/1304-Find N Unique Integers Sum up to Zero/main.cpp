class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 2) {
            return {1, -1};
        }

        vector<int> nums;

        int sum = 0;
        for (int i = 0; (i + 1) < n; ++i) {
            nums.push_back(i);
            sum += i;
        }
        nums.push_back(-sum);

        return nums;
    }
};
