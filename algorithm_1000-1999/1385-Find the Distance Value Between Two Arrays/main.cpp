class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        size_t cnt = 0;
        for (int num : arr1) {
            auto itr1 = std::upper_bound(arr2.begin(), arr2.end(), num - d - 1);
            auto itr2 = std::upper_bound(arr2.begin(), arr2.end(), num + d);
            if (itr1 == itr2) {
                ++cnt;
            }
        }

        return cnt;
    }
};
