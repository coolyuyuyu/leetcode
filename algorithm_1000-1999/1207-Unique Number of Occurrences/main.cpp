class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, size_t> cnts;
        for (int num : arr) {
            ++cnts[num];
        }

        unordered_set<size_t> s;
        for (const auto& p : cnts) {
            if (s.insert(p.second).second == false) {
                return false;
            }
        }

        return true;
    }
};
