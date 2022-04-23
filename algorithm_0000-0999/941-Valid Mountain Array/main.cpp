class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        size_t top = 0;
        for (; (top + 1) < arr.size(); ++top) {
            if (arr[top + 1] <= arr[top]) {
                break;
            }
        }
        if (top == 0 || (top + 1) == arr.size()) {
            return false;
        }

        for (size_t i = top + 1; i < arr.size(); ++i) {
            if (arr[i - 1] <= arr[i]) {
                return false;
            }
        }

        return true;
    }
};
