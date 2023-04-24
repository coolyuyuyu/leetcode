class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool plus = true;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }

            plus ^= !(0 < num);
        }

        return plus ? 1 : -1;
    }
};
