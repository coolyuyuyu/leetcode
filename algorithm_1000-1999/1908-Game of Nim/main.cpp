class Solution {
public:
    string encode(vector<int> piles) {
        if (piles.empty()) {
            return "";
        }

        std::sort(piles.begin(), piles.end());

        string key;
        key += ('0' + piles.front());
        for (int i = 0; i < piles.size(); ++i) {
            key += '_';
            key += ('0' + piles[i]);
        }

        return key;
    }

    bool nimGame(vector<int> piles, unordered_map<string, bool>& cache) {
        if (std::all_of(piles.begin(), piles.end(), [](int n) { return n == 0; })) {
            return false;
        }

        string key = encode(piles);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        for (int i = 0; i < piles.size(); ++i) {
            int cnt = piles[i];
            for (int j = 0; j < cnt; ++j) {
                piles[i] = j;
                if (!nimGame(piles, cache)) {
                    return cache[key] = true;
                }
            }
            piles[i] = cnt;
        }

        return cache[key] = false;
    }

    bool nimGame(vector<int>& piles) {
        unordered_map<string, bool> cache;
        return nimGame(piles, cache);
    }
};
