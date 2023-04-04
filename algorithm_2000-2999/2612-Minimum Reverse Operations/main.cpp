class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        set<int> candidateE, candidateO; {
            vector<bool> ban(n, false);
            for (int pos : banned) {
                ban[pos] = true;
            }

            for (int i = 0; i < n; ++i) {
                if (ban[i] == false) {
                    if (i & 1) {
                        candidateO.insert(i);
                    }
                    else {
                        candidateE.insert(i);
                    }
                }
            }

            auto& candidate = p & 1 ? candidateO :candidateE;
            candidate.erase(p);
        }

        vector<int> ret(n, -1);

        queue<int> q({p});
        for (int step = 0; !q.empty(); ++step) {
            for (int N = q.size(); 0 < N--;) {
                int i = q.front();
                q.pop();

                ret[i] = step;

                auto& candidate = ((i & 1) ^ (k & 1)) ? candidateE : candidateO;
                int lo = abs(i - k + 1), hi = n - abs(n - i - k);
                for (auto itr = candidate.lower_bound(lo); itr != candidate.end() && *itr <= hi; itr = candidate.erase(itr)) {
                    int j = *itr;
                    q.push(j);
                }
            }
        }

        return ret;
    }
};
