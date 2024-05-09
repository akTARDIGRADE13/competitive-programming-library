---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/SegmentTree/Segtree.hpp
    title: Segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#line 2 \"lib/data_structure/SegmentTree/Segtree.hpp\"\n\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate\
    \ <typename T> struct Segtree {\n    explicit Segtree(int _n, std::function<T(T,\
    \ T)> _fx, T _ex)\n        : fx(_fx), ex(_ex) {\n        n = 1;\n        while(n\
    \ < _n)\n            n *= 2;\n        val.assign(n * 2, ex);\n    }\n\n    void\
    \ set_vec(std::vector<T> a) {\n        for(int i = 0; i < (int)a.size(); ++i)\n\
    \            val[i + n] = a[i];\n        for(int i = n - 1; i > 0; --i)\n    \
    \        val[i] = fx(val[i << 1], val[(i << 1) | 1]);\n    }\n\n    void set(int\
    \ i, T x) {\n        assert(i >= 0 && i < n);\n        i += n;\n        val[i]\
    \ = x;\n        i >>= 1;\n        while(i) {\n            val[i] = fx(val[i <<\
    \ 1], val[(i << 1) | 1]);\n            i >>= 1;\n        }\n    }\n\n    T prod(int\
    \ l, int r) {\n        assert(l >= 0 && r <= n && l <= r);\n        T vl = ex,\
    \ vr = ex;\n        l += n;\n        r += n;\n        while(l < r) {\n       \
    \     if(l & 1)\n                vl = fx(vl, val[l++]);\n            if(r & 1)\n\
    \                vr = fx(val[--r], vr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return fx(vl, vr);\n    }\n\n  private:\n    int n;\n\
    \    std::vector<T> val;\n    std::function<T(T, T)> fx;\n    const T ex;\n};\n\
    \n}\n#line 2 \"lib/math/ModInt/mint.hpp\"\n\n#line 4 \"lib/math/ModInt/mint.hpp\"\
    \n#include <iostream>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <int mod> struct\
    \ mint {\n    long long x;\n\n    mint(long long x = 0) : x(normalize(x)) {\n\
    \        static_assert(mod > 0, \"modulus must be positive\");\n        static_assert(mod\
    \ < (1 << 30), \"modulus must be small than 2*30\");\n    }\n\n    mint &operator++()\
    \ {\n        if(++x == mod)\n            x = 0;\n        return *this;\n    }\n\
    \n    mint operator++(int) {\n        mint result(*this);\n        ++(*this);\n\
    \        return result;\n    }\n\n    mint &operator--() {\n        if(--x < 0)\n\
    \            x += mod;\n        return *this;\n    }\n\n    mint operator--(int)\
    \ {\n        mint result(*this);\n        --(*this);\n        return result;\n\
    \    }\n\n    mint &operator+=(const mint &a) {\n        if((x += a.x) >= mod)\n\
    \            x -= mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
    \ mint &a) {\n        if((x += mod - a.x) >= mod)\n            x -= mod;\n   \
    \     return *this;\n    }\n\n    mint &operator*=(const mint &a) {\n        x\
    \ = (x * a.x) % mod;\n        return *this;\n    }\n\n    mint &operator/=(const\
    \ mint &a) { return *this *= a.inv(); }\n\n    mint operator-() const { return\
    \ mint(-x); }\n    mint operator+(const mint &a) const { return mint(*this) +=\
    \ a; }\n    mint operator-(const mint &a) const { return mint(*this) -= a; }\n\
    \    mint operator*(const mint &a) const { return mint(*this) *= a; }\n    mint\
    \ operator/(const mint &a) const { return mint(*this) /= a; }\n\n    bool operator==(const\
    \ mint &a) const { return x == a.x; }\n    bool operator!=(const mint &a) const\
    \ { return x != a.x; }\n\n    mint pow(long long t) const {\n        assert(t\
    \ >= 0);\n        mint res(1), a(*this);\n        while(t > 0) {\n           \
    \ if(t & 1)\n                res *= a;\n            a *= a;\n            t >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    mint inv() const { return pow(mod\
    \ - 2); }\n\n    static long long normalize(long long n) {\n        n %= mod;\n\
    \        if(n < 0)\n            n += mod;\n        return n;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, mint &m) {\n        is >> m.x;\n\
    \        m.x = normalize(m.x);\n        return is;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &m) {\n        os << m.x;\n       \
    \ return os;\n    }\n};\n\n}\n#line 5 \"verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp\"\
    \n\n#line 8 \"verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp\"\
    \n#include <tuple>\n#line 10 \"verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp\"\
    \n\nusing mint = akTARDIGRADE13::mint<998244353>;\n\nint main() {\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    std::vector<std::pair<mint, mint>> vec(n);\n\
    \    for(int i = 0; i < n; ++i)\n        std::cin >> vec[i].first >> vec[i].second;\n\
    \    auto fx = [](const std::pair<mint, mint> &lhs,\n                 const std::pair<mint,\
    \ mint> &rhs) -> std::pair<mint, mint> {\n        return std::pair<mint, mint>(lhs.first\
    \ * rhs.first,\n                                     rhs.first * lhs.second +\
    \ rhs.second);\n    };\n    std::pair<mint, mint> ex = std::pair<mint, mint>(1,\
    \ 0);\n    akTARDIGRADE13::Segtree<std::pair<mint, mint>> seg(n, fx, ex);\n  \
    \  seg.set_vec(vec);\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \        if(t) {\n            int l, r, x;\n            std::cin >> l >> r >>\
    \ x;\n            auto ret = seg.prod(l, r);\n            std::cout << ret.first\
    \ * x + ret.second << std::endl;\n        } else {\n            int p, c, d;\n\
    \            std::cin >> p >> c >> d;\n            seg.set(p, std::pair<mint,\
    \ mint>(c, d));\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"lib/data_structure/SegmentTree/Segtree.hpp\"\n#include \"lib/math/ModInt/mint.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n#include <tuple>\n#include <vector>\n\
    \nusing mint = akTARDIGRADE13::mint<998244353>;\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector<std::pair<mint, mint>> vec(n);\n   \
    \ for(int i = 0; i < n; ++i)\n        std::cin >> vec[i].first >> vec[i].second;\n\
    \    auto fx = [](const std::pair<mint, mint> &lhs,\n                 const std::pair<mint,\
    \ mint> &rhs) -> std::pair<mint, mint> {\n        return std::pair<mint, mint>(lhs.first\
    \ * rhs.first,\n                                     rhs.first * lhs.second +\
    \ rhs.second);\n    };\n    std::pair<mint, mint> ex = std::pair<mint, mint>(1,\
    \ 0);\n    akTARDIGRADE13::Segtree<std::pair<mint, mint>> seg(n, fx, ex);\n  \
    \  seg.set_vec(vec);\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \        if(t) {\n            int l, r, x;\n            std::cin >> l >> r >>\
    \ x;\n            auto ret = seg.prod(l, r);\n            std::cout << ret.first\
    \ * x + ret.second << std::endl;\n        } else {\n            int p, c, d;\n\
    \            std::cin >> p >> c >> d;\n            seg.set(p, std::pair<mint,\
    \ mint>(c, d));\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - lib/data_structure/SegmentTree/Segtree.hpp
  - lib/math/ModInt/mint.hpp
  isVerificationFile: true
  path: verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-03-17 10:14:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
- /verify/verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp.html
title: verify/data_structure/SegmentTree/Segtree/yosupo_point_set_range_composite.test.cpp
---
