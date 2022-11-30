class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnts;
        for (int num : arr) {
            ++cnts[num];
        }

        unordered_set<int> s;
        for (const auto& p : cnts) {
            if (s.emplace(p.second).second == false) {
                return false;
            }
        }

        return true;
    }
};
