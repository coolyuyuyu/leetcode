#ifndef __DIFF_2D_HPP__25EB5F95_4CA5_45A4_A820_300127DCD23B
#define __DIFF_2D_HPP__25EB5F95_4CA5_45A4_A820_300127DCD23B

#include <vector>

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
    std::vector<vector<T>> diffs;
};

#endif
