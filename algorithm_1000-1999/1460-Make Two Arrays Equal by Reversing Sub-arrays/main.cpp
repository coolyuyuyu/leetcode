class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnts(1001, 0);
        for (int num : target) {
            ++cnts[num];
        }
        for (int num : arr) {
            --cnts[num];
        }

        return std::all_of(cnts.begin(), cnts.end(), [](int cnt){ return cnt == 0; });
    }
};
