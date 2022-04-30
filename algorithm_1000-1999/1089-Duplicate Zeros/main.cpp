class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        size_t len = 0;
        for (int num : arr) {
            len += (num == 0 ? 2 : 1);
        }

        for (size_t i = arr.size(); 0 < i--;) {
            if (--len < arr.size()) {
                arr[len] = arr[i];
            }
            if (arr[i] == 0) {
                if (--len < arr.size()) {
                    arr[len] = arr[i];
                }
            }
        }
    }
};
