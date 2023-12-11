class Solution {
public:
    // Time: O(B)
    int lsearch(vector<int>& arr) {
        int len = arr.size() / 4;
        for (int i = 0; i + len < arr.size(); ++i) {
            if (arr[i] == arr[i + len]) {
                return arr[i];
            }
        }

        assert(false);
        return -1;
    }

    // Time: O(logN)
    int bsearch(vector<int>& arr) {
        for (float p : vector<float>{0.25, 0.5, 0.75}) {
            int val = arr[arr.size() * p];
            auto bounds = std::equal_range(arr.begin(), arr.end(), val);
            if (std::distance(bounds.first, bounds.second) * 4 > arr.size()) {
                return val;
            }
        }

        assert(false);
        return -1;
    }

    int findSpecialInteger(vector<int>& arr) {
        //return lsearch(arr);
        return bsearch(arr);
    }
};
