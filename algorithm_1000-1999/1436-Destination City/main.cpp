class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> m;
        for (const auto& path : paths) {
            ++m[path[0]];
            m.emplace(path[1], 0);
        }

        for (const auto& [city, cnt] : m) {
            if (cnt == 0) {
                return city;
            }
        }

        return "";
    }
};
