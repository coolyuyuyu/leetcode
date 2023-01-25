#ifndef __DIFF_1D_HPP__FE6A7DB5_9DE6_4051_92D3_B85545DB12A4
#define __DIFF_1D_HPP__FE6A7DB5_9DE6_4051_92D3_B85545DB12A4

#include <vector>

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

#endif
