class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (int num : arr) {
            ++cnts[num];
        }

        int ret = -1;
        for (const auto& [num, cnt] : cnts) {
            if (num == cnt) {
                ret = std::max(ret, num);
            }
        }

        return ret;
    }
};
