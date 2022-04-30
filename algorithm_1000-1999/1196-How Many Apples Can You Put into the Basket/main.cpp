class Solution {
public:
    // Time: O(NlogN)
    int bySort(vector<int>& weight) {
        std::sort(weight.begin(), weight.end());
        for (int sum = 0, i = 0; i < weight.size(); ++i) {
            sum += weight[i];
            if (5000 < sum) {
                return i;
            }
        }

        return weight.size();
    }

    // Time: O(NlogN)
    int byHeap(vector<int>& weight) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(weight.begin(), weight.end());

        int cnt = 0;
        for (int sum = 0; !pq.empty(); ++cnt) {
            sum += pq.top();
            pq.pop();
            if (5000 < sum) {
                return cnt;
            }
        }

        return cnt;
    }

    int maxNumberOfApples(vector<int>& weight) {
        //return bySort(weight);
        return byHeap(weight);
    }
};
