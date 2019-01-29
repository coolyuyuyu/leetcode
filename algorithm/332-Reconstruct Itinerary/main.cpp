class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Hierholzer’s Algorithm

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjLists; {
            for (const pair<string, string>& edge : tickets) {
                adjLists[edge.first].emplace(edge.second);
            }
        }

        vector<string> path;

        string node = "JFK";
        stack<string> stk;
        stk.emplace(node);
        while (!stk.empty()) {
            if (adjLists[node].empty()) {
                path.emplace_back(node);

                node = stk.top();
                stk.pop();
            }
            else {
                stk.emplace(node);

                priority_queue<string, vector<string>, greater<string>>& neighbors = adjLists[node];
                node = neighbors.top();
                neighbors.pop();
            }
        }
        reverse(path.begin(), path.end());

        return path;
    }
};