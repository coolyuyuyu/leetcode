class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> id2childs;
        for (int i = 0, n = pid.size(); i < n; ++i) {
            int cur = ppid[i], nxt = pid[i];
            id2childs[cur].push_back(nxt);
        }

        vector<int> ret;
        for (queue<int> q({kill}); !q.empty();) {
            int cur = q.front();
            q.pop();

            ret.push_back(cur);

            for (int nxt : id2childs[cur]) {
                q.push(nxt);
            }
        }

        return ret;
    }
};
