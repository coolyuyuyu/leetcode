class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int num : arr) {
            ++m[num];
        }

        vector<int> cnts;
        for (const auto& [_, cnt] : m) {
            cnts.push_back(cnt);
        }
        std::sort(cnts.begin(), cnts.end());

        int i = 0;
        for (; k > 0 && i < cnts.size(); ++i) {
            k -= cnts[i];
            if (k < 0) {
                break;
            }
        }

        return cnts.size() - i;
    }
};
