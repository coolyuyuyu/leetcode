class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int nextVal = arr.back();
        for (size_t i = arr.size(); 1 < i--;) {
            int maxVal = max(arr[i], nextVal);
            nextVal = arr[i - 1];
            arr[i - 1] = maxVal;
        }
        arr.back() = -1;

        return arr;
    }
};
