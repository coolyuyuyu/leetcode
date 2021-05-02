class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> indexes(1002, -1);
        for (int i = 0; i < arr2.size(); ++i) {
            indexes[arr2[i]] = i;
        }

        auto comp = [&indexes](int num1, int num2) -> bool {
            if (0 <= indexes[num1]) {
                if (0 <= indexes[num2]) {
                    return indexes[num1] < indexes[num2];
                }
                else {
                    return true;
                }
            }
            else {
                if (0 <= indexes[num2]) {
                    return false;
                }
                else {
                    return num1 < num2;
                }
            }
        };
        sort(arr1.begin(), arr1.end(), comp);

        return arr1;
    }
};
