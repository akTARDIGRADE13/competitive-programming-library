---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/union_find/yosupo_unionfind.test.cpp
    title: verify/data_structure/union_find/yosupo_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find/union_find.hpp\"\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct Union_find\
    \ {\n public:\n  Union_find() : n(0), c(0) {}\n  explicit Union_find(int _n) :\
    \ n(_n), c(_n), par(_n, -1) {}\n\n  int root(int x) {\n    if (par[x] < 0) return\
    \ x;\n    return par[x] = root(par[x]);\n  }\n\n  bool same(int x, int y) {\n\
    \    x = root(x), y = root(y);\n    return x == y;\n  }\n\n  int count_group()\
    \ { return c; }\n\n  int size(int x) {\n    x = root(x);\n    return -par[x];\n\
    \  }\n\n  bool merge(int x, int y) {\n    x = root(x), y = root(y);\n    if (x\
    \ == y) return false;\n    --c;\n    if (par[x] > par[y]) std::swap(x, y);\n \
    \   par[x] += par[y];\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<std::vector<int>>\
    \ groups() {\n    std::vector<std::vector<int>> ret(n);\n    for (int i = 0; i\
    \ < n; ++i) {\n      ret[root(i)].emplace_back(i);\n    }\n    ret.erase(std::remove_if(\n\
    \                  ret.begin(), ret.end(),\n                  [&](const std::vector<int>&\
    \ e) -> bool { return e.empty(); }),\n              ret.end());\n    return ret;\n\
    \  }\n\n private:\n  int n;\n  int c;\n  std::vector<int> par;\n};\n\n}  // namespace\
    \ akTARDIGRADE13\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\nstruct Union_find {\n public:\n  Union_find() : n(0), c(0) {}\n  explicit\
    \ Union_find(int _n) : n(_n), c(_n), par(_n, -1) {}\n\n  int root(int x) {\n \
    \   if (par[x] < 0) return x;\n    return par[x] = root(par[x]);\n  }\n\n  bool\
    \ same(int x, int y) {\n    x = root(x), y = root(y);\n    return x == y;\n  }\n\
    \n  int count_group() { return c; }\n\n  int size(int x) {\n    x = root(x);\n\
    \    return -par[x];\n  }\n\n  bool merge(int x, int y) {\n    x = root(x), y\
    \ = root(y);\n    if (x == y) return false;\n    --c;\n    if (par[x] > par[y])\
    \ std::swap(x, y);\n    par[x] += par[y];\n    par[y] = x;\n    return true;\n\
    \  }\n\n  std::vector<std::vector<int>> groups() {\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; ++i) {\n      ret[root(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(\n                  ret.begin(), ret.end(),\n\
    \                  [&](const std::vector<int>& e) -> bool { return e.empty();\
    \ }),\n              ret.end());\n    return ret;\n  }\n\n private:\n  int n;\n\
    \  int c;\n  std::vector<int> par;\n};\n\n}  // namespace akTARDIGRADE13"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/union_find/union_find.hpp
  requiredBy: []
  timestamp: '2023-09-26 17:36:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/union_find/yosupo_unionfind.test.cpp
documentation_of: lib/data_structure/union_find/union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/union_find/union_find.hpp
- /library/lib/data_structure/union_find/union_find.hpp.html
title: lib/data_structure/union_find/union_find.hpp
---
