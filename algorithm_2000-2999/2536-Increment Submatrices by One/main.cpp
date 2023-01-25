class Solution {
public:
    template<typename T>
    class Diff1D {
    public:
        Diff1D(size_t count)
            : diffs(count, 0) {
        }

        void update(size_t lft, size_t rht, T delta) {
            diffs[lft] += delta;
            if ((rht + 1) < size()) {
                diffs[rht + 1] -= delta;
            }
        }

        size_t size() const {
            return diffs.size();
        }

        template<typename OutputIterator>
        void construct(OutputIterator itr) {
            T sum = 0;
            for (T diff : diffs) {
                sum += diff;
                *itr++ = sum;
            }
        }

    private:
        vector<T> diffs;
    };

    vector<vector<int>> byDiff1D(int n, vector<vector<int>>& queries) {
        vector<Diff1D<int>> diffs(n, Diff1D<int>(n));
        for (const auto& query : queries) {
            for (int r = query[0]; r <= query[2]; ++r) {
                diffs[r].update(query[1], query[3], 1);
            }
        }

        vector<vector<int>> nums(n, vector<int>(n));
        for (int r = 0; r < n; ++r) {
            diffs[r].construct(nums[r].begin());
        }
        return nums;
    }

    template<typename T>
    class Diff2D {
    public:
        Diff2D(size_t rowCount, size_t colCount)
            : diffs(rowCount, vector<T>(colCount, 0)) {
        }

        void update(size_t lft, size_t rht, T delta) {
            diffs[lft] += delta;
            if ((rht + 1) < size()) {
                diffs[rht + 1] -= delta;
            }
        }

        void update(size_t rowTL, size_t colTL, size_t rowBR, size_t colBR, T delta) {
            diffs[rowTL][colTL] += delta;
            if ((rowBR + 1) < rowCount()) {
                diffs[rowBR + 1][colTL] -= delta;
            }
            if ((colBR + 1) < colCount()) {
                diffs[rowTL][colBR + 1] -= delta;
            }
            if ((rowBR + 1) < rowCount() && (colBR + 1) < colCount()) {
                diffs[rowBR + 1][colBR + 1] += delta;
            }
        }

        size_t rowCount() const {
            return diffs.size();
        }

        size_t colCount() const {
            return diffs.empty() ? 0 : diffs[0].size();
        }

        size_t size() const {
            return rowCount() * colCount();
        }

        template<typename OutputIterator>
        void construct(OutputIterator itr) {
            for (size_t r = 0; r < rowCount(); ++r) {
                for (size_t c = 0; c < colCount(); ++c) {
                    auto itrNum = (itr + r)->begin() + (c);
                    *itrNum = diffs[r][c];
                    if (0 < r) {
                        *itrNum += (itr + r - 1)->at(c);
                    }
                    if (0 < c) {
                        *itrNum += (itr + r)->at(c - 1);
                    }
                    if (0 < r && 0 < c) {
                        *itrNum -= (itr + r - 1)->at(c - 1);
                    }
                }
            }
        }

    private:
        vector<vector<T>> diffs;
    };

    vector<vector<int>> byDiff2D(int n, vector<vector<int>>& queries) {
        Diff2D<int> diffs(n, n);
        for (const auto& query : queries) {
            diffs.update(query[0], query[1], query[2], query[3], 1);
        }

        vector<vector<int>> nums(n, vector<int>(n));
        diffs.construct(nums.begin());
        return nums;
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //return byDiff1D(n, queries);
        return byDiff2D(n, queries);
    }
};
