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

    int minimumLines(vector<vector<int>>& points) {
        return recursive(points);
    }
};
