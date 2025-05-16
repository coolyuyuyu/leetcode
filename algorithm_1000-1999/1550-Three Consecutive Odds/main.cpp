class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCnt = 0;
        for (int num : arr) {
            if (num & 1) {
                ++oddCnt;
            }
            else {
                oddCnt = 0;
            } 
            if (oddCnt >= 3) {
                return true;
            }
        }

        return false;
    }
};
