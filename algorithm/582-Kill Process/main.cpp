class Solution {
public:
    vector<int> killProcess(vector<int>& pidArr, vector<int>& ppidArr, int kill) {
        unordered_multimap<int, int> childs;
        for (size_t i = 0, n = pidArr.size(); i < n; ++i) {
            childs.emplace(ppidArr[i], pidArr[i]);
        }

        vector<int> vals;

        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int parent = q.front();
            q.pop();

            vals.push_back(parent);

            auto range = childs.equal_range(parent);
            for (auto itr = range.first; itr != range.second; ++itr) {
                q.push(itr->second);
            }
        }

        return vals;
    }
};