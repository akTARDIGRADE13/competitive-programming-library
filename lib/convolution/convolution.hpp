#pragma once

#include "lib/math/ModInt/mint.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace akTARDIGRADE13{

template <int mod>
struct NTT{
   
    NTT() {
        pr = get_pr();
        depth = __builtin_ctz(mod - 1);
        root.assign(depth, 0);
        inv_root.assign(depth, 0);
        root[depth - 1] = mint<mod>(pr).pow((mod - 1) / (1<<depth));
        inv_root[depth - 1] = root[depth - 1].inv();
        for(int i = depth - 2; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            inv_root[i] = inv_root[i + 1] * inv_root[i + 1];
        }
    }
    
    std::vector<mint<mod>> multiply(std::vector<mint<mod>> a, std::vector<mint<mod>> b) {
        int n = a.size() + b.size() - 1;
        int m = 1;
        while(m <= n) {
            m <<= 1;
        }
        a.resize(m, 0);
        b.resize(m, 0);
        int d = 1;
        while((1 << d) < m) {
            d++;
        }
        a = ntt(a, d - 1), b = ntt(b, d - 1);
        for(int i = 0; i < m; i++) {
            a[i] *= b[i];
        }
        a = ntt(a, d - 1, true);
        mint<mod> inv = mint<mod>(m).inv();
        for(int i = 0; i < m; i++) {
            a[i] *= inv;
        }
        a.resize(n);
        return a;
    }

private:
    int get_pr() {
        if constexpr(mod == 998244353) {
            return 3;
        }else if constexpr(mod == 469762049){
            return 3;
        }else if constexpr(mod == 167772161){
            return 3;
        }else if constexpr(mod == 754974721){
            return 11;
        }else if constexpr(mod == 1224736769){
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
        while(true){
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

    std::vector<mint<mod>> ntt(std::vector<mint<mod>> a, int d, bool inv = false) {
        int n = a.size();
        if(n == 1) return a;
        std::vector<mint<mod>> even(n >> 1), odd(n >> 1);
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                odd[i >> 1] = a[i];
            } else {
                even[i >> 1] = a[i];
            }
        }
        even = ntt(even, d - 1, inv);
        odd = ntt(odd, d - 1, inv);
        mint<mod> w = 1, wn = (inv ? inv_root : root)[d];
        for(int i = 0; i < (n >> 1); i++) {
            a[i] = even[i] + w * odd[i];
            a[i + (n >> 1)] = even[i] - w * odd[i];
            w *= wn;
        }
        return a;
    }

    int pr;
    int depth;
    std::vector<mint<mod>> root, inv_root;
};

}