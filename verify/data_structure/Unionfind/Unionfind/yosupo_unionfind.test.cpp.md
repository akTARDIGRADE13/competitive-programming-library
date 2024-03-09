---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/Unionfind/Unionfind.hpp
    title: Unionfind
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
  bundledCode: "#line 1 \"verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"\
    lib/data_structure/Unionfind/Unionfind.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct Unionfind\
    \ {\n  public:\n    Unionfind() : n(0), c(0) {}\n    explicit Unionfind(int _n)\
    \ : n(_n), c(_n), par(_n, -1) {}\n\n    int root(int x) {\n        assert(x >=\
    \ 0 && x < n);\n        if(par[x] < 0)\n            return x;\n        return\
    \ par[x] = root(par[x]);\n    }\n\n    bool same(int x, int y) {\n        x =\
    \ root(x), y = root(y);\n        return x == y;\n    }\n\n    int count_group()\
    \ { return c; }\n\n    int size(int x) {\n        x = root(x);\n        return\
    \ -par[x];\n    }\n\n    bool merge(int x, int y) {\n        x = root(x), y =\
    \ root(y);\n        if(x == y)\n            return false;\n        --c;\n    \
    \    if(par[x] > par[y])\n            std::swap(x, y);\n        par[x] += par[y];\n\
    \        par[y] = x;\n        return true;\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> ret(n);\n        for(int i\
    \ = 0; i < n; ++i) {\n            ret[root(i)].emplace_back(i);\n        }\n \
    \       ret.erase(std::remove_if(ret.begin(), ret.end(),\n                   \
    \              [&](const std::vector<int> &e) -> bool {\n                    \
    \                 return e.empty();\n                                 }),\n  \
    \                ret.end());\n        return ret;\n    }\n\n  private:\n    int\
    \ n;\n    int c;\n    std::vector<int> par;\n};\n\n}\n#line 4 \"verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    akTARDIGRADE13::Unionfind uf(n);\n    while(q--) {\n        int t, u, v;\n\
    \        std::cin >> t >> u >> v;\n        if(t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            std::cout << uf.same(u, v) << std::endl;\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"lib/data_structure/Unionfind/Unionfind.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    akTARDIGRADE13::Unionfind\
    \ uf(n);\n    while(q--) {\n        int t, u, v;\n        std::cin >> t >> u >>\
    \ v;\n        if(t == 0) {\n            uf.merge(u, v);\n        } else {\n  \
    \          std::cout << uf.same(u, v) << std::endl;\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - lib/data_structure/Unionfind/Unionfind.hpp
  isVerificationFile: true
  path: verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 20:53:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp
- /verify/verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp.html
title: verify/data_structure/Unionfind/Unionfind/yosupo_unionfind.test.cpp
---
