class Solution {
public:
    int M = 1e9 + 7;

    int numberOfWays(int numPeople, vector<int>& cache) {
        if (numPeople % 2) {
            return 0;
        }
        if (numPeople == 0) {
            return 1;
        }
        if (cache[numPeople] != -1) {
            return cache[numPeople];
        }

        int ret = 0;
        for (int i = 0; (i + 2) <= numPeople; i += 2) {
            ret = (ret + (long long)numberOfWays(i, cache) * numberOfWays(numPeople - i - 2, cache)) % M;
        }

        return cache[numPeople] = ret;
    }

    int numberOfWays(int numPeople) {
        vector<int> cache(numPeople + 1, -1);
        return numberOfWays(numPeople, cache);
    }
};
