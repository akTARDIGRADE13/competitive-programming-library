---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find/union_find.hpp
    title: lib/data_structure/union_find/union_find.hpp
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<lib/data_structure/union_find/union_find.hpp>\n\
    \n#include<iostream>\n\nint main(){\n  int n,q;\n  std::cin >> n >> q;\n  akTARDIGRADE13::Union_find\
    \ uf(n);\n  while(q--){\n    int t,u,v;\n    std::cin >> t >> u >> v;\n    if(t\
    \ == 0){\n      uf.merge(u,v);\n    }else{\n      std::cout << uf.same(u,v) <<\
    \ std::endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<lib/data_structure/union_find/union_find.hpp>\n\
    \n#include<iostream>\n\nint main(){\n  int n,q;\n  std::cin >> n >> q;\n  akTARDIGRADE13::Union_find\
    \ uf(n);\n  while(q--){\n    int t,u,v;\n    std::cin >> t >> u >> v;\n    if(t\
    \ == 0){\n      uf.merge(u,v);\n    }else{\n      std::cout << uf.same(u,v) <<\
    \ std::endl;\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - lib/data_structure/union_find/union_find.hpp
  isVerificationFile: true
  path: verify/data_structure/union_find/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-09-26 01:43:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/union_find/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/union_find/yosupo_unionfind.test.cpp
- /verify/verify/data_structure/union_find/yosupo_unionfind.test.cpp.html
title: verify/data_structure/union_find/yosupo_unionfind.test.cpp
---
