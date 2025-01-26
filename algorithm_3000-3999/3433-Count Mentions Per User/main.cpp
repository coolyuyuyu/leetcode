class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;

        std::sort(
            events.begin(),
            events.end(),
            [](const auto& e1, const auto& e2){
                int t1 = std::stoi(e1[1]), t2 = std::stoi(e2[1]);
                if (t1 != t2) {
                    return t1 < t2;
                }
                else {
                    return e1[0] == "OFFLINE";
                }
            });

        bool onlines[n]; std::fill(onlines, onlines + n, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; // <time, id>

        vector<int> ret(n, 0);

        int t = 0;
        for (const auto& e : events) {
            t = std::stoi(e[1]);
            while (!pq.empty() && pq.top().first <= t) {
                auto [_, id] = pq.top();
                pq.pop();
                onlines[id] = true;
            }
            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int id = 0; id < n; ++id) {
                        ++ret[id];
                    }
                }
                else if (e[2] == "HERE") {
                    for (int id = 0; id < n; ++id) {
                        if (onlines[id]) {
                            ++ret[id];
                        }
                    }
                }
                else {
                    string token;
                    for (istringstream iss(e[2]); iss >> token;) {
                        int id = std::stoi(token.substr(2));
                        ++ret[id];
                    }
                }
            }
            else {
                int id = std::stoi(e[2]);
                onlines[id] = false;
                pq.emplace(t + 60, id);
            }
        }

        return ret;
    }
};
