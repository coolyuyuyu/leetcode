class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (int num : arr) {
            ++cnts[num];
        }

        for (int num : arr) {
            --cnts[num];

            if (cnts[num * 2] > 0) {
                return true;
            }

            ++cnts[num];
        }

        return false;
    }
};
