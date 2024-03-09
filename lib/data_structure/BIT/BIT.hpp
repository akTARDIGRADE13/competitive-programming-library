#pragma once

#include <cassert>
#include <vector>

namespace akTARDIGRADE13 {

template <typename T> struct BIT {
    BIT() : n(0) {}
    explicit BIT(int _n) : n(_n + 1), vec(_n + 1, 0) {}

    void add(int i, T x) {
        assert(i >= 0 && i < n - 1);
        ++i;
        while(i < n) {
            vec[i] += x;
            i += i & (-i);
        }
    }

    T sum(int i) {
        assert(i >= 0 && i < n);
        T ret(0);
        while(i > 0) {
            ret += vec[i];
            i -= i & (-i);
        }
        return ret;
    }

    T query(int l, int r) {
        assert(l <= r);
        return sum(r) - sum(l);
    }

    int binary_search(T x) {
        int ret = 0, r = 1;
        while(r < n)
            r = r << 1;
        while(r > 0) {
            if(ret + r < n && vec[ret + r] < x) {
                x -= vec[ret + r];
                ret += r;
            }
            r = r >> 1;
        }
        return ret;
    }

  private:
    int n;
    std::vector<T> vec;
};

} 