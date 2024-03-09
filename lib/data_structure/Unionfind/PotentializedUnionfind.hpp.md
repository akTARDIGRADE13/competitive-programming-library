---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
    title: verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/Unionfind/PotentializedUnionfind.hpp\"\
    \n\n#include <algorithm>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ akTARDIGRADE13 {\n\ntemplate <typename T> struct PotentializedUnionfind {\n\
    \  public:\n    PotentializedUnionfind() : n(0), c(0) {}\n    explicit PotentializedUnionfind(int\
    \ n, std::function<T(T, T)> _fx,\n                                    std::function<T(T)>\
    \ _inv, T _ex)\n        : n(n), c(n), fx(_fx), inv(_inv) {\n        parents.assign(n,\
    \ -1);\n        potential.assign(n, _ex);\n    }\n\n    bool merge(int x, int\
    \ y, T w) {\n        w += get_potential(x);\n        w -= get_potential(y);\n\
    \        x = root(x), y = root(y);\n\n        if(x == y) {\n            if(diff(x,\
    \ y) == w) {\n                return true;\n            } else {\n           \
    \     return false;\n            }\n        }\n        --c;\n\n        if(parents[x]\
    \ > parents[y])\n            std::swap(x, y), w = inv(w);\n        parents[x]\
    \ += parents[y];\n        parents[y] = x;\n        potential[y] = w;\n       \
    \ return true;\n    }\n\n    bool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n    int root(int x) {\n        if(parents[x] < 0) {\n            return\
    \ x;\n        } else {\n            int r = root(parents[x]);\n            potential[x]\
    \ = fx(potential[x], potential[parents[x]]);\n            return parents[x] =\
    \ r;\n        }\n    }\n\n    int count_group() { return c; }\n\n    int size(int\
    \ x) { return -parents[root(x)]; }\n\n    T get_potential(int x) {\n        root(x);\n\
    \        return potential[x];\n    }\n\n    T diff(int x, int y) { return fx(get_potential(y),\
    \ inv(get_potential(x))); }\n\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> ret(n);\n        std::vector<int> cnt(n),\
    \ roots(n);\n        for(int i = 0; i < n; ++i) {\n            roots[i] = root(i);\n\
    \            ++cnt[roots[i]];\n        }\n        for(int i = 0; i < n; ++i)\n\
    \            ret[i].reserve(cnt[i]);\n        for(int i = 0; i < n; ++i)\n   \
    \         ret[roots[i]].push_back(i);\n        ret.erase(\n            remove_if(ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int> &i) { return i.empty();\
    \ }),\n            ret.end());\n        return ret;\n    }\n\n  private:\n   \
    \ const int n;\n    int c;\n    std::vector<int> parents;\n    std::vector<T>\
    \ potential;\n    std::function<T(T, T)> fx;\n    std::function<T(T)> inv;\n};\n\
    \n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <functional>\n#include <vector>\n\
    \nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct PotentializedUnionfind\
    \ {\n  public:\n    PotentializedUnionfind() : n(0), c(0) {}\n    explicit PotentializedUnionfind(int\
    \ n, std::function<T(T, T)> _fx,\n                                    std::function<T(T)>\
    \ _inv, T _ex)\n        : n(n), c(n), fx(_fx), inv(_inv) {\n        parents.assign(n,\
    \ -1);\n        potential.assign(n, _ex);\n    }\n\n    bool merge(int x, int\
    \ y, T w) {\n        w += get_potential(x);\n        w -= get_potential(y);\n\
    \        x = root(x), y = root(y);\n\n        if(x == y) {\n            if(diff(x,\
    \ y) == w) {\n                return true;\n            } else {\n           \
    \     return false;\n            }\n        }\n        --c;\n\n        if(parents[x]\
    \ > parents[y])\n            std::swap(x, y), w = inv(w);\n        parents[x]\
    \ += parents[y];\n        parents[y] = x;\n        potential[y] = w;\n       \
    \ return true;\n    }\n\n    bool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n    int root(int x) {\n        if(parents[x] < 0) {\n            return\
    \ x;\n        } else {\n            int r = root(parents[x]);\n            potential[x]\
    \ = fx(potential[x], potential[parents[x]]);\n            return parents[x] =\
    \ r;\n        }\n    }\n\n    int count_group() { return c; }\n\n    int size(int\
    \ x) { return -parents[root(x)]; }\n\n    T get_potential(int x) {\n        root(x);\n\
    \        return potential[x];\n    }\n\n    T diff(int x, int y) { return fx(get_potential(y),\
    \ inv(get_potential(x))); }\n\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> ret(n);\n        std::vector<int> cnt(n),\
    \ roots(n);\n        for(int i = 0; i < n; ++i) {\n            roots[i] = root(i);\n\
    \            ++cnt[roots[i]];\n        }\n        for(int i = 0; i < n; ++i)\n\
    \            ret[i].reserve(cnt[i]);\n        for(int i = 0; i < n; ++i)\n   \
    \         ret[roots[i]].push_back(i);\n        ret.erase(\n            remove_if(ret.begin(),\
    \ ret.end(),\n                      [&](const std::vector<int> &i) { return i.empty();\
    \ }),\n            ret.end());\n        return ret;\n    }\n\n  private:\n   \
    \ const int n;\n    int c;\n    std::vector<int> parents;\n    std::vector<T>\
    \ potential;\n    std::function<T(T, T)> fx;\n    std::function<T(T)> inv;\n};\n\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/Unionfind/PotentializedUnionfind.hpp
  requiredBy: []
  timestamp: '2024-03-09 04:53:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
documentation_of: lib/data_structure/Unionfind/PotentializedUnionfind.hpp
layout: document
title: PotentializedUnionfind
---

## 概要

ポテンシャル付き（重み付き）Unionfind のライブラリ．

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

## 使い方

- `Unionfind<T>(int n, function<T(T, T)> fx, function<T(T)> inv, T ex)`：サイズ$n$のUnionfindを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y, T z)`：$x$に対する$y$のポテンシャルが$+z$となるようにマージする
．返り値はマージに成功したらtrue，失敗したらfalseを返す．矛盾する場合もfalseを返す．計算量$\mathrm{O}(\log n)$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\log n)$
- `size(int x)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\log n)$
- `diff(int x, int y)`：$x$に対する$y$のポテンシャルを返す．$x$と$y$が連結していない場合は無意味な値が返ってくるので注意．計算量$\mathrm{O}(\log n)$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$