class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<vector<int>::iterator, vector<int>::iterator> ItrPair;
        auto comp = [](const ItrPair& lft, const ItrPair& rht) { return *(lft.first) > *(rht.first); };

        priority_queue<ItrPair, vector<ItrPair>, decltype(comp)> pq(comp);
        for (vector<int>& vals : matrix) {
            if (!vals.empty()) {
                pq.emplace(vals.begin(), vals.end());
            }
        }

        while (k > 1) {
            ItrPair itrPair = pq.top();
            pq.pop();

            --k;

            ++itrPair.first;
            if (itrPair.first != itrPair.second) {
                pq.emplace(itrPair.first, itrPair.second);
            }
        }

        return *(pq.top().first);
    }
};