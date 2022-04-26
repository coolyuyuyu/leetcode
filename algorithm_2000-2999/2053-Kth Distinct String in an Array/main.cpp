class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnts;
        for (const string& str : arr) {
            ++cnts[str];
        }
        for (const string& str : arr) {
            if (cnts[str] == 1 && --k == 0) {
                return str;
            }
        }

        return "";
    }
};
