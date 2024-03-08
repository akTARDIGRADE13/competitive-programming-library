---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/AOJ_BIT.test.cpp
    title: verify/data_structure/BIT/AOJ_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/yosupo_BIT.test.cpp
    title: verify/data_structure/BIT/yosupo_BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/BIT/BIT.hpp\"\n\n#include <vector>\n\n\
    namespace akTARDIGRADE13 {\n\ntemplate <typename T> struct BIT {\n    BIT() :\
    \ n(0) {}\n    explicit BIT(int _n) : n(_n + 1), vec(_n + 1, 0) {}\n\n    void\
    \ add(int i, T x) {\n        ++i;\n        while(i < n) {\n            vec[i]\
    \ += x;\n            i += i & (-i);\n        }\n    }\n\n    T sum(int i) {\n\
    \        T ret(0);\n        while(i > 0) {\n            ret += vec[i];\n     \
    \       i -= i & (-i);\n        }\n        return ret;\n    }\n\n    T query(int\
    \ l, int r) { return sum(r) - sum(l); }\n\n    int binary_search(T x) {\n    \
    \    int ret = 0, r = 1;\n        while(r < n)\n            r = r << 1;\n    \
    \    while(r > 0) {\n            if(ret + r < n && vec[ret + r] < x) {\n     \
    \           x -= vec[ret + r];\n                ret += r;\n            }\n   \
    \         r = r >> 1;\n        }\n        return ret;\n    }\n\n  private:\n \
    \   int n;\n    std::vector<T> vec;\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate\
    \ <typename T> struct BIT {\n    BIT() : n(0) {}\n    explicit BIT(int _n) : n(_n\
    \ + 1), vec(_n + 1, 0) {}\n\n    void add(int i, T x) {\n        ++i;\n      \
    \  while(i < n) {\n            vec[i] += x;\n            i += i & (-i);\n    \
    \    }\n    }\n\n    T sum(int i) {\n        T ret(0);\n        while(i > 0) {\n\
    \            ret += vec[i];\n            i -= i & (-i);\n        }\n        return\
    \ ret;\n    }\n\n    T query(int l, int r) { return sum(r) - sum(l); }\n\n   \
    \ int binary_search(T x) {\n        int ret = 0, r = 1;\n        while(r < n)\n\
    \            r = r << 1;\n        while(r > 0) {\n            if(ret + r < n &&\
    \ vec[ret + r] < x) {\n                x -= vec[ret + r];\n                ret\
    \ += r;\n            }\n            r = r >> 1;\n        }\n        return ret;\n\
    \    }\n\n  private:\n    int n;\n    std::vector<T> vec;\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/BIT/BIT.hpp
  requiredBy: []
  timestamp: '2024-03-08 18:18:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/BIT/yosupo_BIT.test.cpp
  - verify/data_structure/BIT/AOJ_BIT.test.cpp
documentation_of: lib/data_structure/BIT/BIT.hpp
layout: document
title: BIT
---

## 概要

Binary indexed tree(BIT, Fenwick tree)のライブラリ．

## 使い方

- `BIT(int n)`：サイズ$n$のBITを生成する．計算量$\mathrm{O}(n)$
- `add(int i, int x)`：$i$番目(0-index)の要素に$x$を足す．計算量$\mathrm{O}(\log n)$
- `sum(int i)`：$[0, i)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `query(int l, int r)`：$[l, r)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `binary_search(int x)`：$sum(i-1)$が$x$以上となるような最小の$i$を返す．存在しない場合は$n$を返す．計算量$\mathrm{O}(\log n)$