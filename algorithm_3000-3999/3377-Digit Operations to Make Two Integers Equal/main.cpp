class Solution {
public:
    bool isPrimes[10000];
    void findPrimesLT(int n) {
        std::fill(isPrimes, isPrimes + n, true);
        isPrimes[0] = false;
        if (1 < n) {
            isPrimes[1] = false;
        }

        for (int i = 2, limit = ceil(sqrt(n)); i < n; ++i) {
            if (isPrimes[i]) {
            }
            else {
                continue;
            }

            if (i < limit) {
                for (int j = i * i; j < n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
    }

    int minOperations(int n, int m) {
        findPrimesLT(10000);

        if (isPrimes[n]) {
            return -1;
        }

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; // <cost, cur>

        pq.emplace(n, n);
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            if (visited.insert(cur).second == false) {
                continue;
            }

            if (cur == m) {
                return cost;
            }

            string curStr = std::to_string(cur);
            for (int i = 0; i < curStr.size(); ++i) {
                if (curStr[i] < '9') {
                    string nxtStr = curStr;
                    ++nxtStr[i];
                    int nxt = std::stoi(nxtStr);
                    if (!isPrimes[nxt] && visited.find(nxt) == visited.end()) {
                        pq.emplace(cost + nxt, nxt);
                    }
                }
                if ((i == 0 && curStr[i] > '1') || (i > 0 && curStr[i] > '0')) {
                    string nxtStr = curStr;
                    --nxtStr[i];
                    int nxt = std::stoi(nxtStr);
                    if (!isPrimes[nxt] && visited.find(nxt) == visited.end()) {
                        pq.emplace(cost + nxt, nxt);
                    }
                }
            }
        }

        return -1;
    }
};
