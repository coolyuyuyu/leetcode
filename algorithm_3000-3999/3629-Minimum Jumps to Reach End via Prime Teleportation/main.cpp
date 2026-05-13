class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *std::max_element(nums.begin(), nums.end());

        // smallest prime factor
        vector<int> spf(maxNum + 1, 0);
        for (int i = 2; i <= maxNum; ++i) {
            if (spf[i] > 0) { continue; }
            for (int j = i; j <= maxNum; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
        }

        vector<int> num2idxes[maxNum + 1];
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (num > 1) {
                int prime = spf[num];
                num2idxes[prime].push_back(i);
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }

        unordered_set<int> visitedPrimes;
        queue<int> q;
        vector<bool> visitedIndex(n, false);

        visitedIndex[0] = true;
        q.push(0);
        for (int ret = 0; !q.empty(); ++ret) {
            for (int len = q.size(); 0 < len--;) {
                int u = q.front();
                q.pop();

                if (u == n - 1) {
                    return ret;
                }

                if (u > 0) {
                    int v = u - 1;
                    if (!visitedIndex[v]) {
                        visitedIndex[v] = true;
                        q.push(v);
                    }
                }
                if (u + 1 < n) {
                    int v = u + 1;
                    if (!visitedIndex[v]) {
                        visitedIndex[v] = true;
                        q.push(v);
                    }
                }

                if (spf[nums[u]] == nums[u] && visitedPrimes.insert(nums[u]).second) {
                    for (int v : num2idxes[nums[u]]) {
                        if (!visitedIndex[v]) {
                            visitedIndex[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        std::unreachable();

        return -1;
    }
};
