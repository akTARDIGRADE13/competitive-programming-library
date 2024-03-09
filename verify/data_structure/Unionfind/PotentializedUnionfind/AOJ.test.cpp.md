---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/Unionfind/PotentializedUnionfind.hpp
    title: PotentializedUnionfind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#line 2 \"lib/data_structure/Unionfind/PotentializedUnionfind.hpp\"\n\n#include\
    \ <algorithm>\n#include <functional>\n#include <vector>\n\nnamespace akTARDIGRADE13\
    \ {\n\ntemplate <typename T> struct PotentializedUnionfind {\n  public:\n    PotentializedUnionfind()\
    \ : n(0), c(0) {}\n    explicit PotentializedUnionfind(int n, std::function<T(T,\
    \ T)> _fx,\n                                    std::function<T(T)> _inv, T _ex)\n\
    \        : n(n), c(n), fx(_fx), inv(_inv) {\n        parents.assign(n, -1);\n\
    \        potential.assign(n, _ex);\n    }\n\n    bool merge(int x, int y, T w)\
    \ {\n        w += get_potential(x);\n        w -= get_potential(y);\n        x\
    \ = root(x), y = root(y);\n\n        if(x == y) {\n            if(diff(x, y) ==\
    \ w) {\n                return true;\n            } else {\n                return\
    \ false;\n            }\n        }\n        --c;\n\n        if(parents[x] > parents[y])\n\
    \            std::swap(x, y), w = inv(w);\n        parents[x] += parents[y];\n\
    \        parents[y] = x;\n        potential[y] = w;\n        return true;\n  \
    \  }\n\n    bool same(int x, int y) { return root(x) == root(y); }\n\n    int\
    \ root(int x) {\n        if(parents[x] < 0) {\n            return x;\n       \
    \ } else {\n            int r = root(parents[x]);\n            potential[x] =\
    \ fx(potential[x], potential[parents[x]]);\n            return parents[x] = r;\n\
    \        }\n    }\n\n    int count_group() { return c; }\n\n    int size(int x)\
    \ { return -parents[root(x)]; }\n\n    T get_potential(int x) {\n        root(x);\n\
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
    \n}\n#line 4 \"verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    auto fx = [](long long x, long long y)->long long{return x+y;};\n    auto\
    \ inv = [](long long x)->long long{return -x;};\n    auto ex = 0;\n    akTARDIGRADE13::PotentializedUnionfind<long\
    \ long> uf(n, fx, inv, ex);\n    while(q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if(!t){\n            int x, y, z;\n            std::cin >> x\
    \ >> y >> z;\n            uf.merge(x, y, z);\n        }else{\n            int\
    \ x, y;\n            std::cin >> x >> y;\n            if(uf.same(x, y)){\n   \
    \             std::cout << uf.diff(x, y) << std::endl;\n            }else{\n \
    \               std::cout << '?' << std::endl;\n            }\n        }\n   \
    \ }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"lib/data_structure/Unionfind/PotentializedUnionfind.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    auto\
    \ fx = [](long long x, long long y)->long long{return x+y;};\n    auto inv = [](long\
    \ long x)->long long{return -x;};\n    auto ex = 0;\n    akTARDIGRADE13::PotentializedUnionfind<long\
    \ long> uf(n, fx, inv, ex);\n    while(q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if(!t){\n            int x, y, z;\n            std::cin >> x\
    \ >> y >> z;\n            uf.merge(x, y, z);\n        }else{\n            int\
    \ x, y;\n            std::cin >> x >> y;\n            if(uf.same(x, y)){\n   \
    \             std::cout << uf.diff(x, y) << std::endl;\n            }else{\n \
    \               std::cout << '?' << std::endl;\n            }\n        }\n   \
    \ }\n    return 0;\n}"
  dependsOn:
  - lib/data_structure/Unionfind/PotentializedUnionfind.hpp
  isVerificationFile: true
  path: verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 04:53:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
- /verify/verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp.html
title: verify/data_structure/Unionfind/PotentializedUnionfind/AOJ.test.cpp
---
