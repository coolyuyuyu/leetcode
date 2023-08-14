class Solution {
public:
    static int squareDist(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    static bool comp(const vector<int>& point1, const vector<int>& point2) {
        return squareDist(point1) < squareDist(point2);
    };

    // Time: O(NlogN)
    vector<vector<int>> quickSort(vector<vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }

    // Time: O(NlogK)
    vector<vector<int>> heap(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&comp)> pq(comp);
        for (const vector<int>& point : points) {
            pq.push(point);
            if ((k + 1) < pq.size()) {
                pq.pop();
            }
        }

        vector<vector<int>> ret;
        for (; !pq.empty(); pq.pop()) {
            ret.push_back(pq.top());
        }

        return ret;
    }

    // Time: O(NlogC)
    vector<vector<int>> binarySearch(vector<vector<int>>& points, int k) {
        auto [pLo, pHi] = std::minmax_element(points.begin(), points.end(), comp);
        auto lo = squareDist(*pLo), hi = squareDist(*pHi);

        std::function<int(int)> countLE = [&points, k](int target) {
            int cnt = 0;
            for (const vector<int>& point : points) {
                if (squareDist(point) <= target) {
                    ++cnt;
                }
            }

            return cnt;
        };
        while (lo < hi) {
            auto mid = lo + (hi - lo) / 2;
            if (k < countLE(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        vector<vector<int>> ret;
        for (int i = 0, cnt = 0; i < points.size(); ++i) {
            if (squareDist(points[i]) <= lo) {
                ret.push_back(points[i]);
                if (k < cnt) {
                    break;
                }
            }
        }

        return ret;
    }

    // Time: Amoterized O(N)
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        std::function<int(int, int, int)> f = [&](int lo, int hi, int k) {
            // M: pivot
            // S: less than pivot
            // L: greater than pivot
            // X: unknown
            // S S S S S M M M M M X X X X X L L L L L
            //           i         x       j
            int pivot = squareDist(points[lo + (hi - lo) / 2]);
            int i = lo, j = hi, x = lo;
            while (x <= j) {
                int val = squareDist(points[x]);
                if (val < pivot) {
                    std::swap(points[i], points[x]);
                    ++i;
                    ++x;
                }
                else if (val == pivot) {
                    ++x;
                }
                else {
                    std::swap(points[x], points[j]);
                    --j;
                }
            }
            // S S S S S M M M M M L L L L L
            // lo        i       j         hi
            if (k < (i - lo)) {
                return f(lo, i - 1, k);
            }
            else if (k < (j + 1 - lo)) {
                return pivot;
            }
            else {
                return f(j + 1, hi, k - (j + 1 - lo));
            }
        };
        int target = f(0, points.size() - 1, k);

        vector<vector<int>> ret;
        for (int i = 0, cnt = 0; i < points.size(); ++i) {
            if (squareDist(points[i]) <= target) {
                ret.push_back(points[i]);
                if (k < cnt) {
                    break;
                }
            }
        }

        return ret;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        --k;

        //return quickSort(points, k);
        //return heap(points, k);
        //return binarySearch(points, k);
        return quickSelect(points, k);
    }
};
