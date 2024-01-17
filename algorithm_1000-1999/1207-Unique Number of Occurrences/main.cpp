class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num : arr) {
            ++m[num];
        }

        unordered_set<int> s;
        for (const auto& [_, cnt] : m) {
            if (s.insert(cnt).second == false) {
                return false;
            }
        }

        return true;
    }
};
