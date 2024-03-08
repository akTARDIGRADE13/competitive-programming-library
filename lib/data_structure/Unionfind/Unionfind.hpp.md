---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Unionfind/yosupo_unionfind.test.cpp
    title: verify/data_structure/Unionfind/yosupo_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/Unionfind/Unionfind.hpp\"\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct Unionfind\
    \ {\n  public:\n    Unionfind() : n(0), c(0) {}\n    explicit Unionfind(int _n)\
    \ : n(_n), c(_n), par(_n, -1) {}\n\n    int root(int x) {\n        if(par[x] <\
    \ 0)\n            return x;\n        return par[x] = root(par[x]);\n    }\n\n\
    \    bool same(int x, int y) {\n        x = root(x), y = root(y);\n        return\
    \ x == y;\n    }\n\n    int count_group() { return c; }\n\n    int size(int x)\
    \ {\n        x = root(x);\n        return -par[x];\n    }\n\n    bool merge(int\
    \ x, int y) {\n        x = root(x), y = root(y);\n        if(x == y)\n       \
    \     return false;\n        --c;\n        if(par[x] > par[y])\n            std::swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ ret(n);\n        for(int i = 0; i < n; ++i) {\n            ret[root(i)].emplace_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(),\n       \
    \                          [&](const std::vector<int> &e) -> bool {\n        \
    \                             return e.empty();\n                            \
    \     }),\n                  ret.end());\n        return ret;\n    }\n\n  private:\n\
    \    int n;\n    int c;\n    std::vector<int> par;\n};\n\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\nstruct Unionfind {\n  public:\n    Unionfind() : n(0), c(0) {}\n    explicit\
    \ Unionfind(int _n) : n(_n), c(_n), par(_n, -1) {}\n\n    int root(int x) {\n\
    \        if(par[x] < 0)\n            return x;\n        return par[x] = root(par[x]);\n\
    \    }\n\n    bool same(int x, int y) {\n        x = root(x), y = root(y);\n \
    \       return x == y;\n    }\n\n    int count_group() { return c; }\n\n    int\
    \ size(int x) {\n        x = root(x);\n        return -par[x];\n    }\n\n    bool\
    \ merge(int x, int y) {\n        x = root(x), y = root(y);\n        if(x == y)\n\
    \            return false;\n        --c;\n        if(par[x] > par[y])\n      \
    \      std::swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n    \
    \    return true;\n    }\n\n    std::vector<std::vector<int>> groups() {\n   \
    \     std::vector<std::vector<int>> ret(n);\n        for(int i = 0; i < n; ++i)\
    \ {\n            ret[root(i)].emplace_back(i);\n        }\n        ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(),\n                                 [&](const std::vector<int> &e)\
    \ -> bool {\n                                     return e.empty();\n        \
    \                         }),\n                  ret.end());\n        return ret;\n\
    \    }\n\n  private:\n    int n;\n    int c;\n    std::vector<int> par;\n};\n\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/Unionfind/Unionfind.hpp
  requiredBy: []
  timestamp: '2024-03-08 18:21:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Unionfind/yosupo_unionfind.test.cpp
documentation_of: lib/data_structure/Unionfind/Unionfind.hpp
layout: document
title: Unionfind
---

## 概要

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

また，以下では，$\alpha(n)$はアッカーマン関数$A(n,n)$の逆関数とします．

## 使い方

- `Union_find(int n)`：サイズ$n$のunion_findを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y)`：「$x$の属する集合」と「$y$の属する集合」をマージする．返り値はマージに成功したらtrue，失敗したらfalseを返す．計算量$\mathrm{O}(\alpha(n))$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\alpha(n))$
- `size(int k)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\alpha(n))$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$