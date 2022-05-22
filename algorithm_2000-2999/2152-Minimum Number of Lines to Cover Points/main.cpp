class Solution {
public:
    void recursiveHelper(const vector<vector<int>>& points, vector<bool>& used, int depth, int& ans) {
        auto computeSlope = [](const vector<int>& p1, const vector<int>& p2) -> float {
            if (p1[0] == p2[0]) {
                return std::numeric_limits<float>::infinity();
            }
            else {
                return float(p2[1] - p1[1]) / float(p2[0] - p1[0]);
            }
        };
        auto compPQ = [](const vector<size_t>* pIndexes1, const vector<size_t>* pIndexes2) -> bool {
            return (pIndexes1->size() < pIndexes2->size());
        };

        if (depth >= ans) {
            return;
        }

        size_t src = std::find(used.begin(), used.end(), false) - used.begin();
        assert(src < used.size());
        size_t cnt = std::count(used.begin() + src, used.end(), false);
        assert(0 < cnt);

        if (cnt <= 2) {
            ans = std::min(ans, depth);
            return;
        }

        used[src] = true;

        unordered_map<float, vector<size_t>> candidates;
        for (size_t i = src + 1; i < points.size(); ++i) {
            if (used[i]) {
                continue;
            }
            float slope = computeSlope(points[src], points[i]);
            candidates[slope].push_back(i);
        }
        assert(1 <= candidates.size());

        if (candidates.size() == 1) {
            ans = std::min(ans, depth);
        }
        else {
            priority_queue<const vector<size_t>*, vector<const vector<size_t>*>, decltype(compPQ)> pq(compPQ); // max_heap
            for (auto itr = candidates.begin(); itr != candidates.end(); ++itr) {
                pq.push(&(itr->second));
            }

            while (!pq.empty()) {
                const vector<size_t>* pIndexes = pq.top();
                pq.pop();

                for (size_t index : *pIndexes) {
                    used[index] = true;
                }
                recursiveHelper(points, used, depth + 1, ans);
                for (size_t index : *pIndexes) {
                    used[index] = false;
                }
            }
        }

        used[src] = false;
    }

    int recursive(const vector<vector<int>>& points) {
        vector<bool> used(points.size(), false);
        int ans = ceil(float(points.size()) / 2);
        recursiveHelper(points, used, 1, ans);
        return ans;
    }

    int iterative(const vector<vector<int>>& points) {
        // y = ax + b. <a, b> -> points
        vector<vector<pair<int, int>>> lines; {
            map<pair<float, float>, vector<pair<int, int>>> pntsOnLine;
            for (size_t i = 0; i < points.size(); ++i) {
                for (size_t j = i + 1; j < points.size(); ++j) {
                    float a, b; {
                        if (points[i][0] == points[j][0]) {
                            a = points[i][0];
                            b = std::numeric_limits<float>::infinity();
                        }
                        else {
                            a = float(points[j][1] - points[i][1]) / float(points[j][0] - points[i][0]);
                            b = points[i][1] - a * points[i][0];
                        }
                    }
                    pntsOnLine[{a, b}].emplace_back(points[i][0], points[i][1]);
                    pntsOnLine[{a, b}].emplace_back(points[j][0], points[j][1]);
                }
            }

            for (auto& [slope, pnts] : pntsOnLine) {
                if (2 < pnts.size()) {
                    lines.push_back(pnts);
                }
            }
        }

        int ans = ceil(float(points.size()) / 2); // max possible answer
        for (int i = 1, n = (1 << lines.size()); i < n; ++i) {
            int lineCnt = __builtin_popcount(i);
            if (ans <= lineCnt) {
                continue;
            }

            set<pair<int, int>> visitedPoints;
            for (int mask = i, index = 0; 0 < mask; mask >>= 1, ++index) {
                if (mask & 1) {
                    visitedPoints.insert(lines[index].begin(), lines[index].end());
                }
            }

            ans = min(ans, lineCnt + int(ceil(float(points.size() - visitedPoints.size()) / 2)));
        }

        return ans;
    }

    int minimumLines(vector<vector<int>>& points) {
        //return recursive(points);
        return iterative(points);
    }
};
