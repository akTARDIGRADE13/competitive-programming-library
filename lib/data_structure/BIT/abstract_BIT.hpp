#pragma once

#include <functional>
#include <vector>

namespace akTARDIGRADE13 {

template <typename T> struct BIT {
    BIT() : n(0) {}
    explicit BIT(int _n, std::function<T(T, T)> _fx, std::function<T(T)> _inv, T _ex)
        : n(_n + 1), vec(_n + 1, 0), fx(_fx), inv(_inv), ex(_ex) {}

    void add(int i, T x) {
        ++i;
        while(i < n) {
            vec[i] = fx(vec[i], x);
            i += i & (-i);
        }
    }

    T sum(int i) {
        if(i == 0)
            return 0;
        T ret = ex;
        while(i > 0) {
            ret = fx(vec[i], ret);
            i -= i & (-i);
        }
        return ret;
    }

    T query(int l, int r) { return fx(sum(r), inv(sum(l))); }

    int binary_search(T x) {
        int ret = 0, r = 1;
        while(r < n)
            r = r << 1;
        while(r > 0) {
            if(ret + r < n && vec[ret + r] < x) {
                x = fx(x, inv(vec[ret + r]));
                ret += r;
            }
            r = r >> 1;
        }
        return ret;
    }

  private:
    int n;
    std::vector<T> vec;
    std::function<T(T, T)> fx;
    std::function<T(T)> inv;
    const T ex;
};

}