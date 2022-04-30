class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int diff = (arr.back() - arr.front()) / int(arr.size());
        int x = arr.front();
        for (int num : arr) {
            if (num != x) {
                break;
            }
            x += diff;
        }

        return x;
    }
};
