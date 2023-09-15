class Solution {
public:

    vector<string> recursive1(vector<vector<string>>& tickets) {
        unordered_map<string, queue<string>> graph;
        std::sort(tickets.begin(), tickets.end());
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        std::function<vector<string>(const string&)> dfs = [&](const string& start) {
            vector<vector<string>> paths;
            for (queue<string>& edges = graph[start]; !edges.empty();) {
                string next = edges.front();
                edges.pop();
                paths.push_back(dfs(next));
            }

            vector<string> ret = {start};
            for (int i = paths.size() - 1; 0 <= i; --i) {
                const auto& path = paths[i];
                ret.insert(ret.end(), path.begin(), path.end());
            }

            return ret;
        };

        return dfs("JFK");
    }

    vector<string> recursive2(vector<vector<string>>& tickets) {
        unordered_map<string, queue<string>> graph;
        std::sort(tickets.begin(), tickets.end());
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> ret;
        std::function<void(const string&)> dfs = [&](const string& start) {
            for (queue<string>& edges = graph[start]; !edges.empty();) {
                string next = edges.front();
                edges.pop();
                dfs(next);

            }
            ret.push_back(start);
        };
        dfs("JFK");
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    vector<string> iterative(vector<vector<string>>& tickets) {
        // Hierholzer’s Algorithm

        unordered_map<string, queue<string>> graph;
        std::sort(tickets.begin(), tickets.end());
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> ret;


        string node = "JFK";
        for (stack<string> stk({node}); !stk.empty();) {
            if(graph[node].empty()) {
                ret.push_back(node);

                node = stk.top();
                stk.pop();
            }
            else {
                stk.push(node);

                string next =  graph[node].front();
                graph[node].pop();

                node = next;
            }
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //return recursive1(tickets);
        //return recursive2(tickets);
        return iterative(tickets);
    }
};
