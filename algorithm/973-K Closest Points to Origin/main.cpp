class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> heap(comp); // max heap
        for (const vector<int>& point : points) {
            if (heap.size() < K) {
                heap.push(point);
            }
            else {
                if (comp(point, heap.top())) {
                    heap.pop();
                    heap.push(point);
                }
            }
        }

        vector<vector<int>> ans(heap.size());
        for (size_t i = 0; !heap.empty(); ++i) {
            ans[i] = heap.top();
            heap.pop();
        }
        return ans;
    }
};