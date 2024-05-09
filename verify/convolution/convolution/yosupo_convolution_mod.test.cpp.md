---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/Convolution.hpp
    title: convolution
  - icon: ':heavy_check_mark:'
    path: lib/math/ModInt/mint.hpp
    title: mint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/convolution/convolution/yosupo_convolution_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line\
    \ 2 \"lib/convolution/Convolution.hpp\"\n\n#line 2 \"lib/math/ModInt/mint.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nnamespace akTARDIGRADE13 {\n\n\
    template <int mod> struct mint {\n    long long x;\n\n    mint(long long x = 0)\
    \ : x(normalize(x)) {\n        static_assert(mod > 0, \"modulus must be positive\"\
    );\n        static_assert(mod < (1 << 30), \"modulus must be small than 2*30\"\
    );\n    }\n\n    mint &operator++() {\n        if(++x == mod)\n            x =\
    \ 0;\n        return *this;\n    }\n\n    mint operator++(int) {\n        mint\
    \ result(*this);\n        ++(*this);\n        return result;\n    }\n\n    mint\
    \ &operator--() {\n        if(--x < 0)\n            x += mod;\n        return\
    \ *this;\n    }\n\n    mint operator--(int) {\n        mint result(*this);\n \
    \       --(*this);\n        return result;\n    }\n\n    mint &operator+=(const\
    \ mint &a) {\n        if((x += a.x) >= mod)\n            x -= mod;\n        return\
    \ *this;\n    }\n\n    mint &operator-=(const mint &a) {\n        if((x += mod\
    \ - a.x) >= mod)\n            x -= mod;\n        return *this;\n    }\n\n    mint\
    \ &operator*=(const mint &a) {\n        x = (x * a.x) % mod;\n        return *this;\n\
    \    }\n\n    mint &operator/=(const mint &a) { return *this *= a.inv(); }\n\n\
    \    mint operator-() const { return mint(-x); }\n    mint operator+(const mint\
    \ &a) const { return mint(*this) += a; }\n    mint operator-(const mint &a) const\
    \ { return mint(*this) -= a; }\n    mint operator*(const mint &a) const { return\
    \ mint(*this) *= a; }\n    mint operator/(const mint &a) const { return mint(*this)\
    \ /= a; }\n\n    bool operator==(const mint &a) const { return x == a.x; }\n \
    \   bool operator!=(const mint &a) const { return x != a.x; }\n\n    mint pow(long\
    \ long t) const {\n        assert(t >= 0);\n        mint res(1), a(*this);\n \
    \       while(t > 0) {\n            if(t & 1)\n                res *= a;\n   \
    \         a *= a;\n            t >>= 1;\n        }\n        return res;\n    }\n\
    \n    mint inv() const { return pow(mod - 2); }\n\n    static long long normalize(long\
    \ long n) {\n        n %= mod;\n        if(n < 0)\n            n += mod;\n   \
    \     return n;\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ mint &m) {\n        is >> m.x;\n        m.x = normalize(m.x);\n        return\
    \ is;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os, const mint\
    \ &m) {\n        os << m.x;\n        return os;\n    }\n};\n\n}\n#line 4 \"lib/convolution/Convolution.hpp\"\
    \n\n#include <algorithm>\n#line 7 \"lib/convolution/Convolution.hpp\"\n#include\
    \ <vector>\n\nnamespace akTARDIGRADE13{\n\ntemplate <int mod>\nstruct NTT{\n \
    \  \n    NTT() {\n        pr = get_pr();\n        depth = __builtin_ctz(mod -\
    \ 1);\n        root.assign(depth, 0);\n        inv_root.assign(depth, 0);\n  \
    \      root[depth - 1] = mint<mod>(pr).pow((mod - 1) / (1<<depth));\n        inv_root[depth\
    \ - 1] = root[depth - 1].inv();\n        for(int i = depth - 2; i >= 0; i--) {\n\
    \            root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n    }\n    \n    std::vector<mint<mod>>\
    \ multiply(std::vector<mint<mod>> a, std::vector<mint<mod>> b) {\n        int\
    \ n = a.size() + b.size() - 1;\n        int m = 1;\n        while(m <= n) {\n\
    \            m <<= 1;\n        }\n        a.resize(m, 0);\n        b.resize(m,\
    \ 0);\n        int d = 1;\n        while((1 << d) < m) {\n            d++;\n \
    \       }\n        a = ntt(a, d), b = ntt(b, d);\n        for(int i = 0; i < m;\
    \ i++) {\n            a[i] *= b[i];\n        }\n        a = ntt(a, d, true);\n\
    \        mint<mod> inv = mint<mod>(m).inv();\n        for(int i = 0; i < m; i++)\
    \ {\n            a[i] *= inv;\n        }\n        a.resize(n);\n        return\
    \ a;\n    }\n\nprivate:\n    int get_pr() {\n        if constexpr(mod == 998244353)\
    \ {\n            return 3;\n        }else if constexpr(mod == 469762049){\n  \
    \          return 3;\n        }else if constexpr(mod == 167772161){\n        \
    \    return 3;\n        }else if constexpr(mod == 754974721){\n            return\
    \ 11;\n        }else if constexpr(mod == 1224736769){\n            return 3;\n\
    \        }\n        long long ds[32] = {};\n        int idx = 0;\n        long\
    \ long m = mod - 1;\n        for(long long i = 2; i * i <= m; i++) {\n       \
    \     if(m % i == 0) {\n                ds[idx++] = i;\n                while(m\
    \ % i == 0) {\n                    m /= i;\n                }\n            }\n\
    \        }\n        if(m > 1) {\n            ds[idx++] = m;\n        }\n     \
    \   int ret = 2;\n        while(true){\n            bool ok = true;\n        \
    \    for(int i = 0; i < idx; i++) {\n                if(mint<mod>(ret).pow((mod\
    \ - 1) / ds[i]) == 1) {\n                    ok = false;\n                   \
    \ break;\n                }\n            }\n            if(ok) {\n           \
    \     return ret;\n            }\n            ret++;\n        }\n        return\
    \ ret;\n    }\n\n    std::vector<mint<mod>> ntt(std::vector<mint<mod>> a, int\
    \ d, bool inv = false) {\n        int n = a.size();\n        if(n == 1) return\
    \ a;\n        for(int i = 0; i < n; i++) {\n            int j = 0;\n         \
    \   for(int k = 0; k < d; k++) {\n                if(i >> k & 1) {\n         \
    \           j |= 1 << (d - 1 - k);\n                }\n            }\n       \
    \     if(i < j) {\n                std::swap(a[i], a[j]);\n            }\n   \
    \     }\n        for(int i = 0; i < d; i++) {\n            int m = 1 << i;\n \
    \           mint<mod> w = 1, wn = (inv ? inv_root : root)[i];\n            for(int\
    \ j = 0; j < m; j++) {\n                for(int k = 0; k < n; k += m << 1) {\n\
    \                    mint<mod> s = a[j | k], t = w * a[j | k | m];\n         \
    \           a[j | k] = s + t;\n                    a[j | k | m] = s - t;\n   \
    \             }\n                w *= wn;\n            }\n        }\n        return\
    \ a;\n    }\n\n    int pr;\n    int depth;\n    std::vector<mint<mod>> root, inv_root;\n\
    };\n\n}\n#line 5 \"verify/convolution/convolution/yosupo_convolution_mod.test.cpp\"\
    \n\nusing mint = akTARDIGRADE13::mint<998244353>;\n\n#line 9 \"verify/convolution/convolution/yosupo_convolution_mod.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ a(n), b(m);\n    for(int i = 0; i < n; ++i) std::cin >> a[i];\n    for(int i\
    \ = 0; i < m; ++i) std::cin >> b[i];\n    akTARDIGRADE13::NTT<998244353> convolution;\n\
    \    auto c = convolution.multiply(a, b);\n    for(int i = 0; i < n + m - 1; ++i)\
    \ {\n        std::cout << c[i] << ' ';\n    }\n    std::cout << std::endl;\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"lib/convolution/Convolution.hpp\"\n#include \"lib/math/ModInt/mint.hpp\"\n\
    \nusing mint = akTARDIGRADE13::mint<998244353>;\n\n#include <iostream>\n\nint\
    \ main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint> a(n),\
    \ b(m);\n    for(int i = 0; i < n; ++i) std::cin >> a[i];\n    for(int i = 0;\
    \ i < m; ++i) std::cin >> b[i];\n    akTARDIGRADE13::NTT<998244353> convolution;\n\
    \    auto c = convolution.multiply(a, b);\n    for(int i = 0; i < n + m - 1; ++i)\
    \ {\n        std::cout << c[i] << ' ';\n    }\n    std::cout << std::endl;\n\n\
    \    return 0;\n}"
  dependsOn:
  - lib/convolution/Convolution.hpp
  - lib/math/ModInt/mint.hpp
  isVerificationFile: true
  path: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2024-05-09 09:47:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp.html
title: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
---
