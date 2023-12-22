
class Solution {
public:
    std::pair<bool, unordered_map<char, unordered_set<char>>> constructGraph(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        for (const string& word : words) {
            for (char c : word) {
                graph.emplace(c, unordered_set<char>{});
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            const string& pre = words[i - 1];
            const string& cur = words[i];
            int j = 0, n = std::min(pre.size(), cur.size());
            for (;j < n; ++j) {
                if (pre[j] != cur[j]) {
                    graph[pre[j]].insert(cur[j]);
                    break;
                }
            }
            if (j == n && pre.size() > cur.size()) {
                return {false, {}};
            }
        }

        return {true, graph};
    }

    string bfsTopologicalOrder(unordered_map<char, unordered_set<char>>& graph) {
        unordered_map<char, int> in;
        for (const auto& [cur, nxts] : graph) {
            in.emplace(cur, 0);
            for (auto nxt : nxts) {
                ++in[nxt];
            }
        }

        string ret;

        queue<char> q;
        for (const auto& [cur, degree] : in) {
            if (degree == 0) {
                q.push(cur);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            ret += cur;

            for (int nxt : graph[cur]) {
                if (--in[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        if (ret.size() != in.size()) {
            ret.clear();
        }

        return ret;
    }

    string dfsTopologicalOrder(unordered_map<char, unordered_set<char>>& graph) {
        string ret;

        enum class State {
            kNone,
            kProcessing,
            kVisited,
        };
        unordered_map<int, State> state;
        for (const auto& [cur, _] : graph) {
            state[cur] = State::kNone;
        }
        std::function<bool(int)> checkCycle = [&](int cur) {
            switch (state[cur]) {
            case State::kProcessing: return true;
            case State::kVisited: return false;
            }

            state[cur] = State::kProcessing;
            for (int nxt : graph[cur]) {
                if (checkCycle(nxt)) {
                    return true;
                }
            }
            state[cur] = State::kVisited;

            ret.push_back(cur);

            return false;
        };

        for (const auto& [cur, _] : graph) {
            if (checkCycle(cur)) {
                ret = "";
                break;
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    string alienOrder(vector<string>& words) {
        auto [valid, graph] = constructGraph(words);
        if (!valid) { return ""; }

        return bfsTopologicalOrder(graph);
        //return dfsTopologicalOrder(graph);
    }
};
