class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCnt = 0;
        for (int num : arr) {
            if ((num % 2) == 1) {
                ++oddCnt;
                if (3 <= oddCnt) {
                    return true;
                }
            }
            else {
                oddCnt = 0;
            }
        }

        return false;
    }
};