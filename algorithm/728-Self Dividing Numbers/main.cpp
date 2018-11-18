class Solution {
public:
    bool checkSelfDividing(int num) {
        int tmpNum = num;
        while (tmpNum != 0) {
            int digit = tmpNum % 10;
            if (digit == 0 || num % digit != 0) {
                return false;
            }
            tmpNum /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (checkSelfDividing(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};