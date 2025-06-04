class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        std::function<pair<int, int>(int)> idx2pos = [&](int idx) {
            --idx;
            int r = n - (idx / n) - 1;
            int c = (n - r - 1) & 1 ? (n - idx % n - 1): (idx % n);
            return std::make_pair(r, c);
        };

        int src = 1, dst = n * n;

        auto comp = [&](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(0, src);

        vector<bool> visited(n * n + 1, false);
        visited[src] = true;
        while (!pq.empty()) {
            auto [move, cur] = pq.top();
            pq.pop();

            if (cur == dst) {
                return move;
            }

            for (int nxt = cur + 1; nxt <= cur + 6 && nxt <= dst; ++nxt) {
                if (visited[nxt]) { continue; }
                visited[nxt] = true;

                auto [r, c] = idx2pos(nxt);
                pq.emplace(move + 1, (board[r][c] != -1 ? board[r][c] : nxt));
            }
        }

        return -1;
    }
};
