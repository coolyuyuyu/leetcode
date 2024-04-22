class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string src = "0000";
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if (deads.find(src) != deads.end()) {
            return -1;
        }

        queue<string> q;
        visited.insert(src);
        q.push(src);
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); 0 < i--;) {
                string state = q.front();
                q.pop();

                if (state == target) {
                    return steps;
                }

                for (int idx = 0; idx < state.size(); ++idx) {
                    string state1 = state;
                    state1[idx] = '0' + (state[idx] - '0' + 1) % 10;
                    if (visited.insert(state1).second && deads.find(state1) == deads.end()) {
                        q.push(state1);
                    }

                    string state2 = state;
                    state2[idx] = '0' + (state[idx] - '0' + 10 - 1) % 10;
                    if (visited.insert(state2).second && deads.find(state2) == deads.end()) {
                        q.push(state2);
                    }
                }
            }
        }

        return -1;
    }
};
