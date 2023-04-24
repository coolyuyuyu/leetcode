class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (size_t i = 2; i < arr.size(); ++i) {
            if ((arr[i - 1] + diff) != arr[i]) {
                return false;
            }
        }

        return true;
    }
};
