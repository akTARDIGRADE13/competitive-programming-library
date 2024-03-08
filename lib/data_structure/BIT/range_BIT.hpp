#pragma once

#include <vector>

namespace akTARDIGRADE13 {

template <typename T> struct range_BIT {
    range_BIT() : n(0) {}
    explicit range_BIT(int _n) : n(_n + 2), vec(2, std::vector<T>(_n + 2, 0)) {}

    void add(int l, int r, T x) {
        ++l, ++r;
        for(int i = l; i < n; i += i & (-i)) {
            vec[0][i] -= x * (l - 1);
            vec[1][i] += x;
        }
        for(int i = r; i < n; i += i & (-i)) {
            vec[0][i] += x * (r - 1);
            vec[1][i] -= x;
        }
    }

    T sum(int i) {
        T ret(0);
        int k = i;
        while(i > 0) {
            ret += vec[1][i] * k + vec[0][i];
            i -= i & (-i);
        }
        return ret;
    }

    T query(int l, int r) { return sum(r) - sum(l); }

  private:
    int n;
    std::vector<std::vector<T>> vec;
};

} 