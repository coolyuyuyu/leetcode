class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        if (kill == 0) {
            return pid;
        }

        struct ForestNode {
            int val;
            vector<ForestNode*> childs;
            ForestNode(int x) : val(x) {}
        };

        unordered_map<int, vector<int>> childs;
        int length = pid.size();
        for (int i = 0; i < length; ++i) {
            pair<unordered_map<int, vector<int>>::iterator, bool> p1 = childs.emplace(ppid[i], vector<int>());
            unordered_map<int, vector<int>>::iterator itrParent = p1.first;

            pair<unordered_map<int, vector<int>>::iterator, bool> p2 = childs.emplace(pid[i], vector<int>());
            unordered_map<int, vector<int>>::iterator itrChild = p2.first;
            
            p1.first->second.push_back(p2.first->first);
        }

        int root = kill;
        vector<int> ans;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int pid = q.front();
            q.pop();
            ans.push_back(pid);
            vector<int> pids = childs[pid];
            for (auto pid: pids) {
                q.push(pid);
            }
        }

        return ans;
    }
};