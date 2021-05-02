class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == i) {
                return i;
            }
        }

        return -1;
    }
};
