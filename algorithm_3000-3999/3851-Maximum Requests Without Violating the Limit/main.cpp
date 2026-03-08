class Solution {
public:
    int maxRequests(vector<vector<int>>& requests, int k, int window) {
        unordered_map<int, vector<int>> user2times;
        for (const auto& request : requests) {
            int user = request[0], time = request[1];
            user2times[user].push_back(time);
        }

        int ret = requests.size();
        for (auto& [_, times] : user2times) {
            std::sort(times.begin(), times.end());

            deque<int> dq;
            for (int time : times) {
                while (!dq.empty() && (time - dq.front()) > window) {
                    dq.pop_front();
                }

                if (dq.size() >= k) {
                    --ret;
                }
                else {
                    dq.push_back(time);
                }
            }
        }

        return ret;
    }
};
