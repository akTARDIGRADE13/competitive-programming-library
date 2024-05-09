#pragma once

#include "lib/math/ModInt/mint.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace akTARDIGRADE13 {

template <int mod> struct NTT {

    NTT() : pr(get_pr()) {}

    std::vector<mint<mod>> multiply(std::vector<mint<mod>> a,
                                    std::vector<mint<mod>> b) {
        int n = a.size() + b.size() - 1;
        int m = 1;
        while(m < n) {
            m <<= 1;
        }
        a.resize(m, 0);
        b.resize(m, 0);
        ntt(a), ntt(b);
        for(int i = 0; i < m; i++) {
            a[i] *= b[i];
        }
        intt(a);
        a.resize(n);
        return a;
    }

private:
    int get_pr() {
        if constexpr(mod == 998244353) {
            return 3;
        } else if constexpr(mod == 469762049) {
            return 3;
        } else if constexpr(mod == 167772161) {
            return 3;
        } else if constexpr(mod == 754974721) {
            return 11;
        } else if constexpr(mod == 1224736769) {
            return 3;
        }
        long long ds[32] = {};
        int idx = 0;
        long long m = mod - 1;
        for(long long i = 2; i * i <= m; i++) {
            if(m % i == 0) {
                ds[idx++] = i;
                while(m % i == 0) {
                    m /= i;
                }
            }
        }
        if(m > 1) {
            ds[idx++] = m;
        }
        int ret = 2;
        while(true) {
            bool ok = true;
            for(int i = 0; i < idx; i++) {
                if(mint<mod>(ret).pow((mod - 1) / ds[i]) == 1) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                return ret;
            }
            ret++;
        }
        return ret;
    }

    void ntt(std::vector<mint<mod>> &a) {
        int n = a.size();
        int width = n;
        int offset = width >> 1;
        while(width > 1) {
            mint<mod> w = get_root(width);
            for(int top = 0; top < n; top += width) {
                mint<mod> ws = 1;
                for(int i = top; i < top + offset; i++) {
                    mint<mod> s = a[i];
                    mint<mod> t = a[i + offset];
                    a[i] = s + t;
                    a[i + offset] = (s - t) * ws;
                    ws *= w;
                }
            }
            width >>= 1;
            offset >>= 1;
        }
    }

    void intt(std::vector<mint<mod>> &a) {
        int n = a.size();
        int width = 2;
        int offset = 1;
        while(width <= n) {
            mint<mod> w = get_root(width).inv();
            for(int top = 0; top < n; top += width) {
                mint<mod> ws = 1;
                for(int i = top; i < top + offset; i++) {
                    mint<mod> s = a[i];
                    mint<mod> t = a[i + offset] * ws;
                    a[i] = s + t;
                    a[i + offset] = s - t;
                    ws *= w;
                }
            }
            width <<= 1;
            offset <<= 1;
        }
        mint<mod> inv = mint<mod>(n).inv();
        for(auto &i : a) {
            i *= inv;
        }
    }

    mint<mod> get_root(int n) { return mint<mod>(pr).pow((mod - 1) / n); }

    int pr;
};

} // namespace akTARDIGRADE13