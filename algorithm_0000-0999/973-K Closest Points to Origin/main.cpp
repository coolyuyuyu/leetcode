class Solution {
public:
    vector<vector<int>> kClosest_Sort(vector<vector<int>>& points, int k) {
        typedef vector<int> Point;
        auto comp = [](const Point& p1, const Point& p2) {
            return ((p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]));
        };
        sort(points.begin(), points.end(), comp);

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    vector<vector<int>> kClosest_Heap(vector<vector<int>>& points, int k) {
        typedef vector<int> Point;
        auto comp = [](const Point& p1, const Point& p2) {
            return ((p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]));
        };
        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp); // max_heap
        for (const Point& p : points) {
            if (pq.size() < k) {
                pq.push(p);
            }
            else if (comp(p, pq.top())) {
                pq.pop();
                pq.push(p);
            }
        }

        vector<Point> ret(pq.size());
        for (size_t i = 0; i < ret.size(); ++i, pq.pop()) {
            ret[i] = pq.top();
        }
        return ret;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Time: O(NlogN), Space: O(logN) <- implicit stack size
        //return kClosest_Sort(points, k);

        // Time: O(NlogK), Space: O(K)
        return kClosest_Heap(points, k);
    }
};