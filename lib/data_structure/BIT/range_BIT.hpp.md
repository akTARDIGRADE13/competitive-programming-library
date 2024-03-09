---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/range_BIT/AOJ.test.cpp
    title: verify/data_structure/BIT/range_BIT/AOJ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/range_BIT/yosupo_point_add_range_sum.test.cpp
    title: verify/data_structure/BIT/range_BIT/yosupo_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/BIT/range_BIT.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct\
    \ range_BIT {\n    range_BIT() : n(0) {}\n    explicit range_BIT(int _n) : n(_n\
    \ + 2), vec(2, std::vector<T>(_n + 2, 0)) {}\n\n    void add(int l, int r, T x)\
    \ {\n        assert(l >= 0 && l < n - 1 && l < r && r < n);\n        ++l, ++r;\n\
    \        for(int i = l; i < n; i += i & (-i)) {\n            vec[0][i] -= x *\
    \ (l - 1);\n            vec[1][i] += x;\n        }\n        for(int i = r; i <\
    \ n; i += i & (-i)) {\n            vec[0][i] += x * (r - 1);\n            vec[1][i]\
    \ -= x;\n        }\n    }\n\n    T sum(int i) {\n        assert(i >= 0 && i <\
    \ n);\n        T ret(0);\n        int k = i;\n        while(i > 0) {\n       \
    \     ret += vec[1][i] * k + vec[0][i];\n            i -= i & (-i);\n        }\n\
    \        return ret;\n    }\n\n    T query(int l, int r) {\n        assert(l <=\
    \ r);\n        return sum(r) - sum(l);\n    }\n\n  private:\n    int n;\n    std::vector<std::vector<T>>\
    \ vec;\n};\n\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> struct range_BIT {\n    range_BIT() : n(0) {}\n \
    \   explicit range_BIT(int _n) : n(_n + 2), vec(2, std::vector<T>(_n + 2, 0))\
    \ {}\n\n    void add(int l, int r, T x) {\n        assert(l >= 0 && l < n - 1\
    \ && l < r && r < n);\n        ++l, ++r;\n        for(int i = l; i < n; i += i\
    \ & (-i)) {\n            vec[0][i] -= x * (l - 1);\n            vec[1][i] += x;\n\
    \        }\n        for(int i = r; i < n; i += i & (-i)) {\n            vec[0][i]\
    \ += x * (r - 1);\n            vec[1][i] -= x;\n        }\n    }\n\n    T sum(int\
    \ i) {\n        assert(i >= 0 && i < n);\n        T ret(0);\n        int k = i;\n\
    \        while(i > 0) {\n            ret += vec[1][i] * k + vec[0][i];\n     \
    \       i -= i & (-i);\n        }\n        return ret;\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(l <= r);\n        return sum(r) - sum(l);\n    }\n\
    \n  private:\n    int n;\n    std::vector<std::vector<T>> vec;\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/BIT/range_BIT.hpp
  requiredBy: []
  timestamp: '2024-03-09 21:05:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/BIT/range_BIT/yosupo_point_add_range_sum.test.cpp
  - verify/data_structure/BIT/range_BIT/AOJ.test.cpp
documentation_of: lib/data_structure/BIT/range_BIT.hpp
layout: document
title: range_BIT
---

## 概要

区間加算Binary indexed tree(BIT, Fenwick tree)のライブラリ．

## 使い方

- `range_BIT<T>(int n)`：サイズ$n$のBITを生成する．計算量$\mathrm{O}(n)$
- `add(int l, int r, T x)`：$[0, i)$の要素に$x$を足す．計算量$\mathrm{O}(\log n)$
- `sum(int i)`：$[0, i)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `query(int l, int r)`：$[l, r)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$