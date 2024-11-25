class Solution {
public:
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        string p;
        for (const auto& row : board) {
            for (int v : row) {
                p += ('0' + v);
            }
        }

        queue<string> patterns;
        unordered_set<string> visited;

        patterns.push(p);
        visited.insert(p);
        for (int step = 0; !patterns.empty(); ++step) {
            for (int x = patterns.size(); 0 < x--;) {
                string p = patterns.front();
                patterns.pop();

                if (p == "123450") {
                    return step;
                }

                int i, r, c;
                for (i = 0; i < p.size(); ++i) {
                    if (p[i] == '0') {
                        r = i / 3, c = i % 3;
                        break;
                    }
                }

                vector<vector<int>> board {{p[0] - '0', p[1] - '0', p[2] - '0'}, {p[3] - '0', p[4] - '0', p[5] - '0'}};
                for (const auto& [dr, dc] : dirs) {
                    int x = r + dr, y = c + dc;
                    if (x < 0 || x >= 2 || y < 0 || y >= 3) { continue; }
                    int j = x * 3 + y;

                    string q = p;
                    std::swap(q[i], q[j]);
                    if (visited.find(q) != visited.end()) {
                        continue;
                    } 

                    patterns.emplace(q);
                    visited.insert(q);                
                }
            }
        }

        return -1;
    }
};
