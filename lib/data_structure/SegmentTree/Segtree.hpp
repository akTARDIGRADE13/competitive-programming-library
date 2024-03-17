#pragma once

#include <cassert>
#include <functional>
#include <vector>

namespace akTARDIGRADE13 {

template <typename T> struct Segtree {
    explicit Segtree(int _n, std::function<T(T, T)> _fx, T _ex)
        : fx(_fx), ex(_ex) {
        n = 1;
        while(n < _n)
            n *= 2;
        val.assign(n * 2, ex);
    }

    void set_vec(std::vector<T> a) {
        for(int i = 0; i < (int)a.size(); ++i)
            val[i + n] = a[i];
        for(int i = n - 1; i > 0; --i)
            val[i] = fx(val[i << 1], val[(i << 1) | 1]);
    }

    void set(int i, T x) {
        assert(i >= 0 && i < n);
        i += n;
        val[i] = x;
        i >>= 1;
        while(i) {
            val[i] = fx(val[i << 1], val[(i << 1) | 1]);
            i >>= 1;
        }
    }

    T prod(int l, int r) {
        assert(l >= 0 && r <= n && l <= r);
        T vl = ex, vr = ex;
        l += n;
        r += n;
        while(l < r) {
            if(l & 1)
                vl = fx(vl, val[l++]);
            if(r & 1)
                vr = fx(val[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return fx(vl, vr);
    }

  private:
    int n;
    std::vector<T> val;
    std::function<T(T, T)> fx;
    const T ex;
};

} // namespace akTARDIGRADE13