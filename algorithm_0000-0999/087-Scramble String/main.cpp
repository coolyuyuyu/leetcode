class Solution {
public:
    // Time: O(5^n), TLE
    bool recursive(const string& s1, size_t bgn1, const string& s2, size_t bgn2, size_t n) {        
        vector<unsigned char> cnts(26, 0);
        for (size_t i = 0; i < n; ++i) {
            ++cnts[s1[bgn1 + i] - 'a'];
            --cnts[s2[bgn2 + i] - 'a'];
        }
        for (size_t i = 0; i < cnts.size(); ++i) {
            if (cnts[i] != 0) {
                return false;
            }
        }
        if (n <= 3) {
            return true;
        }

        for (size_t i = 1; i < n; ++i) {
            if (recursive(s1, bgn1, s2, bgn2, i) && recursive(s1, bgn1 + i, s2, bgn2 + i, n - i)) {
                return true;
            }

            if (recursive(s1, bgn1, s2, bgn2 + n - i, i) && recursive(s1, bgn1 + i, s2, bgn2, n - i)) {
                return true;
            }
        }

        return false;
    }

    int cacheCnt = 0;
    bool recursive_memo(const string& s1, size_t bgn1, const string& s2, size_t bgn2, size_t n, map<tuple<size_t, size_t, size_t>, bool>& cache) {
        auto itr = cache.find({bgn1, bgn2, n});
        if (itr != cache.end()) {
            return itr->second;
        }

        vector<unsigned char> cnts(26, 0);
        for (size_t i = 0; i < n; ++i) {
            ++cnts[s1[bgn1 + i] - 'a'];
            --cnts[s2[bgn2 + i] - 'a'];
        }
        for (size_t i = 0; i < cnts.size(); ++i) {
            if (cnts[i] != 0) {
                return cache[{bgn1, bgn2, n}] = false;
            }
        }
        if (n <= 3) {
            return cache[{bgn1, bgn2, n}] = true;
        }

        for (size_t i = 1; i < n; ++i) {
            if (recursive_memo(s1, bgn1, s2, bgn2, i, cache) && recursive_memo(s1, bgn1 + i, s2, bgn2 + i, n - i, cache)) {
                return cache[{bgn1, bgn2, n}] = true;
            }

            if (recursive_memo(s1, bgn1, s2, bgn2 + n - i, i, cache) && recursive_memo(s1, bgn1 + i, s2, bgn2, n - i, cache)) {
                return cache[{bgn1, bgn2, n}] = true;
            }
        }

        return cache[{bgn1, bgn2, n}] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        
        //return recursive(s1, 0, s2, 0, s1.size());

        map<tuple<size_t, size_t, size_t>, bool> cache;
        return recursive_memo(s1, 0, s2, 0, s1.size(), cache);
    }
};
