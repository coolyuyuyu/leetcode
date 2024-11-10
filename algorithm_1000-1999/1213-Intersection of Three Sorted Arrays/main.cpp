class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ret;
        for (int i = 0, j = 0, k = 0; i < arr1.size() && j < arr2.size() && k < arr3.size();) {
            int mn = std::max({arr1[i], arr2[j], arr3[k]});
            if (arr1[i] < mn) {
                ++i;
            }
            if (arr2[j] < mn) {
                ++j;
            }
            if (arr3[k] < mn) {
                ++k;
            }

            if (arr1[i] == mn && arr2[j] == mn && arr3[k] == mn) {
                ret.push_back(arr1[i]);
                ++i, ++j, ++k;
            }
        }

        return ret;
    }
};
