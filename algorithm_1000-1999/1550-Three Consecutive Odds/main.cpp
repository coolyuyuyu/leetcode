class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0, n = arr.size(), odd = 0; i < n; ++i) {
            if (arr[i] % 2 == 1) {
                if (++odd == 3) {
                    return true;
                }
            }
            else {
                odd = 0;
            }
        }

        return false;
    }
};
