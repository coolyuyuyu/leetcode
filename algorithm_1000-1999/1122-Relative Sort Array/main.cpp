class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> num2idx(1002, -1);
        for (int i = 0; i < arr2.size(); ++i) {
            num2idx[arr2[i]] = i;
        }

        auto comp = [&](int a, int b) {
            if (num2idx[a] == -1 && num2idx[b] == -1 ) {
                return a < b;
            }
            else if (num2idx[a] == -1) {
                return false;
            }
            else if (num2idx[b] == -1)  {
                return true;
            }
            else {
                return num2idx[a] < num2idx[b];
            }
        };
        std::sort(arr1.begin(), arr1.end(), comp);

        return arr1;
    }
};
