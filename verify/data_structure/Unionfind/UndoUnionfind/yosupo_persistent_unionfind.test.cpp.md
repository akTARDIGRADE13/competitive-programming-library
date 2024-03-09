---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/Unionfind/UndoUnionfind.hpp
    title: UndoUnionfind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n\
    #line 2 \"lib/data_structure/Unionfind/UndoUnionfind.hpp\"\n\n#include <algorithm>\n\
    #include <stack>\n#include <vector>\n\nnamespace akTARDIGRADE13 {\n\nstruct UndoUnionfind\
    \ {\n  public:\n    UndoUnionfind() : n(0), c(0) {}\n    explicit UndoUnionfind(int\
    \ _n) : n(_n), c(_n), par(_n, -1) {}\n\n    int root(int x) {\n        if(par[x]\
    \ < 0)\n            return x;\n        return root(par[x]);\n    }\n\n    bool\
    \ same(int x, int y) {\n        x = root(x), y = root(y);\n        return x ==\
    \ y;\n    }\n\n    int count_group() { return c; }\n\n    int size(int x) {\n\
    \        x = root(x);\n        return -par[x];\n    }\n\n    bool merge(int x,\
    \ int y) {\n        x = root(x), y = root(y);\n        rec.emplace(x, par[x]);\n\
    \        rec.emplace(y, par[y]);\n        rec2.emplace(c);\n        if(x == y)\n\
    \            return false;\n        --c;\n        if(par[x] > par[y])\n      \
    \      std::swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n    \
    \    return true;\n    }\n\n    void undo() {\n        par[rec.top().first] =\
    \ rec.top().second;\n        rec.pop();\n        par[rec.top().first] = rec.top().second;\n\
    \        rec.pop();\n        c = par[rec2.top()];\n        rec2.pop();\n    }\n\
    \n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ ret(n);\n        for(int i = 0; i < n; ++i) {\n            ret[root(i)].emplace_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(),\n       \
    \                          [&](const std::vector<int> &e) -> bool {\n        \
    \                             return e.empty();\n                            \
    \     }),\n                  ret.end());\n        return ret;\n    }\n\n  private:\n\
    \    int n;\n    int c;\n    std::vector<int> par;\n    std::stack<std::pair<int,\
    \ int>> rec;\n    std::stack<int> rec2;\n};\n\n} // namespace akTARDIGRADE13\n\
    #line 4 \"verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp\"\
    \n\n#include <array>\n#include <iostream>\n#line 8 \"verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp\"\
    \n\nusing A = std::array<int, 4>;\n\nint main() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    akTARDIGRADE13::UndoUnionfind uf(n);\n    std::vector<std::vector<A>>\
    \ query(q);\n    for(int i = 1; i <= q; ++i) {\n        int t, k, u, v;\n    \
    \    std::cin >> t >> k >> u >> v;\n        ++k;\n        query[k].push_back(A{t,\
    \ i, u, v});\n    }\n    std::vector<int> ans(q + 1, -1);\n    auto dfs = [&](auto\
    \ dfs, const A &inp) -> void {\n        if(inp[0] <= 0) {\n            if(inp[0]\
    \ == 0)\n                uf.merge(inp[2], inp[3]);\n            for(auto &i :\
    \ query[inp[1]])\n                dfs(dfs, i);\n            if(inp[0] == 0)\n\
    \                uf.undo();\n        } else {\n            ans[inp[1]] = uf.same(inp[2],\
    \ inp[3]);\n        }\n    };\n    A sta = {-1, 0, -1, 0};\n    dfs(dfs, sta);\n\
    \    for(auto i : ans)\n        if(i != -1)\n            std::cout << i << std::endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"lib/data_structure/Unionfind/UndoUnionfind.hpp\"\n\n#include <array>\n\
    #include <iostream>\n#include <vector>\n\nusing A = std::array<int, 4>;\n\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    akTARDIGRADE13::UndoUnionfind\
    \ uf(n);\n    std::vector<std::vector<A>> query(q);\n    for(int i = 1; i <= q;\
    \ ++i) {\n        int t, k, u, v;\n        std::cin >> t >> k >> u >> v;\n   \
    \     ++k;\n        query[k].push_back(A{t, i, u, v});\n    }\n    std::vector<int>\
    \ ans(q + 1, -1);\n    auto dfs = [&](auto dfs, const A &inp) -> void {\n    \
    \    if(inp[0] <= 0) {\n            if(inp[0] == 0)\n                uf.merge(inp[2],\
    \ inp[3]);\n            for(auto &i : query[inp[1]])\n                dfs(dfs,\
    \ i);\n            if(inp[0] == 0)\n                uf.undo();\n        } else\
    \ {\n            ans[inp[1]] = uf.same(inp[2], inp[3]);\n        }\n    };\n \
    \   A sta = {-1, 0, -1, 0};\n    dfs(dfs, sta);\n    for(auto i : ans)\n     \
    \   if(i != -1)\n            std::cout << i << std::endl;\n    return 0;\n}"
  dependsOn:
  - lib/data_structure/Unionfind/UndoUnionfind.hpp
  isVerificationFile: true
  path: verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 19:53:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
- /verify/verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp.html
title: verify/data_structure/Unionfind/UndoUnionfind/yosupo_persistent_unionfind.test.cpp
---
