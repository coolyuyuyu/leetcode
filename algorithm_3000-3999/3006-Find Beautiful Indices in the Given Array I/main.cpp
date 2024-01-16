class Solution {
public:
    // Time: O(m * n)
    vector<int> findIndexes(const string& haystack, const string& needle) {
        int m = haystack.size(), n = needle.size();

        vector<int> ret;
        for (int i = 0; i + n <= m; ++i) {
            if (haystack.compare(i, n, needle) == 0) {
                ret.push_back(i);
            }
        }

        return ret;
    };

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indexes1 = findIndexes(s, a), indexes2 = findIndexes(s, b);
        int m = indexes1.size(), n = indexes2.size();

        vector<int> ret;
        for (int i1 = 0, i2 = 0; i1 < m; ++i1) {
            while (i2 < n && indexes2[i2] - indexes1[i1] <= k) {
                if (std::abs(indexes2[i2] - indexes1[i1]) <= k) {
                    break;
                }
                ++i2;
            }

            if (i2 < n && std::abs(indexes2[i2] - indexes1[i1]) <= k) {
                ret.push_back(indexes1[i1]);
            }
        }

        return ret;
    }
};
