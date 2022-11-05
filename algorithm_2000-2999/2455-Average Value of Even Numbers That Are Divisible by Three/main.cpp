class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for (int num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                sum += num, ++cnt;
            }
        }

        return cnt == 0 ? 0 : (sum / cnt);
    }
};
