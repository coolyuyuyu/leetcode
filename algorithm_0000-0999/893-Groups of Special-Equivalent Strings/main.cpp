class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<vector<int>> groups;
        for (const string& str : A) {
            vector<int> group(26 * 2, 0);
            for (size_t i = 0; i < str.size(); ++i) {
                group[str[i] - 'a' + i % 2 * 26]++;
            }
            groups.insert(group);
        }

        return groups.size();
    }
};