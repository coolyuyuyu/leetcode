class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnts(26, 0);
        for (char c : word) {
            ++cnts[c - 'a'];
        }

        priority_queue<int> pq;
        for (int cnt : cnts) {
            if (cnt == 0) { continue; }
            pq.push(cnt);
        }

        int ret = 0;
        for (int type = 1; !pq.empty(); ++type) {
            for (int key = 2; key <= 9 && !pq.empty(); ++key) {
                int cnt = pq.top();
                pq.pop();

                ret += cnt * type;
            }
        }

        return ret;
    }
};
