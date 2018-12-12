class Solution {
public:
    int minIncrementForUnique(vector<int>& numbers) {
        const int MAX_NUMBER = 40000;

        int counts[MAX_NUMBER] = {0};
        for (int number : numbers) {
            ++counts[number];
        }

        int ans = 0;
        int leftCount = 0;
        for (int number = 0; number < MAX_NUMBER; ++number) {
            if (2 <= counts[number]) {
                leftCount += (counts[number] - 1);
                ans -= (number * (counts[number] - 1));
            }
            else if (0 < leftCount && counts[number] == 0) {
                --leftCount;
                ans += number;
            }
        }

        for (int number = MAX_NUMBER; 0 < leftCount; ++ number) {
            ans += number;
            --leftCount;
        }

        return ans;
    }
};