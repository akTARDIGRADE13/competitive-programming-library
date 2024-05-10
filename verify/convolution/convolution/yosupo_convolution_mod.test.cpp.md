---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/Convolution.hpp
    title: Convolution
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
    \ <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <int mod> struct NTT {\n\n\
    \    NTT() : pr(get_pr()) {}\n\n    std::vector<mint<mod>> multiply(std::vector<mint<mod>>\
    \ a,\n                                    std::vector<mint<mod>> b) {\n      \
    \  int n = a.size() + b.size() - 1;\n        int m = 1;\n        while(m < n)\
    \ {\n            m <<= 1;\n        }\n        a.resize(m, 0);\n        b.resize(m,\
    \ 0);\n        ntt(a), ntt(b);\n        for(int i = 0; i < m; i++) {\n       \
    \     a[i] *= b[i];\n        }\n        intt(a);\n        a.resize(n);\n     \
    \   return a;\n    }\n\nprivate:\n    int get_pr() {\n        if constexpr(mod\
    \ == 998244353) {\n            return 3;\n        } else if constexpr(mod == 469762049)\
    \ {\n            return 3;\n        } else if constexpr(mod == 167772161) {\n\
    \            return 3;\n        } else if constexpr(mod == 754974721) {\n    \
    \        return 11;\n        } else if constexpr(mod == 1224736769) {\n      \
    \      return 3;\n        }\n        long long ds[32] = {};\n        int idx =\
    \ 0;\n        long long m = mod - 1;\n        for(long long i = 2; i * i <= m;\
    \ i++) {\n            if(m % i == 0) {\n                ds[idx++] = i;\n     \
    \           while(m % i == 0) {\n                    m /= i;\n               \
    \ }\n            }\n        }\n        if(m > 1) {\n            ds[idx++] = m;\n\
    \        }\n        int ret = 2;\n        while(true) {\n            bool ok =\
    \ true;\n            for(int i = 0; i < idx; i++) {\n                if(mint<mod>(ret).pow((mod\
    \ - 1) / ds[i]) == 1) {\n                    ok = false;\n                   \
    \ break;\n                }\n            }\n            if(ok) {\n           \
    \     return ret;\n            }\n            ret++;\n        }\n        return\
    \ ret;\n    }\n\n    void ntt(std::vector<mint<mod>> &a) {\n        int n = a.size();\n\
    \        int width = n;\n        int offset = width >> 1;\n        while(width\
    \ > 1) {\n            mint<mod> w = get_root(width);\n            for(int top\
    \ = 0; top < n; top += width) {\n                mint<mod> ws = 1;\n         \
    \       for(int i = top; i < (top + offset); i++) {\n                    mint<mod>\
    \ s = a[i];\n                    mint<mod> t = a[i + offset];\n              \
    \      a[i] = s + t;\n                    a[i + offset] = (s - t) * ws;\n    \
    \                ws *= w;\n                }\n            }\n            width\
    \ >>= 1;\n            offset >>= 1;\n        }\n    }\n\n    void intt(std::vector<mint<mod>>\
    \ &a) {\n        int n = a.size();\n        int width = 2;\n        int offset\
    \ = 1;\n        while(width <= n) {\n            mint<mod> w = get_root(width).inv();\n\
    \            for(int top = 0; top < n; top += width) {\n                mint<mod>\
    \ ws = 1;\n                for(int i = top; i < (top + offset); i++) {\n     \
    \               mint<mod> s = a[i];\n                    mint<mod> t = a[i + offset]\
    \ * ws;\n                    a[i] = s + t;\n                    a[i + offset]\
    \ = s - t;\n                    ws *= w;\n                }\n            }\n \
    \           width <<= 1;\n            offset <<= 1;\n        }\n        mint<mod>\
    \ inv = mint<mod>(n).inv();\n        for(auto &i : a) {\n            i *= inv;\n\
    \        }\n    }\n\n    mint<mod> get_root(int n) { return mint<mod>(pr).pow((mod\
    \ - 1) / n); }\n\n    int pr;\n};\n\n} // namespace akTARDIGRADE13\n#line 5 \"\
    verify/convolution/convolution/yosupo_convolution_mod.test.cpp\"\n\nusing mint\
    \ = akTARDIGRADE13::mint<998244353>;\n\n#line 9 \"verify/convolution/convolution/yosupo_convolution_mod.test.cpp\"\
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
  timestamp: '2024-05-09 14:59:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp
- /verify/verify/convolution/convolution/yosupo_convolution_mod.test.cpp.html
title: verify/convolution/convolution/yosupo_convolution_mod.test.cpp
---
