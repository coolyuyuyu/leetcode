class Solution {
public:
    vector<int> kWeakestRows_Sort(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> pairs(mat.size()); // vector<count, index>
        for (int index = 0; index < mat.size(); ++index) {
            pairs[index] = {count(mat[index].begin(), mat[index].end(), 1), index};
        }

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return (p1.second < p2.second);
            }
            else {
                return (p1.first < p2.first);
            }
        };
        partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(), comp);

        vector<int> indexes;
        for (int i = 0; i < k; ++i) {
            indexes.push_back(pairs[i].second);
        }

        return indexes;
    }

    vector<int> kWeakestRows_Heap(vector<vector<int>>& mat, int k) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return (p1.second < p2.second);
            }
            else {
                return (p1.first < p2.first);
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int index = 0; index < mat.size(); ++index) {
            pair<int, int> p(count(mat[index].begin(), mat[index].end(), 1), index);
            if (pq.size() < k) {
                pq.push(p);
            }
            else if (comp(p, pq.top())) {
                pq.pop();
                pq.push(p);
            }
        }

        vector<int> indexes(k);
        for (int i = k - 1; 0 <= i; --i) {
            indexes[i] = pq.top().second;
            pq.pop();
        }

        return indexes;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //return kWeakestRows_Sort(mat, k);
        return kWeakestRows_Heap(mat, k);
    }
};
