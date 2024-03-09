---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
    title: verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/Unionfind/UndoUnionfind.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <stack>\n#include <vector>\n\nnamespace\
    \ akTARDIGRADE13 {\n\nstruct UndoUnionfind {\n  public:\n    UndoUnionfind() :\
    \ n(0), c(0) {}\n    explicit UndoUnionfind(int _n) : n(_n), c(_n), par(_n, -1)\
    \ {}\n\n    int root(int x) {\n        assert(x >= 0 && x < n);\n        if(par[x]\
    \ < 0)\n            return x;\n        return root(par[x]);\n    }\n\n    bool\
    \ same(int x, int y) {\n        x = root(x), y = root(y);\n        return x ==\
    \ y;\n    }\n\n    int count_group() { return c; }\n\n    int size(int x) {\n\
    \        x = root(x);\n        return -par[x];\n    }\n\n    bool merge(int x,\
    \ int y) {\n        x = root(x), y = root(y);\n        rec.emplace(x, par[x]);\n\
    \        rec.emplace(y, par[y]);\n        rec2.emplace(c);\n        if(x == y)\n\
    \            return false;\n        --c;\n        if(par[x] > par[y])\n      \
    \      std::swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n    \
    \    return true;\n    }\n\n    void undo() {\n        assert(!rec2.empty());\n\
    \        par[rec.top().first] = rec.top().second;\n        rec.pop();\n      \
    \  par[rec.top().first] = rec.top().second;\n        rec.pop();\n        c = par[rec2.top()];\n\
    \        rec2.pop();\n    }\n\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> ret(n);\n        for(int i = 0; i < n;\
    \ ++i) {\n            ret[root(i)].emplace_back(i);\n        }\n        ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(),\n                                 [&](const std::vector<int> &e)\
    \ -> bool {\n                                     return e.empty();\n        \
    \                         }),\n                  ret.end());\n        return ret;\n\
    \    }\n\n  private:\n    int n;\n    int c;\n    std::vector<int> par;\n    std::stack<std::pair<int,\
    \ int>> rec;\n    std::stack<int> rec2;\n};\n\n} \n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n\
    #include <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct UndoUnionfind {\n  public:\n\
    \    UndoUnionfind() : n(0), c(0) {}\n    explicit UndoUnionfind(int _n) : n(_n),\
    \ c(_n), par(_n, -1) {}\n\n    int root(int x) {\n        assert(x >= 0 && x <\
    \ n);\n        if(par[x] < 0)\n            return x;\n        return root(par[x]);\n\
    \    }\n\n    bool same(int x, int y) {\n        x = root(x), y = root(y);\n \
    \       return x == y;\n    }\n\n    int count_group() { return c; }\n\n    int\
    \ size(int x) {\n        x = root(x);\n        return -par[x];\n    }\n\n    bool\
    \ merge(int x, int y) {\n        x = root(x), y = root(y);\n        rec.emplace(x,\
    \ par[x]);\n        rec.emplace(y, par[y]);\n        rec2.emplace(c);\n      \
    \  if(x == y)\n            return false;\n        --c;\n        if(par[x] > par[y])\n\
    \            std::swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n\
    \        return true;\n    }\n\n    void undo() {\n        assert(!rec2.empty());\n\
    \        par[rec.top().first] = rec.top().second;\n        rec.pop();\n      \
    \  par[rec.top().first] = rec.top().second;\n        rec.pop();\n        c = par[rec2.top()];\n\
    \        rec2.pop();\n    }\n\n    std::vector<std::vector<int>> groups() {\n\
    \        std::vector<std::vector<int>> ret(n);\n        for(int i = 0; i < n;\
    \ ++i) {\n            ret[root(i)].emplace_back(i);\n        }\n        ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(),\n                                 [&](const std::vector<int> &e)\
    \ -> bool {\n                                     return e.empty();\n        \
    \                         }),\n                  ret.end());\n        return ret;\n\
    \    }\n\n  private:\n    int n;\n    int c;\n    std::vector<int> par;\n    std::stack<std::pair<int,\
    \ int>> rec;\n    std::stack<int> rec2;\n};\n\n} "
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/Unionfind/UndoUnionfind.hpp
  requiredBy: []
  timestamp: '2024-03-09 21:04:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
documentation_of: lib/data_structure/Unionfind/UndoUnionfind.hpp
layout: document
title: UndoUnionfind
---

## 概要

Undo付きUnionfindのライブラリ．

[Union-Find Tree を理解する！素集合系を扱うデータ構造](https://algo-logic.info/union-find-tree/)

このライブラリでは，上記ページにおける「union by size」の実装方針を採用しています．

## 使い方

- `UndoUnionfind(int n)`：サイズ$n$のUnionfindを生成する．計算量$\mathrm{O}(n)$
- `merge(int x, int y)`：「$x$の属する集合」と「$y$の属する集合」をマージする．返り値はマージに成功したらtrue，失敗したらfalseを返す．計算量$\mathrm{O}(\log n)$
- `root(int k)`：$k$の根を返す．計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：$x$と$y$が同じ集合に所属しているかを返す．計算量$\mathrm{O}(\log n)$
- `size(int x)`：$x$を含む集合のサイズを返す．計算量$\mathrm{O}(\log n)$
- `count_groups()`：存在する集合の個数を返す．計算量$\mathrm{O}(1)$
- `undo()`：1個前のmergeを無かったことにする．計算量$\mathrm{O}(1)$
- `groups()`：存在する集合を全列挙して返す．計算量$\mathrm{O}(n)$