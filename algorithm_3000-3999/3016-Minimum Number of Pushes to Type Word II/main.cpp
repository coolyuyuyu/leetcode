class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> cnts;
        for (char c : word) {
            ++cnts[c];
        }

        priority_queue<int> pq;
        for (const auto& [_, cnt] : cnts) {
            pq.push(cnt);
        }

        int ret = 0;
        for (int press = 1; !pq.empty(); ++press) {
            for (int i = 0; i < 8 && !pq.empty(); ++i) {
                auto cnt = pq.top();
                pq.pop();

                ret += cnt * press;
            }
        }

        return ret;
    }
};
