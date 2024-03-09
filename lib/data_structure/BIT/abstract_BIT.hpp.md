---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/abstract_BIT/AOJ.test.cpp
    title: verify/data_structure/BIT/abstract_BIT/AOJ.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/BIT/abstract_BIT/yosupo_point_add_range_sum.test.cpp
    title: verify/data_structure/BIT/abstract_BIT/yosupo_point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/BIT/abstract_BIT.hpp\"\n\n#include <functional>\n\
    #include <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct\
    \ BIT {\n    BIT() : n(0) {}\n    explicit BIT(int _n, std::function<T(T, T)>\
    \ _fx, std::function<T(T)> _inv, T _ex)\n        : n(_n + 1), vec(_n + 1, 0),\
    \ fx(_fx), inv(_inv), ex(_ex) {}\n\n    void add(int i, T x) {\n        ++i;\n\
    \        while(i < n) {\n            vec[i] = fx(vec[i], x);\n            i +=\
    \ i & (-i);\n        }\n    }\n\n    T sum(int i) {\n        if(i == 0)\n    \
    \        return 0;\n        T ret = ex;\n        while(i > 0) {\n            ret\
    \ = fx(vec[i], ret);\n            i -= i & (-i);\n        }\n        return ret;\n\
    \    }\n\n    T query(int l, int r) { return fx(sum(r), inv(sum(l))); }\n\n  \
    \  int binary_search(T x) {\n        int ret = 0, r = 1;\n        while(r < n)\n\
    \            r = r << 1;\n        while(r > 0) {\n            if(ret + r < n &&\
    \ vec[ret + r] < x) {\n                x = fx(x, inv(vec[ret + r]));\n       \
    \         ret += r;\n            }\n            r = r >> 1;\n        }\n     \
    \   return ret;\n    }\n\n  private:\n    int n;\n    std::vector<T> vec;\n  \
    \  std::function<T(T, T)> fx;\n    std::function<T(T)> inv;\n    const T ex;\n\
    };\n\n}\n"
  code: "#pragma once\n\n#include <functional>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> struct BIT {\n    BIT() : n(0) {}\n    explicit BIT(int\
    \ _n, std::function<T(T, T)> _fx, std::function<T(T)> _inv, T _ex)\n        :\
    \ n(_n + 1), vec(_n + 1, 0), fx(_fx), inv(_inv), ex(_ex) {}\n\n    void add(int\
    \ i, T x) {\n        ++i;\n        while(i < n) {\n            vec[i] = fx(vec[i],\
    \ x);\n            i += i & (-i);\n        }\n    }\n\n    T sum(int i) {\n  \
    \      if(i == 0)\n            return 0;\n        T ret = ex;\n        while(i\
    \ > 0) {\n            ret = fx(vec[i], ret);\n            i -= i & (-i);\n   \
    \     }\n        return ret;\n    }\n\n    T query(int l, int r) { return fx(sum(r),\
    \ inv(sum(l))); }\n\n    int binary_search(T x) {\n        int ret = 0, r = 1;\n\
    \        while(r < n)\n            r = r << 1;\n        while(r > 0) {\n     \
    \       if(ret + r < n && vec[ret + r] < x) {\n                x = fx(x, inv(vec[ret\
    \ + r]));\n                ret += r;\n            }\n            r = r >> 1;\n\
    \        }\n        return ret;\n    }\n\n  private:\n    int n;\n    std::vector<T>\
    \ vec;\n    std::function<T(T, T)> fx;\n    std::function<T(T)> inv;\n    const\
    \ T ex;\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/BIT/abstract_BIT.hpp
  requiredBy: []
  timestamp: '2024-03-09 03:30:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/BIT/abstract_BIT/yosupo_point_add_range_sum.test.cpp
  - verify/data_structure/BIT/abstract_BIT/AOJ.test.cpp
documentation_of: lib/data_structure/BIT/abstract_BIT.hpp
layout: document
title: abstract_BIT
---

## 概要

抽象化されたBinary indexed tree(BIT, Fenwick tree)のライブラリ．

## 使い方

- `BIT<T>(int n, function<T(T, T)> fx, function<T(T)> inv, T ex)`：サイズ$n$のBITを生成する．計算量$\mathrm{O}(n)$
- `add(int i, T x)`：$i$番目(0-index)の要素に$x$を足す．計算量$\mathrm{O}(\log n)$
- `sum(int i)`：$[0, i)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `query(int l, int r)`：$[l, r)$の要素の総和を返す．計算量$\mathrm{O}(\log n)$
- `binary_search(T x)`：$sum(i-1)$が$x$以上となるような最小の$i$を返す．存在しない場合は$n$を返す．計算量$\mathrm{O}(\log n)$