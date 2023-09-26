---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find/union_find.hpp
    title: union_find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/data_structure/union_find/yosupo_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"\
    lib/data_structure/union_find/union_find.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct Union_find {\n public:\n  Union_find()\
    \ : n(0), c(0) {}\n  explicit Union_find(int _n) : n(_n), c(_n), par(_n, -1) {}\n\
    \n  int root(int x) {\n    if (par[x] < 0) return x;\n    return par[x] = root(par[x]);\n\
    \  }\n\n  bool same(int x, int y) {\n    x = root(x), y = root(y);\n    return\
    \ x == y;\n  }\n\n  int count_group() { return c; }\n\n  int size(int x) {\n \
    \   x = root(x);\n    return -par[x];\n  }\n\n  bool merge(int x, int y) {\n \
    \   x = root(x), y = root(y);\n    if (x == y) return false;\n    --c;\n    if\
    \ (par[x] > par[y]) std::swap(x, y);\n    par[x] += par[y];\n    par[y] = x;\n\
    \    return true;\n  }\n\n  std::vector<std::vector<int>> groups() {\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; ++i) {\n      ret[root(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(\n                  ret.begin(), ret.end(),\n\
    \                  [&](const std::vector<int>& e) -> bool { return e.empty();\
    \ }),\n              ret.end());\n    return ret;\n  }\n\n private:\n  int n;\n\
    \  int c;\n  std::vector<int> par;\n};\n\n}  // namespace akTARDIGRADE13\n#line\
    \ 4 \"verify/data_structure/union_find/yosupo_unionfind.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main(){\n  int n,q;\n  std::cin >> n >> q;\n  akTARDIGRADE13::Union_find\
    \ uf(n);\n  while(q--){\n    int t,u,v;\n    std::cin >> t >> u >> v;\n    if(t\
    \ == 0){\n      uf.merge(u,v);\n    }else{\n      std::cout << uf.same(u,v) <<\
    \ std::endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"lib/data_structure/union_find/union_find.hpp\"\n\n#include <iostream>\n\n\
    int main(){\n  int n,q;\n  std::cin >> n >> q;\n  akTARDIGRADE13::Union_find uf(n);\n\
    \  while(q--){\n    int t,u,v;\n    std::cin >> t >> u >> v;\n    if(t == 0){\n\
    \      uf.merge(u,v);\n    }else{\n      std::cout << uf.same(u,v) << std::endl;\n\
    \    }\n  }\n  return 0;\n}"
  dependsOn:
  - lib/data_structure/union_find/union_find.hpp
  isVerificationFile: true
  path: verify/data_structure/union_find/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-09-26 17:43:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/union_find/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/union_find/yosupo_unionfind.test.cpp
- /verify/verify/data_structure/union_find/yosupo_unionfind.test.cpp.html
title: verify/data_structure/union_find/yosupo_unionfind.test.cpp
---
