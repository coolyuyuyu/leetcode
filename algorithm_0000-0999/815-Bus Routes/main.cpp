class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) { return 0; }

        const auto& bus2stop = routes;
        unordered_map<int, vector<int>> stop2bus;
        for (int bus = 0; bus < bus2stop.size(); ++bus) {
            for (int stop : bus2stop[bus]) {
                stop2bus[stop].push_back(bus);
            }
        }

        unordered_set<int> visitedBus, visitedStop;
        visitedStop.insert(source);

        queue<int> q({source});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); 0 < i--;) {
                int cur = q.front();
                q.pop();

                for (int bus : stop2bus[cur]) {
                    if (visitedBus.insert(bus).second == false) { continue; }
                    for (int nxt : bus2stop[bus]) {
                        if (visitedStop.insert(nxt).second == false) { continue; }

                        if (nxt == target) {
                            return steps + 1;
                        }

                        q.emplace(nxt);
                    }
                }
            }
        }

        return -1;
    }
};
