---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/math/ModInt/mint/yosupo_https:/judge.yosupo.jp/problem/binomial_coefficient_prime_mod.test.cpp
    title: verify/math/ModInt/mint/yosupo_https:/judge.yosupo.jp/problem/binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/ModInt/mint.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <int mod> struct mint {\n\
    \    long long x;\n\n    mint(long long x = 0) : x(normalize(x)) {\n        static_assert(mod\
    \ > 0, \"modulus must be positive\");\n        static_assert(mod < (1 << 30),\
    \ \"modulus must be small than 2*30\");\n    }\n\n    mint &operator++() {\n \
    \       if(++x == mod)\n            x = 0;\n        return *this;\n    }\n\n \
    \   mint operator++(int) {\n        mint result(*this);\n        ++(*this);\n\
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
    \ return os;\n    }\n};\n\ntemplate <int id> struct d_mint {\n    using mint =\
    \ d_mint;\n    static int mod;\n    long long x;\n\n    d_mint(long long x = 0)\
    \ : x(normalize(x)) {}\n\n    static void set_mod(int m) {\n        assert(m >\
    \ 0 && \"modulus must be positive\");\n        assert(m < (1 << 30) && \"modulus\
    \ must be smaller than 2^30\");\n        mod = m;\n    }\n\n    mint &operator++()\
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
    \ return os;\n    }\n};\n\ntemplate <int id> int d_mint<id>::mod;\n\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <int mod> struct mint {\n    long long x;\n\n    mint(long long\
    \ x = 0) : x(normalize(x)) {\n        static_assert(mod > 0, \"modulus must be\
    \ positive\");\n        static_assert(mod < (1 << 30), \"modulus must be small\
    \ than 2*30\");\n    }\n\n    mint &operator++() {\n        if(++x == mod)\n \
    \           x = 0;\n        return *this;\n    }\n\n    mint operator++(int) {\n\
    \        mint result(*this);\n        ++(*this);\n        return result;\n   \
    \ }\n\n    mint &operator--() {\n        if(--x < 0)\n            x += mod;\n\
    \        return *this;\n    }\n\n    mint operator--(int) {\n        mint result(*this);\n\
    \        --(*this);\n        return result;\n    }\n\n    mint &operator+=(const\
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
    \ &m) {\n        os << m.x;\n        return os;\n    }\n};\n\ntemplate <int id>\
    \ struct d_mint {\n    using mint = d_mint;\n    static int mod;\n    long long\
    \ x;\n\n    d_mint(long long x = 0) : x(normalize(x)) {}\n\n    static void set_mod(int\
    \ m) {\n        assert(m > 0 && \"modulus must be positive\");\n        assert(m\
    \ < (1 << 30) && \"modulus must be smaller than 2^30\");\n        mod = m;\n \
    \   }\n\n    mint &operator++() {\n        if(++x == mod)\n            x = 0;\n\
    \        return *this;\n    }\n\n    mint operator++(int) {\n        mint result(*this);\n\
    \        ++(*this);\n        return result;\n    }\n\n    mint &operator--() {\n\
    \        if(--x < 0)\n            x += mod;\n        return *this;\n    }\n\n\
    \    mint operator--(int) {\n        mint result(*this);\n        --(*this);\n\
    \        return result;\n    }\n\n    mint &operator+=(const mint &a) {\n    \
    \    if((x += a.x) >= mod)\n            x -= mod;\n        return *this;\n   \
    \ }\n\n    mint &operator-=(const mint &a) {\n        if((x += mod - a.x) >= mod)\n\
    \            x -= mod;\n        return *this;\n    }\n\n    mint &operator*=(const\
    \ mint &a) {\n        x = (x * a.x) % mod;\n        return *this;\n    }\n\n \
    \   mint &operator/=(const mint &a) { return *this *= a.inv(); }\n\n    mint operator-()\
    \ const { return mint(-x); }\n    mint operator+(const mint &a) const { return\
    \ mint(*this) += a; }\n    mint operator-(const mint &a) const { return mint(*this)\
    \ -= a; }\n    mint operator*(const mint &a) const { return mint(*this) *= a;\
    \ }\n    mint operator/(const mint &a) const { return mint(*this) /= a; }\n\n\
    \    bool operator==(const mint &a) const { return x == a.x; }\n    bool operator!=(const\
    \ mint &a) const { return x != a.x; }\n\n    mint pow(long long t) const {\n \
    \       assert(t >= 0);\n        mint res(1), a(*this);\n        while(t > 0)\
    \ {\n            if(t & 1)\n                res *= a;\n            a *= a;\n \
    \           t >>= 1;\n        }\n        return res;\n    }\n\n    mint inv()\
    \ const { return pow(mod - 2); }\n\n    static long long normalize(long long n)\
    \ {\n        n %= mod;\n        if(n < 0)\n            n += mod;\n        return\
    \ n;\n    }\n\n    friend std::istream &operator>>(std::istream &is, mint &m)\
    \ {\n        is >> m.x;\n        m.x = normalize(m.x);\n        return is;\n \
    \   }\n\n    friend std::ostream &operator<<(std::ostream &os, const mint &m)\
    \ {\n        os << m.x;\n        return os;\n    }\n};\n\ntemplate <int id> int\
    \ d_mint<id>::mod;\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/ModInt/mint.hpp
  requiredBy: []
  timestamp: '2024-03-17 08:53:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/math/ModInt/mint/yosupo_https:/judge.yosupo.jp/problem/binomial_coefficient_prime_mod.test.cpp
documentation_of: lib/math/ModInt/mint.hpp
layout: document
title: mint
---

## 概要

静的modintと動的modintのライブラリ

## 使い方

