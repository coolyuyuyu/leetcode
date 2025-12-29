class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        std::sort(
            events.begin(), events.end(),
            [](const auto& e1, const auto& e2){
                int t1 = std::stoi(e1[1]), t2 = std::stoi(e2[1]);
                return t1 < t2 || (t1 == t2 && e1[0] == "OFFLINE");
            });

        vector<bool> onlines(numberOfUsers, true);
        queue<pair<int, int>> q; // <t, id>

        vector<int> ret(numberOfUsers, 0);
        for (const auto& e : events) {
            const string& msg = e[0];
            int t = std::stoi(e[1]);

            while (!q.empty() && q.front().first <= t) {
                auto& [_, id] = q.front();
                q.pop();

                onlines[id] = true;
            }

            if (msg == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int id = 0; id < numberOfUsers; ++id) {
                        ++ret[id];
                    }
                }
                else if (e[2] == "HERE") {
                    for (int id = 0; id < numberOfUsers; ++id) {
                        if (onlines[id]) {
                            ++ret[id];
                        }
                    }
                }
                else {
                    string token;
                    for (istringstream iss(e[2]); iss >> token;) {
                        int id = stoi(token.substr(2));
                        ++ret[id];
                    }
                }
            }
            else if (msg == "OFFLINE") {
                int id = std::stoi(e[2]);
                onlines[id] = false;
                q.emplace(t + 60, id);
            }
            else {
                assert(false);
            }
        }

        return ret;
    }
};
