class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for (size_t i = 0, j = 0, k = 0; i < arr1.size() && j < arr2.size() && k < arr3.size();) {
            int m = std::max({arr1[i], arr2[j], arr3[k]});
            if (arr1[i] < m) {
                ++i;
            }
            if (arr2[j] < m) {
                ++j;
            }
            if (arr3[k] < m) {
                ++k;
            }

            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.push_back(arr1[i]);
                ++i, ++j, ++k;
            }
        }

        return ans;
    }
};
