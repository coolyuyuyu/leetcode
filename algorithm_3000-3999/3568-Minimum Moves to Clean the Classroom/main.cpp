class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom.empty() ? 0 : classroom[0].size();

        int srcR, srcC, litterCnt = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                switch (classroom[r][c]) {
                    case 'S':
                        srcR = r, srcC = c;
                        break;
                    case 'L':
                        classroom[r][c] = '0' + litterCnt;
                        ++litterCnt;
                        break;
                }
            }
        }
        int dstState = (1 << litterCnt) - 1;

        int visited[m][n][(1 << litterCnt)];
        std::fill(&visited[0][0][0], &visited[0][0][0] + m * n * (1 << litterCnt), -1);

        queue<tuple<int, int, int, int>> q;
        visited[srcR][srcC][0] = energy;
        q.emplace(srcR, srcC, 0, energy);
        for (int move = 0; !q.empty(); ++move) {
            for (int i = q.size(); 0 < i--;) {
                auto [r, c, s, e] = q.front();
                q.pop();

                if (s == dstState) {
                    return move;
                }
                if (e == 0) {
                    continue;
                }

                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                    if (classroom[x][y] == 'X') { continue; }

                    int newS = s;
                    int newE = e - 1;
                    if ('0' <= classroom[x][y] && classroom[x][y] <= '9') {
                        newS |= (1 << (classroom[x][y] - '0'));
                    }
                    else if (classroom[x][y] == 'R') {
                        newE = energy;
                    }

                    if (newE > visited[x][y][newS]) {
                        visited[x][y][newS] = newE;
                        q.emplace(x, y, newS, newE);
                    }
                }
            }
        }

        return -1;
    }
};
