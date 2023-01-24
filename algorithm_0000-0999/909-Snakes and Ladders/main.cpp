class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int src = 1, dst = n * n;

        auto computePos = [&](int idx) -> pair<int, int> {
            --idx;
            int r = n - (idx / n) - 1;
            int c = ((idx / n) % 2) == 0 ? (idx % n) : (n - (idx % n) - 1);
            return {r, c};
        };

        auto comp = [&](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(0, src);

        vector<bool> visited(dst + 1, false);
        visited[src] = true;
        while (!pq.empty()) {
            auto [move, idx] = pq.top();
            pq.pop();

            if (dst == idx) {
                return move;
            }
            else if (dst < (idx + 6)) {
                return move + 1;
            }

            for (int diff = 1; diff <= 6; ++diff) {
                int nxt = idx + diff;
                auto [r, c] = computePos(nxt);
                if (visited[nxt]) {
                    continue;
                }
                visited[nxt] = true;

                if (board[r][c] != -1 ) {
                    nxt = board[r][c];
                }
                pq.emplace(move + 1, nxt);
            }
        }

        return -1;
    }
};
