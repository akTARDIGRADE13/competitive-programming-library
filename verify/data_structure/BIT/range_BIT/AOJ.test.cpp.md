---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/BIT/range_BIT.hpp
    title: range_BIT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"verify/data_structure/BIT/range_BIT/AOJ.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#line 2 \"lib/data_structure/BIT/range_BIT.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace akTARDIGRADE13 {\n\ntemplate <typename T> struct range_BIT\
    \ {\n    range_BIT() : n(0) {}\n    explicit range_BIT(int _n) : n(_n + 2), vec(2,\
    \ std::vector<T>(_n + 2, 0)) {}\n\n    void add(int l, int r, T x) {\n       \
    \ assert(l >= 0 && l < n - 1 && l < r && r < n);\n        ++l, ++r;\n        for(int\
    \ i = l; i < n; i += i & (-i)) {\n            vec[0][i] -= x * (l - 1);\n    \
    \        vec[1][i] += x;\n        }\n        for(int i = r; i < n; i += i & (-i))\
    \ {\n            vec[0][i] += x * (r - 1);\n            vec[1][i] -= x;\n    \
    \    }\n    }\n\n    T sum(int i) {\n        assert(i >= 0 && i < n);\n      \
    \  T ret(0);\n        int k = i;\n        while(i > 0) {\n            ret += vec[1][i]\
    \ * k + vec[0][i];\n            i -= i & (-i);\n        }\n        return ret;\n\
    \    }\n\n    T query(int l, int r) {\n        assert(l <= r);\n        return\
    \ sum(r) - sum(l);\n    }\n\n  private:\n    int n;\n    std::vector<std::vector<T>>\
    \ vec;\n};\n\n}\n#line 4 \"verify/data_structure/BIT/range_BIT/AOJ.test.cpp\"\n\
    \n#include <iostream>\n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    akTARDIGRADE13::range_BIT<long long> bt(n);\n    while(q--) {\n        int\
    \ t;\n        std::cin >> t;\n        if(!t) {\n            int l, r, x;\n   \
    \         std::cin >> l >> r >> x;\n            bt.add(l-1, r, x);\n        }\
    \ else {\n            int l, r;\n            std::cin >> l >> r;\n           \
    \ std::cout << bt.query(l-1, r) << std::endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"lib/data_structure/BIT/range_BIT.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    akTARDIGRADE13::range_BIT<long\
    \ long> bt(n);\n    while(q--) {\n        int t;\n        std::cin >> t;\n   \
    \     if(!t) {\n            int l, r, x;\n            std::cin >> l >> r >> x;\n\
    \            bt.add(l-1, r, x);\n        } else {\n            int l, r;\n   \
    \         std::cin >> l >> r;\n            std::cout << bt.query(l-1, r) << std::endl;\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - lib/data_structure/BIT/range_BIT.hpp
  isVerificationFile: true
  path: verify/data_structure/BIT/range_BIT/AOJ.test.cpp
  requiredBy: []
  timestamp: '2024-03-09 21:05:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/BIT/range_BIT/AOJ.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/BIT/range_BIT/AOJ.test.cpp
- /verify/verify/data_structure/BIT/range_BIT/AOJ.test.cpp.html
title: verify/data_structure/BIT/range_BIT/AOJ.test.cpp
---
