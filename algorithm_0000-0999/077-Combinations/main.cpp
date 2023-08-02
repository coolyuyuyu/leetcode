class Solution {
public:
    vector<vector<int>> recursion(int n, int k) {
        vector<vector<int>> ret;

        vector<int> comb;
        std::function<void(int)> f = [&](int start) {
            if (comb.size() == k) {
                ret.push_back(comb);
                return;
            }

            for (int num = start, end = (comb.size() + n - k + 1); num <= end; ++num) {
                comb.push_back(num);
                f(num + 1);
                comb.pop_back();
            }
        };
        f(1);

        return ret;
    }

    vector<vector<int>> iterative(int n, int k) {
        vector<vector<int>> ret;

        vector<int> comb(k);
        for (int i = 0; 0 <= i;) {
            ++comb[i];

            for (int j = i + 1; j < k; ++j) {
                comb[j] = comb[j - 1] + 1;
            }
            ret.push_back(comb);

            i = k - 1;
            while (0 <= i && comb[i] == (i + n - k + 1)) {
                --i;
            }
        }

        return ret;
    }

    vector<vector<int>> combine(int n, int k) {
        //return recursion(n, k);
        return iterative(n, k);
    }
};
